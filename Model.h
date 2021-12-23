#ifndef MODEL_H
#define MODEL_H

#include <iostream>

#include "GameObject.h"
#include "Student.h"
#include "DoctorsOffice.h"
#include "ClassRoom.h"
#include "Point2D.h"
#include "View.h"
#include "Virus.h"
using namespace std;

class Model
{
private:
	int time; //simulation time
	GameObject* object_ptrs[10];
	int num_objects;
	Student* student_ptrs[10];
	int num_students;
	DoctorsOffice* office_ptrs[10];
	int num_offices;
	ClassRoom* class_ptrs[10];
	int num_classes;
	Virus* virus_ptrs[10];
	int num_viruses;

public:
	Model();
	~Model();
	Student* GetStudentPtr(int id);
	DoctorsOffice* GetDoctorsOfficePtr(int id);
	ClassRoom* GetClassRoomPtr(int id);
	Virus* GetVirusPtr(int id);
	bool Update();
	void Display(View& view);
	void ShowStatus();
};

#endif