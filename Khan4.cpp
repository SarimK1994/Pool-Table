/**************************************************************************
*                                                                         *
*     Program Filename:  Khan4.cpp                                        *
*     Author          :  Sarim Khan                                       *
*     Date Written    :  November 6th, 2017                               *
*     Purpose         :  To simulate a pool table at 45 angles            *
*     Input from      :  Keyboard                                         *
*     Output to       :  Screen                                           *
*                                                                         *
**************************************************************************/
#include <iostream>
#include "Point.h"
using namespace std;

void DeclareVariables(double&, double&, int&, Point&);
void TestViolations(Point &P); 
void EndProgram(); 
void Rails(Point&, double&, int&); 

int main()
{
	Point P;

	double	X, Y; 
    double StepSize = 0.001, Direction = 45.0;
	int N; 
	int counter = 0; 

	DeclareVariables(X, Y, N, P); 
      
   while (counter < N)
   {
      P.moveInDirection(Direction, StepSize);
	  TestViolations(P);  
	  Rails(P, Direction, counter); 
   }

   EndProgram(); 
}//end main 
   


//Functions below: 
void Rails(Point &P, double &Direction, int &Counter)
{
	    if (P.getX() == 125.0 && P.getY() == 45.0)
		{
			cout << endl << "TOP";
			cout << endl << "RIGHT";
			Counter++;
			Counter++; 
			Direction = 225.0;
		}//top right 
		else if (P.getX() == 125.0 && P.getY() == 0.0)
		{
			cout << endl << "BOTTOM";
			cout << endl << "RIGHT";
			Counter++;
			Counter++; 
			Direction = 135.0;
		}//bottom right
		else if (P.getX() == 0.0 && P.getY() == 0.0)
		{
			cout << endl << "BOTTOM";
			cout << endl << "LEFT";
			Counter++;
			Counter++; 
			Direction = 45.0;
		}//bottom left
		else if (P.getX() == 0.0 && P.getY() == 45.0)
		{
			cout << endl << "TOP";
			cout << endl << "LEFT";
			Counter++;
			Counter++; 
			Direction = 315.0;
		}//top left
	else if (P.getY() == 45.0)
	{
		cout << endl << "TOP";
		Counter++;
		if (Direction == 45.0)
		{
			Direction = 315.0;
		}
		else if (Direction == 135.0)
		{
			Direction = 225.0;
		}
	}//hit top
	else if (P.getY() == 0.0)
	{
		cout << endl << "BOTTOM";
		Counter++;
		if (Direction == 315.0)
		{
			Direction = 45.0;
		}
		else if (Direction == 225.0)
		{
			Direction = 135.0;
		}
	}// hit bottom
	else if (P.getX() == 125.0)
	{
		cout << endl << "RIGHT";
		Counter++;
		if (Direction == 315.0)
		{
			Direction = 225.0;
		}
		else if (Direction == 45.0)
		{
			Direction = 135.0;
		}
	}//hit right 
	else if (P.getX() == 0.0)
	{
		cout << endl << "LEFT";
		Counter++;
		if (Direction == 225.0)
		{
			Direction = 315.0;
		}
		else if (Direction == 135.0)
		{
			Direction = 45.0;
		}
	}//hit left 
}//end rails 
void DeclareVariables(double &X, double &Y, int &N, Point &P)
{
	cout << endl << "Enter the starting point for the X coordinate between 0 and 125: ";
	cin >> X;

	cout << endl << "Please enter the starting point for the Y coordinate between 0 and 45: ";
	cin >> Y;

	if (X < 0 || X > 125)
	{
		cout << endl << "You have entered an invalid X coordinate, please try again.";
		std::abort();
	}

	if (Y < 0 || Y > 45)
	{
		cout << endl << "You have entered an invalid Y coordinate, please try again.";
		std::abort();
	}

	cout << endl << "Please enter the number of times you would like to hit the rails: ";
	cin >> N;

	P.setX(X);
	P.setY(Y);
}//end declarevariabls 
   
void EndProgram()
{
	cout << endl << endl << "Please press enter to continue"; 
	cin.ignore();
	cin.get(); 
} //endprogram 

void TestViolations(Point &P)
{
	if (P.getX() < 0.0)
	{
		P.setX(0.0);
	}

	if (P.getX() > 125.0)
	{
		P.setX(125.0);
	}
	if (P.getY() < 0.0)
	{
		P.setY(0.0);
	}
	if (P.getY() > 45.0)
	{
		P.setY(45.0);
	}
}//end test violations