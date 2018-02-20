/******************************************************************************************
 * Program Filename: Assignment1.cpp 
 * Author: Tida Sooreechine
 * Date: 10/2/2015
 * Description: Conway's Game of Life
 * 		This program will run the game of life according to the rules and user inputs.
 * Inputs: Configuration choice, starting location (x,y), and number of evolutions
 * Output: Program will display changes of cell lives on a 40x20 grid at every evolution
******************************************************************************************/

#include <iostream>
#include <cstdlib> 		//header file needed to use system
#include <unistd.h>		//header file needed to use usleep

#include "gameoflife.hpp"	//contains Gameoflife class declaration

using std::cin;
using std::cout;
using std::endl;

int main()
{	
	int choice;				//menu choice
	int xstart, ystart;		//starting position (x,y)
	int evolutions;			//number of times to run loop
	
	system("clear");
	
	cout << "ASSIGNMENT 1: GAME OF LIFE" << endl;
	cout << "This is a C++ implementation of Conway's Game of Life." << endl << endl;
	cout << "The rules: " << endl;	//from assignment problem
	cout << "Each cell has eight neighborhood cells." << endl;
	cout << "1. If an occupied cell has 0 or 1 neighbor, it dies of loneliness." << endl;
	cout << "2. If an occupied cell has more than 3 neighbors, it dies of overcrowding." << endl;
	cout << "3. If an empty cell has exactly 3 occupied neighbor cells, there is a birth " << endl;
	cout << "of a new cell to replace the empty cell." << endl;
	cout << "4. Births aand deaths are instantaneous and occur at the changes of generation.";
	cout << endl << endl;	
	
	do 
	{	
		//display game menu
		cout << "Game of Life Menu:" << endl;
		cout << "1. Fixed Oscillator (Blinker)" << endl;
		cout << "2. Glider" << endl;
		cout << "3. Glider Gun" << endl;
		cout << "4. Quit the program" << endl << endl;
		
		//prompt user for menu choice
		cout << "Select your choice: ";
		cin >> choice;
		while (choice < 1 || choice > 4)	//validate choice 
		{
			cout << "Invalid input. Please re-enter (1-4): ";
			cin >> choice;
		}
		
		if (choice != 4) //if user does not want to quit, proceed
		{	
			cout << endl;
			cout << "Display will be a 40 x 20 frame." << endl << endl;
				
			//prompt user for x and y coordinates of starting position
			
			//starting x
			cout << "Specify the starting location's x-coordinate (1-40)";
			if (choice == 3)
			{	
				cout << endl;
				cout << "For best result in displaying the entire glider gun, use x value of 1-5";
			}
			cout << ": ";
			cin >> xstart;
			while (xstart < 1 || xstart > 40)	//validate xstart
			{
				cout << "Invalid input. Please re-enter (1-40): ";
				cin >> xstart;
			}
			cout << endl;
	
			//starting y
			cout << "Specify the starting location's y-coordinate (1-20)";
			if (choice == 3)
			{
				cout << endl;
				cout << "For best result in displaying the entire glider gun, use y value 1-5";
			}
			cout << ": ";
			cin >> ystart;
			while (ystart < 1 || ystart > 20)	//validate ystart
			{
				cout << "Invalid input. Please re-enter (1-20): ";
				cin >> ystart;
			}
			cout << endl;

			//prompt user for loop counts
			cout << "Specify the number of game evolutions: ";
			cin >> evolutions;
			while (evolutions < 1)	//validate evolutions
			{
				cout << "Invalid input. Enter a positive value: ";
				cin >> evolutions;
			}
				
			//Gameoflife class implementation
	
			//instantiate class object with menu choice and coordinates			
			Gameoflife object(choice, xstart, ystart);	
			
			//define and display grid using for loop for repitions
			for (int count = 0; count < evolutions; count++)
			{
				system("clear");			//clear screen

				if (count == 0)				//first run
					object.definegrid();	//define grid based on inputs
				else						//second run onward				
					object.newgrid();		//update grid based on neighbors count
			
				object.printgrid();			//print grid
				usleep(110000);				//pause 0.11 seconds between grids
											//source: Assignment 1 Q&A Forum
			}			
		}
		cout << endl;
	} while (choice != 4);	//keep running as long as user does not quit
	
	cout << "Good bye." << endl << endl;

	return 0;
}
