using System;
using System.Collections.Generic;
using System.Linq;
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

namespace InLab1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            //DataContext = this;
        }

        private async void StartStatusBarProgress(object sender, RoutedEventArgs e)
        {
            var me = sender as Button;
            me.Visibility = Visibility.Hidden;
            me.IsEnabled = false;
            var task = Task.Run(() => ExecuteStuff(50, 100));
            await task;
            me.IsEnabled = true;
            me.Visibility = Visibility.Visible;
        }

        internal void ExecuteStuff(int count, int delay)
        {
            for( int ii = 0; ii < count; ++ii)
            {
                System.Threading.Thread.Sleep(delay);
                Dispatcher.Invoke(() =>
                {
                    StatusBarProgress.Value = 100 * (ii + 1) / count;
                });
            }
        }
        
        private void VerifyUIResponsiveness(object sender, RoutedEventArgs e)
        {
            Random rando = new Random();
            SolidColorBrush bgbrush = new SolidColorBrush(Color.FromRgb((byte)rando.Next(255), (byte)rando.Next(255), (byte)rando.Next(255)));
            UIChecker.Fill = bgbrush;
        }
    }
}
