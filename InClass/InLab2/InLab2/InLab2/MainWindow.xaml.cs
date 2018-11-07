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

namespace InLab2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        int moveNumber = 0;
        string CurrentPlayer = "X";

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Button button = (Button)sender;
            if (button.Content != null) { return; }

            button.Content =
               new PlayerMove(this.CurrentPlayer, ++this.moveNumber);
             
            if (CurrentPlayer == "X")
                CurrentPlayer = "O";
            else
                CurrentPlayer = "X";
        }
    }
}

