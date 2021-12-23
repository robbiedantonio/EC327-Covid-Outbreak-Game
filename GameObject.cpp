#include "GameObject.h"
using namespace std;

//Constructor 1
GameObject::GameObject(char in_code)
{
	display_code = in_code;
	id_num = 1;
	state = 0;

	cout << "GameObject constructed" << endl;
}

//Constructor 2
GameObject::GameObject(Point2D in_loc, int in_id, char in_code)
{
	display_code = in_code;
	id_num = in_id;
	location = in_loc;
	state = '0';

	cout << "GameObject constructed" << endl;
}



//Return Location 
Point2D GameObject::GetLocation()
{
	return GameObject::location;
}

//Return ID
int GameObject::GetId()
{
	return id_num;
}

//Return state
char GameObject::GetState()
{
	return state;
}

//Return all info
void GameObject::ShowStatus()
{
	cout << display_code << id_num << " at " << location;
}

//Destructor
GameObject::~GameObject()
{
	cout << "GameObject destructed" << endl;
}

void GameObject::DrawSelf(char* ptr)
{
	ptr[0] = display_code;
	ptr[1] = '0' + id_num;
}


