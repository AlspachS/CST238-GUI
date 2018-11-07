#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
using std::cout;
using std::endl;
using std::setw;

#include "cpuzzle.h"

//**************************************************
cPuzzle::cPuzzle(int size)
{
    srand(time(NULL));

    m_size = size;
    m_board = nullptr;
    m_ErrorFunc = nullptr;
    Reset();
}
//**************************************************
cPuzzle::cPuzzle()
{
    m_size = 4;
    m_board = nullptr;
    m_ErrorFunc = nullptr;
    Reset();
}

//**************************************************
void reset1()
{
    int **m_board = nullptr;;
    int m_size = 0;
    if (m_board == nullptr)
    {
        m_board = (int **)malloc(m_size * sizeof(int *));

        for (int ii=0; ii<m_size; ii++)
        {
            m_board[ii] = (int *)malloc(m_size * sizeof(int));
        }
    }

    for (int row=0; row<m_size; row++)
    {
        for (int col=0; col<m_size; col++)
        {
            m_board[row][col] = 0;
        }
    }

    for (int ii=1; ii<m_size*m_size; ii++)
    {
        int row, col;
        do
        {
            row = rand() % m_size;
            col = rand() % m_size;
        } while (m_board[row][col] != 0);

        m_board[row][col] = ii;
    }
}
//**************************************************
void cPuzzle::Reset()
{
    if (m_board == nullptr)
    {
        m_board = (int **)malloc(m_size * sizeof(int *));

        for (int ii=0; ii<m_size; ii++)
        {
            m_board[ii] = (int *)malloc(m_size * sizeof(int));
        }
    }

    for (int row=0; row<m_size; row++)
    {
        for (int col=0; col<m_size; col++)
        {
            m_board[row][col] = row*m_size + col;
        }
    }

    for (int ii=1; ii<20000; ii++)
    {
        int row, col;
        row = rand() % m_size;
        col = rand() % m_size;
        Move(row, col);
    }
}
//**************************************************
void cPuzzle::Move(int row, int col)
{
    if (row < 0 || col < 0 || row >= m_size || col >= m_size)
    {
        if (m_ErrorFunc != nullptr) m_ErrorFunc("Invalid param to Move");
        return;
    }
    
    if (m_board[row][col] == 0)
    {
        if (m_ErrorFunc != nullptr) m_ErrorFunc("Can't move the empty spot");
        return;
    }

    if (row > 0 && (m_board[row-1][col] == 0))
    {
        m_board[row-1][col] = m_board[row][col];
        m_board[row][col] = 0;
    }
    else if (col > 0 && (m_board[row][col-1] == 0))
    {
        m_board[row][col-1] = m_board[row][col];
        m_board[row][col] = 0;
    }
    else if (row < m_size-1 && (m_board[row+1][col] == 0))
    {
        m_board[row+1][col] = m_board[row][col];
        m_board[row][col] = 0;
    }
    else if (col < m_size-1 && (m_board[row][col+1] == 0))
    {
        m_board[row][col+1] = m_board[row][col];
        m_board[row][col] = 0;
    }
    else
    {
        if (m_ErrorFunc != nullptr) m_ErrorFunc("Not next to empty square");
    }

}

//**************************************************
void cPuzzle::SetErrorFunc( void (*errorFunc)(const string &msg))
{
    m_ErrorFunc = errorFunc;
}
//**************************************************
int cPuzzle::GetAt(int row, int col)
{
    if (row < 0 || col < 0 || row >= m_size || col >= m_size)
    {
        if (m_ErrorFunc != nullptr) m_ErrorFunc("Invalid param to GetAt");
        return 0;
    }

    return m_board[row][col];
}
//**************************************************
int cPuzzle::Size()
{
    return m_size;
}
