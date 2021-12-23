#include "GameCommand.h"
using namespace std;

void DoMoveCommand(Model& model, int student_id, Point2D p1)
{
	if(model.GetStudentPtr(student_id) != 0)
	{
		model.GetStudentPtr(student_id)->StartMoving(p1);
		cout << "Moving " << model.GetStudentPtr(student_id)->GetName() << " to " << p1 << endl;
	}
	else
		cout << "Error: Please enter a valid command!" << endl;
}


void DoMoveToDoctorCommand(Model& model, int student_id, int office_id)
{
	if(model.GetStudentPtr(student_id) != 0 && model.GetDoctorsOfficePtr(office_id) != 0)
	{
		model.GetStudentPtr(student_id)->StartMovingToDoctor(model.GetDoctorsOfficePtr(office_id));
		cout << "Moving " << model.GetStudentPtr(student_id)->GetName() << " to doctors office " << office_id << endl;
		model.Update();
	}
	else
		cout << "Error: Please enter a valid command!" << endl;
}

void DoMoveToClassCommand(Model& model, int student_id, int class_id)
{
	if(model.GetStudentPtr(student_id) != 0 && model.GetClassRoomPtr(class_id) != 0)
	{
		model.GetStudentPtr(student_id)->StartMovingToClass(model.GetClassRoomPtr(class_id));
		cout << "Moving " << model.GetStudentPtr(student_id)->GetName() << " to class " << class_id << endl;
		model.Update();
	}
	else 
		cout << "Error: Please enter a valid command!" << endl;
}

void DoStopCommand(Model& model, int student_id)
{
	if(model.GetStudentPtr(student_id) != 0)
	{
		model.GetStudentPtr(student_id)->Stop();
		cout << "Stopping " << model.GetStudentPtr(student_id)->GetName() << endl;
	}
	else
		cout <<"Error: Please enter a valid command!" << endl;
}

void DoLearningCommand(Model& model, int student_id, unsigned int assignments)
{
	if(model.GetStudentPtr(student_id) != 0)
	{
		model.GetStudentPtr(student_id)->StartLearning(assignments);
		cout << "Teaching " << model.GetStudentPtr(student_id)->GetName() << endl;
	}
	else
		cout << "Error: Please enter a valid command!" << endl;
}

void DoRecoverInOfficeCommand(Model& model, int student_id, unsigned int vaccine_needs)
{
	if(model.GetStudentPtr(student_id) != 0)
	{
		model.GetStudentPtr(student_id)->StartRecoveringAntibodies(vaccine_needs);
		cout << "Recovering " << model.GetStudentPtr(student_id)->GetName() << "'s antibodies" << endl;
	}
	else
		cout << "Error: Please enter a valid command!" << endl;
}

void DoGoCommand(Model& model, View& view)
{	
	model.ShowStatus();	
	model.Update();
	model.Display(view);

	cout << "Advancing one tick." << endl;
}

void DoRunCommand(Model& model, View& view)
{
	model.ShowStatus();
	for(int i=0; i<5; i++)
	{
		bool updateVar = model.Update();
		if(updateVar)
			break;
	}
	model.Display(view);
}







