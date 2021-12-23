#include "Virus.h"
using namespace std;
    
//default constructor
Virus::Virus() : GameObject('V')
{
	state = IN_ENVIRONMENT;

	name = "Virus";
	virulence = 5;
    resistance = 2;
    variant = false;
    energy = 10;
    is_in_student = false;

    cout << "Virus default constructed" << endl;
}

Virus::Virus(string in_name, double in_virulence, double in_resistance, double in_energy, bool in_variant, int in_id, Point2D in_loc) : GameObject(in_loc, in_id, 'V')
{
	state = IN_ENVIRONMENT;

    virulence = in_virulence;
    resistance = in_resistance;
    variant = in_variant;
    energy = in_energy;
    is_in_student = false;
    name = in_name;

    cout << "Virus Constructed" << endl;
}

//See if student should be infected
void Virus::ShouldBeInfected(Student* s)
{
	Point2D StudentLoc = s->GetLocation();
	if(StudentLoc.x == location.x && StudentLoc.y == location.y)
		infect(s);

}

//Infect a student
void Virus::infect(Student* s)
{
	state = IN_STUDENT;
	is_in_student = true;
	current_student = s;

	s->ContractVirus(virulence, IsAlive());

}

//variant getter
bool Virus::get_variant()
{
	return variant;
}

//virulence getter
double Virus::get_virulence()
{
	return virulence;
}

//resistance getter
double Virus::get_resistance()
{
	return resistance;
}

//energy getter
double Virus::get_energy()
{
	return energy;
}

//is_in_student getter
bool Virus::get_in_student()
{
	return is_in_student;
}

string Virus::GetName()
{
	return name;
}

bool Virus::Update()
{



	switch(state)
	{
		case IN_ENVIRONMENT:
			return false;
		case DEAD:
			return false;
		case IN_STUDENT:
			if(IsAlive() == false)
			{
				state = DEAD;
				return true;
			}

			StudentLoc = current_student->GetLocation();
			location.x = StudentLoc.x;
			location.y = StudentLoc.y;
			energy -= (1 / resistance);
			return false;
		default:
			return false;
	}
}

void Virus::ShowStatus()
{
	cout << name << " status:" << endl;
	GameObject::ShowStatus();
	switch(state)
	{
		case IN_ENVIRONMENT:
			cout << " and alive, ready to infect anyone who lands on " << location << endl;
			break;
		case DEAD:
			cout << ", however this virus is dead and harmless" << endl;
			break;
		case IN_STUDENT:
			cout << ", inside of " << current_student->GetName() << endl;
			break;
	}
	cout << "Energy: " << energy << endl;
	cout << "Resistance: " << resistance << endl;
	cout << "Virulence: " << virulence << endl;
}

bool Virus::IsAlive()
{
	if(energy > 0)
		return true;
	else
	{
		energy = 0;
		return false;
	}
}

bool Virus::ShouldBeVisible()
{
	if(energy > 0)
		return true;
	else
		return false;
}

Virus::~Virus()
{
	cout << "Virus destructed" << endl;
}


