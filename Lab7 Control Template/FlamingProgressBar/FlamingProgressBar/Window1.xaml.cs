using System;
using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace FlamingProgressBar
{
    /// <summary>
    /// Flaming progress bar window
    /// </summary>
    public partial class Window1 : Window
    {
        const int       FireWidth       = 100;                  // Image resolution
        const int       FireHeight      = 100;
        const int       FireCutoff      = 2;                    // Cut-off ugliness at the bottom
        const int       FireBottom      = 2;                    // Initialization area is 2 lines
        const double    FireExtraHotness= 2.5;                  // Increase to burn hotter
        const double    FireSmoothness  = 1.0 / FireHeight;     // 0 = perfectly smooth
        const double    FireDecay       = 2.2 / FireHeight;     // Increase for shorter fire

        Random                  _rnd = new Random();
        WriteableBitmap         _wbm;                           // The output Image
        Int32Rect               _wbmRect;
        byte[,]                 _pixelsBytes;                   // The bytes for the image
        double[,]               _pixels;                        // The working area

        public Window1()
        {
            InitializeComponent();

            // Create a fiery color palette
            // - This one fades from black -> red -> yellow -> white
            Color[] colors = new Color[256];
            SpreadColors(colors, Color.FromRgb(  0,  0,  0),   0, Color.FromRgb(255,  0,  0), 128);
            SpreadColors(colors, Color.FromRgb(255,  0,  0), 128, Color.FromRgb(255,255,  0), 230);
            SpreadColors(colors, Color.FromRgb(255,255,  0), 230, Color.FromRgb(255,255,255), 255);

            // Create a bitmap and assign it to the image
            // - The cutoff area is the number of lines where the algorithm is
            //   unstable and ugly.  So don't make room for that in the output
            //   image.  Just in the working area.
            _wbm = new WriteableBitmap(FireWidth, FireHeight - FireCutoff, 96, 96, PixelFormats.Indexed8, new BitmapPalette(colors));
            img.ImageSource = _wbm;
            _wbmRect = new Int32Rect(0, 0, FireWidth, FireHeight - FireCutoff);

            // Pixels is what we write to.  pixelsBytes is the raw data for the image.
            _pixels = new double[FireHeight + FireBottom, FireWidth];
            _pixelsBytes = new byte[FireHeight + FireBottom, FireWidth];

            // Kick-off a timer to draw the fire at about 30fps
            var timer = new System.Windows.Threading.DispatcherTimer();
            timer.Tick += UpdateFire;
            timer.Interval = TimeSpan.FromSeconds(1.0/30);
            timer.IsEnabled = true;
        }

        /// <summary>
        /// Draw some fire
        /// </summary>
        private void UpdateFire(object sender, EventArgs e)
        {
            // First, we initialize the bottom of the fire.
            // - Varying this results in different types of fires
            for (int y = FireHeight; y < FireHeight + FireBottom; y++)
            {
                for (int x = 0; x < FireWidth; x++)
                {
                    // A random number between 0 and 1
                    double f = _rnd.NextDouble();
                    // Square the heat for plumes of flame
                    double heat = f * f * FireExtraHotness; 
                    // Now mix that in by about 25%
                    _pixels[y, x] = _pixels[y, x]*0.75 + heat*0.25;
                }
            }

            // Now move the fire up the screen
            for (int y = 0; y < FireHeight + FireBottom - 2; y++)
            {
                for (int x = 1; x < FireWidth - 1; x++)
                {
                    // This averages the current pixel with the pixels
                    // below it and around it, so the fire moves up.
                    // - FireDecay must be >0 so the fire slowly vanishes
                    // - FireSmoothness adds some randomness into the fire
                    double newPixel =
                        (
                            _pixels[y, x] +
                            _pixels[y + 1, x + 1] +
                            _pixels[y + 1, x + 0] * 2 +
                            _pixels[y + 1, x - 1] +
                            _pixels[y + 2, x + 1] +
                            _pixels[y + 2, x + 0] * 2 +
                            _pixels[y + 2, x - 1]
                        ) / 9
                        + _rnd.NextDouble(-FireSmoothness, FireSmoothness)
                        - _rnd.NextDouble(0, FireDecay);

                    // Now copy the fire to our buffer
                    _pixels[y, x] = newPixel;
                }
            }

            // The buffer must be converted from floats(0..1) to bytes(0..255).
            // - Must clamp the values within 0.255
            for (int y = 0; y < FireHeight - FireCutoff; y++)
            {
                for (int x = 1; x < FireWidth - 1; x++)
                {
                    _pixelsBytes[y, x] = (byte)
                        Math.Min(Math.Max(_pixels[y, x]*255, 0), 255);
                }
            }

            // Now copy the bytes to the WPF image
            _wbm.WritePixels(_wbmRect, _pixelsBytes, FireWidth, 0);
        }

        /// <summary>
        /// Helper method to generate a color palette.  This will cross-fade
        /// between two colors.
        /// </summary>
        private static void SpreadColors(Color[] colors, Color start, int startIndex, Color finish, int finishIndex)
        {
            for (int c = startIndex; c <= finishIndex; c++)
            {
                float factor = 1.0f * (c - startIndex) / (finishIndex - startIndex);
                Color temp = Color.FromRgb(
                    (byte)(start.R * (1 - factor) + finish.R * factor),
                    (byte)(start.G * (1 - factor) + finish.G * factor),
                    (byte)(start.B * (1 - factor) + finish.B * factor));

                colors[c] = temp;
            }
        }
    }

    public static class RandomNumberHelper
    {
        /// <summary>
        /// Pick a random number between min and max
        /// </summary>
        /// <param name="r">Random generator</param>
        /// <param name="min">Minimum value</param>
        /// <param name="max">Maximum value</param>
        /// <returns>A double, between min and max</returns>
        public static double NextDouble(this Random r, double min, double max)
        {
            double d = r.NextDouble() * (max-min) + min;
            return d;
        }
    }
}
