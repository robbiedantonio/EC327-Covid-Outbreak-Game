#include "Building.h"
using namespace std;

//Default Constructor
Building::Building() : GameObject('B')
{
	student_count = 0;
	cout << "Building default constructed" << endl;
}

//Constructor 1
Building::Building(char in_code, int in_id, Point2D in_loc) : GameObject(in_loc, in_id, in_code)
{
	student_count = 0;
	cout << "Building constructed" << endl;
}

//Add one student
void Building::AddOneStudent()
{
	student_count++;
}

//Remove one student
void Building::RemoveOneStudent()
{
	student_count--;
}

//Show status
void Building::ShowStatus()
{
	GameObject::ShowStatus();
	cout << endl;
	if (student_count == 1)
		cout << student_count << " student is in this building" << endl;
	else
		cout << student_count << " students are in this building" << endl;
}

//Should be visible 
bool Building::ShouldBeVisible()
{
	return true;
}