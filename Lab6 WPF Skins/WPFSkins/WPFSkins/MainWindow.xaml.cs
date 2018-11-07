using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WPFSkins
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Style_Button1_Click(object sender, RoutedEventArgs e)
        {
            ResourceDictionary skinny = new ResourceDictionary();
            skinny.Source = new Uri("Style1.xaml", UriKind.Relative);
            Collection<ResourceDictionary> appMergedDictionaries = Application.Current.Resources.MergedDictionaries;
            if(appMergedDictionaries.Count != 0)
            {
                appMergedDictionaries.Remove(appMergedDictionaries[0]);
            }
            appMergedDictionaries.Add(skinny);
        }

        private void Style_Button2_Click(object sender, RoutedEventArgs e)
        {
            ResourceDictionary skinny = new ResourceDictionary();
            skinny.Source = new Uri("Style2.xaml", UriKind.Relative);
            Collection<ResourceDictionary> appMergedDictionaries = Application.Current.Resources.MergedDictionaries;
            if (appMergedDictionaries.Count != 0)
            {
                appMergedDictionaries.Remove(appMergedDictionaries[0]);
            }
            appMergedDictionaries.Add(skinny);
        }

        private void Style_Button3_click(object sender, RoutedEventArgs e)
        {
            try
            {
                ResourceDictionary resources = null;
                using (FileStream fs = new FileStream("Style3.xaml", FileMode.Open, FileAccess.Read))
                {
                    resources = XamlReader.Load(fs) as ResourceDictionary;
                }
                Application.Current.Resources = resources;
            }
            catch (Exception)
            {

                
            }
            
        }

        private void Style_Button4_click(object sender, RoutedEventArgs e)
        {
            ResourceDictionary resources = null;
            using (FileStream fs = new FileStream("Style4.xaml", FileMode.Open, FileAccess.Read))
            {
                resources = XamlReader.Load(fs) as ResourceDictionary;
            }
            Application.Current.Resources = resources;
        }
    }
}