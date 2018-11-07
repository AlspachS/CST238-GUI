using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InLab1
{
    public class ResourceTest : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        public ResourceTest() : this("SaveTheWorld", 0) { }
        public ResourceTest(string saveTheWorldTask, int prog)
        {
            SaveTheWorldTask = saveTheWorldTask;
            SaveTheWorldTaskProgress = prog;
        }

        void Notify(string propName)
        {
            if(PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propName));
            }
        }
        private string SaveTheWorldTask;
        public string ETask
        {
            get { return SaveTheWorldTask; }
            set
            {
                SaveTheWorldTask = value;
                Notify("SaveTheWorldTask");
            }
        }

        private int SaveTheWorldTaskProgress;
        public int ETaskProgress
        {
            get { return SaveTheWorldTaskProgress; }
            set
            {
                SaveTheWorldTaskProgress = value;
                Notify("SaveTheWorldTaskProgress");
            }
        }
    }


}
