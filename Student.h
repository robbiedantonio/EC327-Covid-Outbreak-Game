#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "GameObject.h"
#include "DoctorsOffice.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "ClassRoom.h"
using namespace std;

enum StudentStates{
	STOPPED = 0,
	MOVING = 1,
	INFECTED = 2,
	AT_DOCTORS = 3,
	IN_CLASS = 4,
	MOVING_TO_DOCTOR = 5,
	MOVING_TO_CLASS = 6,
	STUDYING_IN_CLASS = 7,
	RECOVERING_ANTIBODIES = 8
};

class Student: public GameObject
{
private:
	double speed;
	bool is_at_doctor;
	bool is_in_class;
	int antibodies;
	unsigned int credits;
	double dollars;
	unsigned int assignments_to_buy;
	unsigned int vaccines_to_buy;
	string name;
	DoctorsOffice* current_office;
	ClassRoom* current_class;
	Point2D destination;
	Vector2D delta;

	//Variables I added
	bool is_at_destination;
	unsigned int credits_gained;
	unsigned int antibodies_recovered;	

	bool has_virus;
protected:
	bool UpdateLocation();
	void SetupDestination(Point2D dest);
public:
	Student(); //Default Constructor
	Student(char in_code); //Constructor 1
	Student(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc); //Constructor 2
	void StartMoving(Point2D dest);
	void StartMovingToClass(ClassRoom* classr);
	void StartMovingToDoctor(DoctorsOffice* office);
	void StartLearning(unsigned int num_assignments);
	void StartRecoveringAntibodies(unsigned int num_vaccines);
	void Stop();
	bool IsInfected();
	bool ShouldBeVisible();	
	void ContractVirus(int virulence, bool virus_is_alive); //***************************
	string GetName();
	void ShowStatus();
	bool Update();
	virtual ~Student();

};

double GetRandomAmountOfDollars();



#endif