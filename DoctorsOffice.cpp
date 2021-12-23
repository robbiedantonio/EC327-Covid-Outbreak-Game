#include "DoctorsOffice.h"
using namespace std;

//Default Constructor
DoctorsOffice::DoctorsOffice() : Building()
{
	display_code = 'D';
	vaccine_capacity = 100;
	num_vaccine_remaining = vaccine_capacity;
	dollar_cost_per_vaccine = 5;
	state = VACCINE_AVAILABLE;

	cout << "DoctorsOffice default constructed" << endl;
}

//Constructor 1
DoctorsOffice::DoctorsOffice(int in_id, double vaccine_cost, unsigned int vaccine_cap, Point2D in_loc) : Building('D', in_id, in_loc)
{
	dollar_cost_per_vaccine = vaccine_cost;
	vaccine_capacity = vaccine_cap;
	num_vaccine_remaining = vaccine_capacity;
	state = VACCINE_AVAILABLE;

	cout << "DoctorsOffice constructed" << endl;
}

//Return true if DoctorsOffice has vaccines available
bool DoctorsOffice::HasVaccine()
{
	if(num_vaccine_remaining >= 1)
		return true;
	else
		return false;
}

//Return number of vaccines remaining in DoctorsOffice
unsigned int DoctorsOffice::GetNumVaccineRemaining()
{
	return num_vaccine_remaining;
}

//Returns true if Student can afford vaccines 
bool DoctorsOffice::CanAffordVaccine(unsigned int vaccine, double budget)
{
	if(budget >= (vaccine * dollar_cost_per_vaccine))
		return true;
	else
		return false;
}

//Returns price for specified number of vaccines
double DoctorsOffice::GetDollarCost(unsigned int vaccine)
{
	return vaccine * dollar_cost_per_vaccine;
}

//Take vaccines from DoctorsOffice
unsigned int DoctorsOffice::DistributeVaccine(unsigned int vaccine_needed)
{
	if(num_vaccine_remaining >= vaccine_needed)
	{
		num_vaccine_remaining -= vaccine_needed;
		return vaccine_needed;
	}
	else
	{
		unsigned int current = num_vaccine_remaining;
		num_vaccine_remaining = 0;
		return current;
		
	}
}

//Updates state and display code if DoctorsOffice runs out of vaccines
bool DoctorsOffice::Update()
{
	if(num_vaccine_remaining == 0 && state == VACCINE_AVAILABLE)
	{
		state = NO_VACCINE_AVAILABLE;
		display_code = 'd';
		cout << "DoctorsOffice " << id_num << " has ran out of vaccine." << endl;
		return true;
	}
	else
		return false;
}

//Outputs status of member variables for DoctorsOffice and GameObject
void DoctorsOffice::ShowStatus()
{
	cout << "DoctorsOffice Status: " << endl;
	Building::ShowStatus();
	cout << "Dollars per vaccine: " << dollar_cost_per_vaccine << endl;
	cout << "Has " << num_vaccine_remaining << " vaccine(s) remaining." << endl;
}

//Destructor
DoctorsOffice::~DoctorsOffice()
{
	cout << "DoctorsOffice destructed." << endl;
}

