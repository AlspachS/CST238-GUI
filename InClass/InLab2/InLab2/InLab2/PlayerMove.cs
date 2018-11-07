using System.ComponentModel;

namespace InLab2
{
    public class PlayerMove : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        void Notify(string propName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propName));
            }
        }

        public string PlayerName { get; } 
        public int CurrentMove { get; }

        public PlayerMove(string currentplayer, int currentmove)
        {
            PlayerName = currentplayer;
            CurrentMove = currentmove;
            Notify("PlayerName");
            Notify("CurrentMove");
        }

    }
}