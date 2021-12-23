#include "Student.h"
using namespace std;

//Default Constructor
Student::Student() : GameObject('S')
{
	speed = 5;
	state = STOPPED;

	is_at_doctor = false;
	is_in_class = false;
	has_virus = false;
	antibodies = 20;
	credits = 0;
	dollars = 0;
	assignments_to_buy = 0;
	vaccines_to_buy = 0;

	cout << "Student default constructed." << endl;
}

//Constructor 1
Student::Student(char in_code) : GameObject(in_code)
{
	speed = 5;
	state = STOPPED;

	is_at_doctor = false;
	is_in_class = false;
	has_virus = false;
	antibodies = 20;
	credits = 0;
	dollars = 0;
	assignments_to_buy = 0;
	vaccines_to_buy = 0;

	cout << "Student constructed." << endl;
}

//Constructor 2
Student::Student(string in_name, int in_id, char in_code, unsigned int in_speed, 
	Point2D in_loc) : GameObject(in_loc, in_id, in_code)
{
	speed = in_speed;
	name = in_name;

	state = STOPPED;

	is_at_doctor = false;
	is_in_class = false;
	has_virus = false;
	antibodies = 20;
	credits = 0;
	dollars = 0;
	assignments_to_buy = 0;
	vaccines_to_buy = 0;

	cout << "Student constructed." << endl;
}

//Start moving toward point
void Student::StartMoving(Point2D dest)
{
	if (dest.x == location.x && dest.y == location.y)
		cout << display_code << id_num << ": I'm already there. See?" << endl;
	else if(IsInfected())
		cout << display_code << id_num << ": I am infected. I may move but you cannot see me." << endl;
	else
	{
		SetupDestination(dest);
		state = MOVING;
		cout << display_code << id_num << ": On my way." << endl;
	}
}

//Start moving toward classroom
void Student::StartMovingToClass(ClassRoom* classr)
{
	if(IsInfected())
		cout << display_code << id_num << ": I am infected so I can't move to class..." << endl;
	else if(state == IN_CLASS)
		cout << display_code << id_num << ": I am already at the Classroom!" << endl;
	else
	{		
		current_class = classr;
		SetupDestination(current_class->GetLocation());
		state = MOVING_TO_CLASS;
		cout << display_code << id_num << ": on my way to class " << classr->GetId() << endl;
	}
}

//Start moving toward Doctors office
void Student::StartMovingToDoctor(DoctorsOffice* office)
{
	if(IsInfected())
		cout << display_code << id_num << ": I am infected so I should have gone to the doctor's..." << endl;
	else if(state == AT_DOCTORS)
		cout << display_code << id_num << ": I am already at the Doctor's!" << endl;
	else
	{			
		current_office = office;
		SetupDestination(current_office->GetLocation());
		state = MOVING_TO_DOCTOR;
		cout << display_code << id_num << ": On my way to doctor's " << office->GetId() << endl;
	}
}

//Start learning assignments when in classroom
void Student::StartLearning(unsigned int num_assignments)
{
	if(IsInfected())
		cout << display_code << id_num << ": I am infected so no more school for me..." << endl;
	else if(is_in_class == 0)
		cout << display_code << id_num << ": I can only learn in a ClassRoom!" << endl;
	else if(current_class->IsAbleToLearn(num_assignments, dollars, antibodies) == 0)
		cout << display_code << id_num << ": Not enough antibodies and/or money for school" << endl;
	else if(current_class->GetNumAssignmentsRemaining() == 0)
		cout << display_code << id_num << ": Cannot learn! This class has no more assignments!" << endl;
	else
	{
		state = STUDYING_IN_CLASS;
		cout << display_code << id_num << ": Started to learn at the ClassRoom " << current_class->GetId() << " with " << num_assignments << " assignments" << endl;

		assignments_to_buy = num_assignments;
		current_class->TrainStudents(assignments_to_buy);
	}
}

//Start recovering antibodies when at doctors office
void Student::StartRecoveringAntibodies(unsigned int num_vaccines)
{
	if(is_at_doctor == 0) 
		cout << display_code << id_num << ": I can only recover antibodies at a Doctor's Office!" << endl;
	else if(current_office->GetNumVaccineRemaining() == 0)
		cout << display_code << id_num << ": Cannot recover! No vaccine remaining in this Doctor's Office" << endl;
	else if(current_office->CanAffordVaccine(num_vaccines, dollars) == 0)
		cout << display_code << id_num << ": Not enough money to recover antibodies." << endl;
	else
	{
		state = RECOVERING_ANTIBODIES;
		cout << display_code << id_num << ": Started recovering " << num_vaccines << " vaccines at Doctor's office " << current_office->GetId() << endl;
	
		vaccines_to_buy = num_vaccines;
		current_office->DistributeVaccine(vaccines_to_buy);
		antibodies += 5 * vaccines_to_buy;
		is_at_doctor = 0;
	}
}

//Tells student to stop everything
void Student::Stop()
{
	state = STOPPED;
	cout << display_code << id_num << ": Stopping..." << endl;
}

//Returns true of antibodies is 0 (student is infected)
bool Student::IsInfected()
{
	if(antibodies <= 0)
	{
		antibodies = 0;
		state = INFECTED;
		return true;
	}
	else
		return false;
}


void Student::ContractVirus(int virulence, bool virus_is_alive)
{
	if(virus_is_alive)
	{
		has_virus = true;
		antibodies -= virulence;
	}
	
}


//Returns true if student is not infected
bool Student::ShouldBeVisible()
{
	if(antibodies > 0)
		return true;
	else
		return false;
}

//Returns name of student
string Student::GetName()
{
	return name;
}


//Outputs what is happening for each state
void Student::ShowStatus()
{
	cout << name << " status: " << endl;
	GameObject::ShowStatus();

	if(IsInfected())
		cout << " infected. " << name << " can no longer move!" << endl;
	switch(state)
	{
		case STOPPED:
			cout << " stopped" << endl;
			break;
		case MOVING:
			cout << " moving at a speed of " << speed << " to destination " << destination << " at each step of " << delta << endl;
			break;
		case MOVING_TO_CLASS:
			cout << " heading to Classroom " << current_class->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
			break;
		case MOVING_TO_DOCTOR:
			cout << " heading to Doctor's Office " << current_office->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
			break;
		case IN_CLASS:
			cout << " inside Classroom " << current_class->GetId() << endl;
			break;
		case AT_DOCTORS:
			cout << " inside Doctor's Office " << current_office->GetId() << endl;
			break;
		case STUDYING_IN_CLASS:
			cout << " studying in classroom " << current_class->GetId() << endl;
			break;
		case RECOVERING_ANTIBODIES:
			cout << " recovering antibodies in Doctor's Office " << current_office->GetId() << endl;
			break;
	}

	cout << "Antibodies: " << antibodies << endl;
	cout << "Dollars: " << dollars << endl;
	cout << "Credits: " << credits << endl;

	if(has_virus)
		cout << "This student is infected with a virus!!" << endl;
}

//Updates objects
bool Student::Update()
{
	//IsInfected();

	switch(state)
	{
		case STOPPED:
			return false;
			break;
		case MOVING:
			if(is_in_class)
			{
				current_class->RemoveOneStudent();
				is_in_class = false;
			}

			if(is_at_doctor)
			{
				current_office->RemoveOneStudent();
				is_at_doctor = false;
			}

			is_at_destination = UpdateLocation();
			if(is_at_destination)
			{
				state = STOPPED;
				return true;
				break;
			}
			else
			{
				return false;
				break;
			}
		case MOVING_TO_CLASS: 
			if(is_at_doctor)
			{
				current_office->RemoveOneStudent();
				is_at_doctor = false;
			}

			is_in_class = UpdateLocation();
			if(is_in_class)
			{
				current_class->AddOneStudent();
				state = IN_CLASS;
				return true;
				break;
			}
			else
			{
				return false;
				break;
			}
		case MOVING_TO_DOCTOR:
			if(is_in_class)
			{
				current_class->RemoveOneStudent();
				is_in_class = false;
			}

			is_at_doctor = UpdateLocation();
			if(is_at_doctor)
			{	
				current_office->AddOneStudent();
				state = AT_DOCTORS;
				return true;
				break;
			}	
			else
			{
				return false;
				break;
			}
		case IN_CLASS:
			return false;
			break;
		case AT_DOCTORS:
			return false;
			break;
		case STUDYING_IN_CLASS:
			credits_gained = current_class->TrainStudents(assignments_to_buy);
			antibodies -= current_class->GetAntibodyCost(assignments_to_buy);
			dollars -= current_class->GetDollarCost(assignments_to_buy);
			credits += credits_gained;
			cout << "** " << name << " completed " << assignments_to_buy << " assignment(s)!**" << endl;
			cout << "** " << name << " gained " << credits_gained << " credit(s)" << endl;
			state = IN_CLASS;
			return true;
			break;
		case RECOVERING_ANTIBODIES:
			antibodies_recovered = 5 * vaccines_to_buy;
			StartRecoveringAntibodies(vaccines_to_buy);
			dollars -= current_office->GetDollarCost(vaccines_to_buy);
			cout << "** " << name << " recovered " << antibodies_recovered << " antibodie(s)! **" << endl;
			cout << "** " << name << " bought " << vaccines_to_buy << " vaccine(s)! **" << endl;
			state = AT_DOCTORS;
			return true;
			break;
		case INFECTED:
			return false;
			break;
		default:
			return false;
	}
}

//Updates location for each step
bool Student::UpdateLocation()
{
	//Check if object is within a step of its location
	if(fabs(destination.x - location.x) <= fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y)) 
	{
		location = destination;
		cout << display_code << id_num << ": I'm there!" << endl;
		return true; //object has arrived
	}
	else
	{
		location = location + delta;
		cout << display_code << id_num << ": step..." << endl;
		dollars += GetRandomAmountOfDollars();
		if(antibodies > 0)
			antibodies--;
		return false; //object has not yet arrived
	}
}

//Sets up object to start moving toward destination
void Student::SetupDestination(Point2D dest)
{
	destination = dest;
	delta = (destination - location) * (speed / GetDistanceBetween(destination, location));
}

//Destructor
Student::~Student()
{
	cout << "Student destructed" << endl;
}


//Get random amount of money
double GetRandomAmountOfDollars()
{
	srand (time(NULL)); //seed
	return rand() % 3;
}



