#include "ClassRoom.h"
using namespace std;

//Default Constructor
ClassRoom::ClassRoom() : Building()
{
	display_code = 'C';
	state = NOT_PASSED;
	max_number_of_assignments = 10;
	num_assignments_remaining = max_number_of_assignments;
	antibody_cost_per_assignment = 1;
	dollar_cost_per_assignment = 1.0;
	credits_per_assignment = 2;
	cout << "ClassRoom default constructed" << endl;
}

//Constructor 1
ClassRoom::ClassRoom(unsigned int max_assign, unsigned int antibody_cost, double dollar_cost,
		unsigned int crd_per_assign, int in_id, Point2D in_loc) : Building('C', in_id, in_loc)
{
	max_number_of_assignments = max_assign;
	antibody_cost_per_assignment = antibody_cost;
	credits_per_assignment = crd_per_assign;
	dollar_cost_per_assignment = dollar_cost;

	state = NOT_PASSED;
	num_assignments_remaining = max_number_of_assignments;

	cout << "ClassRoom constructed" << endl;
}

//Return cost of purchasing unit_qty of assignments
double ClassRoom::GetDollarCost(unsigned int unit_qty)
{
	return unit_qty * dollar_cost_per_assignment;
}

//Return amount of antibodies req. for unit_qty of assignments
unsigned int ClassRoom::GetAntibodyCost(unsigned int unit_qty)
{
	return unit_qty * antibody_cost_per_assignment;
}

//Returns number of assignments remaining
unsigned int ClassRoom::GetNumAssignmentsRemaining()
{
	return num_assignments_remaining;
}

//Returns true if student can take unit_qty assignments with provided budget and antibodies
bool ClassRoom::IsAbleToLearn(unsigned int unit_qty, double budget, unsigned int antibodies)
{
	if(budget >= (unit_qty * dollar_cost_per_assignment) && 
		antibodies >= (unit_qty * antibody_cost_per_assignment))
	{
		return true;
	}
	else
		return false;
}

//Subtracts assignment_units from num_assignments_remaining, and calculates credits gained
unsigned int ClassRoom::TrainStudents(unsigned int assignment_units)
{
	if(assignment_units <= num_assignments_remaining)
	{
		num_assignments_remaining -= assignment_units;
		return assignment_units * credits_per_assignment;
	}
	else
	{
		unsigned int current = num_assignments_remaining;
		num_assignments_remaining = 0;
		return current * credits_per_assignment;
	}
}

//Updates state and display code if ClassRoom has been passed
bool ClassRoom::Update()
{
	if(num_assignments_remaining == 0 && state == NOT_PASSED)
	{
		state = PASSED;
		display_code = 'c';
		cout << display_code << id_num << " has been passed" << endl;
		return true;
	}
	else
		return false;
}

//Returns true if assignments remaining is 0
bool ClassRoom::passed()
{
	if(num_assignments_remaining == 0)
		return true;
	else
		return false;
}

//Outputs status of member variables for ClassRoom and Building
void ClassRoom::ShowStatus()
{
	cout << "ClassRoom Status: " << endl;
	Building::ShowStatus();
	cout << "Max number of assignments: " << max_number_of_assignments << endl;
	cout << "Antibody cost per assignment: " << antibody_cost_per_assignment << endl;
	cout << "Dollar per assignment: " << dollar_cost_per_assignment << endl;
	cout << "Credits per assignment: " << credits_per_assignment << endl;
	cout << num_assignments_remaining << " assignment(s) are remaining for this ClassRoom" << endl;
}

//Destructor
ClassRoom::~ClassRoom()
{
	cout << "ClassRoom destructed." << endl;
}
