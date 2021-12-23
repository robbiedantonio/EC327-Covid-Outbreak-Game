#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "DoctorsOffice.h"
#include "ClassRoom.h"
#include "Student.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"
#include "Virus.h"
#include "Input_Handling.h"
using namespace std;

int main()
{
	//Header
	cout << endl << "Robert D'Antonio U51521187" << endl << "EC327: Introduction to Software Engineering" << endl << "Fall 2021" << endl <<"Programming Assignment 3" << endl << endl;
	cout << endl << "C O V I D   O U T B R E A K" << endl << endl;

	//Variables used in commands
	char commandIn;
	int ID, ID1, ID2, vaccine_amount, assignment_amount; 
	double x, y;

	//Create model default
	Model m1;
	View v1;
	m1.ShowStatus();
	m1.Display(v1);

	//Command interface
	do{
		cout << "Enter command: ";
		cin >> commandIn;
		
		try
		{
			switch(commandIn)
			{
				case 'm':
					cin >> ID >> x >> y;
					DoMoveCommand(m1, ID, Point2D(x, y));
					break;
				case 'd':
					cin >> ID1 >> ID2;
					DoMoveToDoctorCommand(m1, ID1, ID2);
					break;
				case 'c':
					cin >> ID1 >> ID2;
					DoMoveToClassCommand(m1, ID1, ID2);
					break;
				case 's':
					cin >> ID;
					DoStopCommand(m1, ID);
					break;
				case 'v':
					cin >> ID >> vaccine_amount;
					DoRecoverInOfficeCommand(m1, ID, vaccine_amount);
					break;
				case 'a':
					cin >> ID >> assignment_amount;
					DoLearningCommand(m1, ID, assignment_amount);
					break;
				case 'g':
					cout << endl;
					DoGoCommand(m1, v1);
					break;
				case 'r':
					cout << endl;
					DoRunCommand(m1, v1);
					break;
				default:
					throw Invalid_Input("Valid commands are: m, d, c, s, v, a, g, r");
			}

		}
		catch (Invalid_Input& except)
		{
			cout << "Invalid input - " << except.msg_ptr << endl;
		}

	}while(commandIn != 'q');

	return 0;
}