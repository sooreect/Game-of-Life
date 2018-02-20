//CS162 Assignment1
//Tida Sooreechine
//10/2/2015

//gameoflife.cpp is the Gameoflife class function implementation file

#include <iostream>
#include "gameoflife.hpp"

using std::cin;
using std::cout;
using std::endl;

/*********************************************************************
 * Function: Gameoflife::Gameoflife
 * Description: Gameoflife class constructor
 * Parameters: Three user input integers from client code, representing
 * 		configuration choice, x, and y coordinates.
 * Pre-Conditions: All three inputs are validated in client code.
 * Post-Conditions: All 2D arrays are initialized, and all user inputs 
 * 		are (corrected and) stored in member variables.
*********************************************************************/
Gameoflife::Gameoflife(int menu, int x0, int y0)
{	
	//initialize all matrix grid elements to 0 using nested for loops
	//cell status: 0 for dead, 1 for alive	
	for (int j = 0; j < 40; j++)	//matrix
	{
		for (int i = 0; i < 120; i++)
			matrix[j][i] = 0; 
	}
	for (int j = 0; j < 40; j++)	//newmatrix
	{
		for (int i = 0; i < 120; i++)
			newmatrix[j][i] = 0; 
	}
	
	//receive user inputs from client code and store to class member variables
	pattern = menu;		//configuration choice
	x = x0 - 1;			//adjust for offset on starting x-coordinate
	y = y0 - 1;			//adjust for offset on starting y-coordinate
}

/*********************************************************************
 * Function: Gameoflife::definegrid
 * Description: Function sets all relevant cells to alive status (1) and
 * 		translates pattern to starting location. This function is meant
 * 		to be used once per program run.
 * Parameters: None
 * Pre-Conditions: All 2D array elements have been initialized to 0.
 * Post-Conditions: Grid is updated to user's choice of pattern and starting
 * 		location. All relevant cells are activated to alive status.
*********************************************************************/
void Gameoflife::definegrid()
{
	if (pattern == 1)	//blinker configuration
	{ 
		matrix[10+y][41+x] = 1;
		matrix[11+y][41+x] = 1;
		matrix[12+y][41+x] = 1;
	}
	else if (pattern == 2)	//glider configuration
	{
		matrix[10+y][41+x] = 1;
		matrix[11+y][42+x] = 1;
		matrix[12+y][40+x] = 1;
		matrix[12+y][41+x] = 1;
		matrix[12+y][42+x] = 1;
	}
	else //pattern 3, gospel glider gun configuration
	{	
		//row 1
		matrix[10+y][64+x] = 1;

		//row 2
		matrix[11+y][62+x] = 1;
		matrix[11+y][64+x] = 1;
		
		//row 3
		matrix[12+y][52+x] = 1;
		matrix[12+y][53+x] = 1;
		matrix[12+y][60+x] = 1;
		matrix[12+y][61+x] = 1;
		matrix[12+y][74+x] = 1;
		matrix[12+y][75+x] = 1;
	
		//row 4
		matrix[13+y][51+x] = 1;
		matrix[13+y][55+x] = 1;
		matrix[13+y][60+x] = 1;
		matrix[13+y][61+x] = 1;
		matrix[13+y][74+x] = 1;
		matrix[13+y][75+x] = 1;
		
		//row 5
		matrix[14+y][40+x] = 1;
		matrix[14+y][41+x] = 1;
		matrix[14+y][50+x] = 1;
		matrix[14+y][56+x] = 1;
		matrix[14+y][60+x] = 1;
		matrix[14+y][61+x] = 1;

		//row 6
		matrix[15+y][40+x] = 1;
		matrix[15+y][41+x] = 1;
		matrix[15+y][50+x] = 1;
		matrix[15+y][54+x] = 1;
		matrix[15+y][56+x] = 1;
		matrix[15+y][57+x] = 1;
		matrix[15+y][62+x] = 1;
		matrix[15+y][64+x] = 1;
		
		//row 7
		matrix[16+y][50+x] = 1;
		matrix[16+y][56+x] = 1;
		matrix[16+y][64+x] = 1;
	
		//row 8
		matrix[17+y][51+x] = 1;
		matrix[17+y][55+x] = 1;
	
		//row 9
		matrix[18+y][52+x] = 1;
		matrix[18+y][53+x] = 1;
	}
}

/*********************************************************************
 * Function: Gameoflife::newgrid
 * Description: Function calculates the number of alive neighbors surrounding 
 * 		each matrix element and determine its new status based on the rules.
 * Parameters: None
 * Pre-Conditions: Starting configuration has been defined in Matrix.
 * Post-Conditions: A new grid is produced based on the former grid's 
 * 		arrangement of live cells.
*********************************************************************/
void Gameoflife::newgrid()
{
	//count neighbors using Moore's neighborhood algorithm
	//Source: http://code.runnable.com/UwQvQY99xW5AAAAQ/john-conway-s-game-of-life-for-c%2B%2B-nested-for-loops-and-2-dimensional-arrays
	for (int j = 0; j < 40; j++)
	{
		for (int i = 0; i < 120; i++)
		{
			int neighbors = 0;

			//[1][2][3]
			//[4][5][6]
			//[7][8][9]
		
			//start at cell above and proceed clockwise
			//end at northwest cell
			
			neighbors = matrix[j-1][i]	//2
				+ matrix[j-1][i+1]		//3
				+ matrix[j][i+1]		//6
				+ matrix[j+1][i+1]		//9
				+ matrix[j+1][i]		//8
				+ matrix[j+1][i-1]		//7
				+ matrix[j][i-1]		//4
				+ matrix[j-1][i-1];		//1
			
			//game of life rules
			//store the result of each element in newmatrix as to not affect current matrix
			if ((neighbors < 2) || (neighbors > 3))	//if neighbors = 0-1 or 4-8, cell dies
				newmatrix[j][i] = 0;	
			if (neighbors == 2) // if neighbors = 2, cell stays the same
				newmatrix[j][i] = matrix[j][i];	
			if (neighbors == 3) //if neighbors = 3, cell is alive regardless of status before
				newmatrix[j][i] = 1;
		}
	}
	
	//replace matrix elements with those calculated and saved in newmatrix
	for (int j = 0; j < 40; j++)
	{
		for (int i = 0; i < 120; i++)
			matrix[j][i] = newmatrix[j][i];
	}
}

/*********************************************************************
 * Function: Gameofelife::printgrid
 * Description: Function prints grid based on each element's status.
 * Parameters: None
 * Pre-Conditions: Matrix is updated.
 * Post-Conditions: The middle 40 columns x 20 rows of the total grid is
 * 		displayed. Each matrix element is marked with one of two symbols:
 * 		"$" and ".", where "$" means the cell is alive and "." means cell
 * 		is dead.
*********************************************************************/
void Gameoflife::printgrid()
{
	for (int j = 10; j < 30; j++)		//display columns 11 to 30
	{
		for (int i = 40; i < 80; i++)	//display rows 11 to 50
		{
			if (matrix[j][i] == 1)		//1 means cell is alive
				cout << "$";			//motivation to complete hw assignment		
			else
				cout << ".";			//0 means cell is dead
		}
		cout << endl;
	}
}
