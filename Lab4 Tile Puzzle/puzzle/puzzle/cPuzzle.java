package puzzle;

import java.util.Random;

public class cPuzzle {
    int m_size;
    int[][] m_board;
    PuzzleErrorHandler m_ErrorFunc;
    Random rand;

	//**************************************************
	cPuzzle(int size)
	{
	    rand = new Random();

	    m_size = size;
	    //m_ErrorFunc = nullptr;
	    Reset();
	}
	
	//**************************************************
	cPuzzle()
	{
	    m_size = 4;
	    Reset();
	}

	//**************************************************
	void Reset()
	{
	    if (m_board == null)
	    {
	        m_board = new int[m_size][m_size];
	    }

	    for (int row=0; row<m_size; row++)
	    {
	        for (int col=0; col<m_size; col++)
	        {
	            m_board[row][col] = row*m_size + col + 1;
	        }
	    }

	    m_board[m_size-1][m_size-1] = 0;

	    for (int ii=1; ii<20000; ii++)
	    {
	        int row, col;
	        row = rand.nextInt(m_size);
	        col = rand.nextInt(m_size);
	        Move(row, col);
	    }
	}
	//**************************************************
	void Move(int row, int col)
	{
	    if (row < 0 || col < 0 || row >= m_size || col >= m_size)
	    {
	        if (m_ErrorFunc != null) m_ErrorFunc.handleError("Invalid param to Move");
	        return;
	    }

	    if (m_board[row][col] == 0)
	    {
	        if (m_ErrorFunc != null) m_ErrorFunc.handleError("Can't move the empty spot");
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
	        if (m_ErrorFunc != null) m_ErrorFunc.handleError("Not next to empty square");
	    }

	}

	//**************************************************
	void SetErrorFunc(PuzzleErrorHandler handler)
	{
	    m_ErrorFunc = handler;
	}
	//**************************************************
	int GetAt(int row, int col)
	{
	    if (row < 0 || col < 0 || row >= m_size || col >= m_size)
	    {
	        if (m_ErrorFunc != null) m_ErrorFunc.handleError("Invalid param to GetAt");
	        return 0;
	    }

	    return m_board[row][col];
	}
	//**************************************************
	int Size()
	{
	    return m_size;
	}

}
