#include "Model.h"
using namespace std;

//Default Constructor
Model::Model()
{
	time = 0;
	
	//Create Student Objects
	Point2D LocationS1(5,1);
	Student* S1 = new Student("Homer", 1, 'S', 2, LocationS1); //ID is 1, speed is 2
	object_ptrs[0] = S1;
	student_ptrs[0] = S1;


	Point2D LocationS2(10,1);
	Student* S2 = new Student("Marge", 2, 'S', 1, LocationS2); //ID is 2, speed is 1
	object_ptrs[1] = S2;
	student_ptrs[1] = S2;

	//Create DoctorsOffice Objects
	Point2D LocationD1(1, 20);
	DoctorsOffice* D1 = new DoctorsOffice(1, 1, 100, LocationD1); //ID is 1, Vax cost 1, Vax capacity 100
	object_ptrs[2] = D1;
	office_ptrs[0] = D1;

	Point2D LocationD2(10, 20);
	DoctorsOffice* D2 = new DoctorsOffice(2, 2, 200, LocationD2); // ID is 2, Vax cost 2, Vax capacity 200
	object_ptrs[3] = D2;
	office_ptrs[1] = D2;

	//Create ClassRoom Objects
	Point2D LocationC1(0, 0);
	ClassRoom* C1 = new ClassRoom(10, 1, 2, 3, 1, LocationC1); //Assignments 10, antibody cost 1, dollar cost 2, credit 3, ID 1
	object_ptrs[4] = C1;
	class_ptrs[0] = C1;

	Point2D LocationG2(5, 5);
	ClassRoom* G2 = new ClassRoom(20, 5, 7.5, 4, 2, LocationG2); //Assignments 20, antibody cost 5, dollar cost 7.5, credit 4, ID 2
	object_ptrs[5] = G2;
	class_ptrs[1] = G2;

	//Create Virus Objects
	Point2D LocationV1(12, 14);
	Virus* V1 = new Virus("Cooties", 5, 3, 5, false, 1, LocationV1); //Virulence 5, Resistance 3, Energy 5, Variant false, ID 1
	object_ptrs[6] = V1;
	virus_ptrs[0] = V1;

	Point2D LocationV2(4, 8);
	Virus* V2 = new Virus("Influenza", 1, 2, 30, false, 2, LocationV2); //Virulence 1, Resistance 2, Energy 5, Variant false, ID 2
	object_ptrs[7] = V2;
	virus_ptrs[1] = V2;


	//Set num of each object
	num_objects = 8;
	num_students = 2;
	num_offices = 2;
	num_classes = 2;
	num_viruses = 2;

	cout << "Model default constructed" << endl;
}


//Model Destructor
Model::~Model()
{
	//Delete Objects
	for(int i=0; i<num_objects;i++)
	{
		delete object_ptrs[i];
	}

	cout << "Model Destructed" << endl;
}



//Student pointer getter
Student* Model::GetStudentPtr(int id)
{
	for(int i=0; i<num_students; i++)
	{
		if(student_ptrs[i]->GetId() == id)
			return student_ptrs[i];
	}
	return 0;
}

//Doctors office pointer getter
DoctorsOffice* Model::GetDoctorsOfficePtr(int id)
{
	for(int i=0; i<num_offices; i++)
	{
		if(office_ptrs[i]->GetId() == id)
			return office_ptrs[i];
	}
	return 0;
}

//ClassRoom pointer getter
ClassRoom* Model::GetClassRoomPtr(int id)
{
	for(int i=0; i<num_classes; i++)
	{
		if(class_ptrs[i]->GetId() == id)
			return class_ptrs[i];
	}
	return 0;
}

//Virus pointer getter
Virus* Model::GetVirusPtr(int id)
{
	for(int i=0; i<num_viruses; i++)
	{
		if(virus_ptrs[i]->GetId() == id)
			return virus_ptrs[i];
	}
	return 0;
}

//Calls update functions from objects & tells if game over
bool Model::Update()
{
	time++;

	for(int i=0; i<num_viruses;i++)
	{
		for(int j=0; j<num_students; j++)
		{
			virus_ptrs[i]->ShouldBeInfected(student_ptrs[j]);
		}	
	}

	for(int i=0; i<num_objects; i++)
	{

		if(object_ptrs[i] == class_ptrs[0] || object_ptrs[i] == class_ptrs[1])
		{
			if(class_ptrs[0]->passed() && class_ptrs[1]->passed())
			{
				cout << "GAME OVER: You win! All assignments done!" << endl;
				return true;
			}
		}
		else if(object_ptrs[i] == student_ptrs[0] || object_ptrs[i] == student_ptrs[1])
		{
			if(student_ptrs[0]->IsInfected() && student_ptrs[1]->IsInfected())
			{
				cout << "GAME OVER:You lose! All of your Students are infected!" << endl;
				return true;
			}
		}		
		object_ptrs[i]->Update();

	}
	return false;
}


//Shows status
void Model::ShowStatus()
{
	cout << "Time: " << time << endl; 
	for(int i=0; i<num_objects; i++)
	{
		object_ptrs[i]->ShowStatus();
		cout << endl;
	}
}

void Model::Display(View& view)
{
	view.Clear();
	for(int i=0; i<num_objects; i++)
	{
		view.Plot(object_ptrs[i]);
	}

/*
	view.Plot(model.GetStudentPtr(1));
	view.Plot(model.GetStudentPtr(2));
	view.Plot(model.GetClassRoomPtr(1));
	view.Plot(model.GetClassRoomPtr(2));
	view.Plot(model.GetDoctorsOfficePtr(1));
	view.Plot(model.GetDoctorsOfficePtr(2));*/
	view.Draw();
}











