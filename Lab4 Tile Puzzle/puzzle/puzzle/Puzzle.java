package puzzle;

import java.util.Scanner;

public class Puzzle {

	static class Error implements PuzzleErrorHandler
	{
		public void handleError(String error)
		{
			System.out.println(error);
		}
	}
	
	//***************************************
	public static void main(String[] args) {
	    int row, col;
	    Error err = new Error();
	    Scanner reader = new Scanner(System.in);  // Reading from System.in

	    cPuzzle puzzle = new cPuzzle(4);
	    puzzle.SetErrorFunc(err);

	    while (true)
	    {
	        Display(puzzle);
	        System.out.print("Enter col: ");
	        col = reader.nextInt();
	        System.out.print("Enter col: ");
	        row = reader.nextInt();
	        puzzle.Move(row, col);
	    }    
	}

	//**************************************************
	static void Display(cPuzzle puzzle)
	{
	    for (int row=0; row<puzzle.Size(); row++)
	    {
	        for (int col=0; col<puzzle.Size(); col++)
	        {
	            if (puzzle.GetAt(row,col) == 0)
	                System.out.format("%4s", " ");
	            else
	            	System.out.format("%4d", puzzle.GetAt(row, col));
	        }
	        System.out.println("");
	    }
	}

}
