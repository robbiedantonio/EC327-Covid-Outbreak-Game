#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
#include "GameObject.h"
#include "Point2D.h"
using namespace std;

class Building: public GameObject
{
private:
	unsigned int student_count;
public:
	void AddOneStudent();
	void RemoveOneStudent();
	void ShowStatus();
	bool ShouldBeVisible();

	Building(); //Default Constructor
	Building(char in_code, int in_id, Point2D in_loc); //Constructor 1
};



#endif