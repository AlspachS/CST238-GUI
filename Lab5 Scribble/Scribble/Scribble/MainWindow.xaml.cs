using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Xml.Serialization;

namespace Scribble
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private SolidColorBrush mFillColor = Brushes.White;
        private SolidColorBrush mBorderColor = Brushes.Black;
        private List<SerializableShape> mAllShapes = new List<SerializableShape>();
        private String mShape = "rectangle";
        private Point mStart;
        private Point mEnd;

        public MainWindow()
        {
            InitializeComponent();

            foreach (PropertyInfo prop in typeof(Brushes).GetProperties())
            {
                Button test = new Button();
                test.Template = (ControlTemplate)ColorPallette.FindResource("ColorPalletteButton");
                test.Background = (Brush)prop.GetValue(null);
                test.MouseRightButtonUp += ChangeBorderColor;
                test.Click += ChangeFillColor;
                ColorPallette.Children.Add(test);
            }
        }

        private void ChangeFillColor(object sender, RoutedEventArgs e)
        {
            var curr = sender as Button;
            mFillColor = (SolidColorBrush)curr.Background;
        }

        private void ChangeBorderColor(object sender, RoutedEventArgs e)
        {
            var curr = sender as Button;
            mBorderColor = (SolidColorBrush)curr.Background;
        }

        private void SetShape(object sender, RoutedEventArgs e)
        {
            Button curr = sender as Button;
            mShape = curr.Name;
        }

        private void Clear_Click(object sender, RoutedEventArgs e)
        {
            DrawSurface.Children.Clear();
        }

        private void About_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Steven Alspach\nsteven.alspach@oit.edu");
        }

        private void Save_Click(object sender, RoutedEventArgs e)
        {
            string filename = String.Empty;

            Microsoft.Win32.SaveFileDialog saveFileWindow = new Microsoft.Win32.SaveFileDialog();
            saveFileWindow.InitialDirectory = "";
            //saveFileWindow.CheckFileExists = true;

            if (saveFileWindow.ShowDialog() == true)
            {
                filename = saveFileWindow.FileName;

                var serializer = new XmlSerializer(mAllShapes.GetType());
                using (TextWriter writer = new StreamWriter(filename))
                {
                    serializer.Serialize(writer, mAllShapes);
                }
            }
        }

        private void Load_Click(object sender, RoutedEventArgs e)
        {
            string filename = String.Empty;

            Microsoft.Win32.OpenFileDialog openFileWindow = new Microsoft.Win32.OpenFileDialog();
            openFileWindow.InitialDirectory = "";
            openFileWindow.CheckFileExists = true;

            if (openFileWindow.ShowDialog() == true)
            {
                filename = openFileWindow.FileName;

                var serializer = new XmlSerializer(mAllShapes.GetType());
                using (FileStream fs = new FileStream(filename, FileMode.Open))
                {
                    mAllShapes = (List<SerializableShape>)serializer.Deserialize(fs);
                }

                DrawSurface.Children.Clear();

                foreach (SerializableShape shape in mAllShapes)
                {
                    shape.DrawShape(DrawSurface);
                }
            }
        }

        private void DrawSurface_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            mStart = e.GetPosition(DrawSurface);
        }

        private void DrawSurface_PreviewMouseUp(object sender, MouseButtonEventArgs e)
        {
            mEnd = e.GetPosition(DrawSurface);
            var myShape = new SerializableShape();
            switch (mShape)
            {
                case "rectangle":
                    myShape.Shape = SerializableShape.shape.Rectangle;
                    myShape.Width = Math.Abs(mStart.X - mEnd.X);
                    myShape.Height = Math.Abs(mStart.Y - mEnd.Y);
                    myShape.Fill = mFillColor.Color;
                    myShape.Border = mBorderColor.Color;
                    myShape.Left = mStart.X < mEnd.X ? mStart.X : mEnd.X;
                    myShape.Top = mStart.Y < mEnd.Y ? mStart.Y : mEnd.Y;
                    break;
                case "ellipse":
                    myShape.Shape = SerializableShape.shape.Ellipse;
                    myShape.Width = Math.Abs(mStart.X - mEnd.X);
                    myShape.Height = Math.Abs(mStart.Y - mEnd.Y);
                    myShape.Fill = mFillColor.Color;
                    myShape.Border = mBorderColor.Color;
                    myShape.Left = mStart.X < mEnd.X ? mStart.X : mEnd.X;
                    myShape.Top = mStart.Y < mEnd.Y ? mStart.Y : mEnd.Y;
                    break;
                case "line":
                    myShape.Shape = SerializableShape.shape.Line;
                    myShape.Width = mEnd.X;
                    myShape.Height = mEnd.Y;
                    myShape.Fill = mFillColor.Color;
                    myShape.Border = mBorderColor.Color;
                    myShape.Left = mStart.X;
                    myShape.Top = mStart.Y;
                    break;
                default:
                    break;
            }
            myShape.DrawShape(DrawSurface);
            mAllShapes.Add(myShape);
        }
    }
}
