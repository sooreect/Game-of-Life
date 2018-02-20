//CS162 Assignment1
//Tida Sooreechine
//10/2/15

//gameoflife.hpp is the Gameoflife class specification file

#ifndef GAMEOFLIFE_HPP
#define GAMEOFLIFE_HPP

//Gameoflife class declaration
class Gameoflife
{
	private:
		int pattern;
		int x, y;
		int matrix[40][120];		//extra 40 cols on each side and 10 top and bottom
		int newmatrix[40][120];		//extra 40 cols on each side and 10 top and bottom
	
	public: 
		Gameoflife(int menu, int x0, int y0);	//constructor	
		void definegrid();	//redefine grid based on user's menu choice
		void newgrid();		//count cell neighbors and establish new life statuses
		void printgrid();	//print grid based on cell's statuses
};

#endif
