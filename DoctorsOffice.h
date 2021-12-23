#ifndef DOCTORSOFFICE_H
#define DOCTORSOFFICE_H

#include <iostream>
#include "Building.h"
#include "Point2D.h"
using namespace std;

enum DoctorsOfficeStates //State machine
{
	VACCINE_AVAILABLE	=0,
	NO_VACCINE_AVAILABLE = 1
};

class DoctorsOffice: public Building
{
private:
	unsigned int vaccine_capacity;
	unsigned int num_vaccine_remaining;
	double dollar_cost_per_vaccine;
public:
	DoctorsOffice(); //Default constructor
	DoctorsOffice(int in_id, double vaccine_cost, unsigned int vaccine_cap, Point2D in_loc); //Constructor 1
	bool HasVaccine();
	unsigned int GetNumVaccineRemaining();
	bool CanAffordVaccine(unsigned int vaccine, double budget);
	double GetDollarCost(unsigned int vaccine);
	unsigned int DistributeVaccine(unsigned int vaccine_needed);
	bool Update();
	void ShowStatus();
	~DoctorsOffice();
};


#endif