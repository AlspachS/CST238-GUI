#include <string>
using std::string;

class cPuzzle
{
    public:
        cPuzzle(int size);
        cPuzzle();

        void Reset();
        void Move(int row, int col);
        int  GetAt(int row, int col);
        void SetErrorFunc( void (*errorFunc)(const string &msg));
        int  Size();
    protected:
        int m_size;
        int **m_board;
        void (*m_ErrorFunc)(const string &msg);
};

