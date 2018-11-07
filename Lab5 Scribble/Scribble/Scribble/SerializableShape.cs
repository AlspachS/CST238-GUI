using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;

namespace Scribble
{
    public class SerializableShape
    {
        public enum shape { Rectangle, Ellipse, Line }
        public double Width { get; set; }
        public double Height { get; set; }
        public double Left { get; set; }
        public double Top { get; set; }
        public Color Fill { get; set; }
        public Color Border { get; set; }
        public shape Shape { get; set; }

        public void DrawShape(Canvas canvas)
        {
            switch (Shape)
            {
                case shape.Rectangle:
                    var quadrilateral = new Rectangle();
                    quadrilateral.Width = Width;
                    quadrilateral.Height = Height;
                    quadrilateral.Fill = new SolidColorBrush(Fill);
                    quadrilateral.Stroke = new SolidColorBrush(Border);
                    quadrilateral.StrokeThickness = 3;
                    Canvas.SetLeft(quadrilateral, Left);
                    Canvas.SetTop(quadrilateral, Top);
                    canvas.Children.Add(quadrilateral);
                    break;
                case shape.Ellipse:
                    var ellipise = new Ellipse();
                    ellipise.Width = Width;
                    ellipise.Height = Height;
                    ellipise.Fill = new SolidColorBrush(Fill);
                    ellipise.Stroke = new SolidColorBrush(Border);
                    ellipise.StrokeThickness = 3;
                    Canvas.SetLeft(ellipise, Left);
                    Canvas.SetTop(ellipise, Top);
                    canvas.Children.Add(ellipise);
                    break;
                case shape.Line:
                    var line = new Line();
                    line.X1 = Left;
                    line.X2 = Width;
                    line.Y1 = Top;
                    line.Y2 = Height;
                    line.StrokeThickness = 2;
                    line.Stroke = new SolidColorBrush(Fill);
                    canvas.Children.Add(line);
                    break;
                default:
                    break;
            }


        }
    }
}
