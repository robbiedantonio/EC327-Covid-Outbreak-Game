#include "Vector2D.h"
using namespace std;

//Default constructor
Vector2D::Vector2D()
{
	x = 0.0;
	y = 0.0;
}

//Constructor 1
Vector2D::Vector2D(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

//Overload * operator to return vector
Vector2D operator * (Vector2D v1, double d)
{
	return Vector2D(v1.x * d, v1.y *d);
}

//Overload / operator to return vector
Vector2D operator / (Vector2D v1, double d)
{
	if(d == 0)
		return v1;
	else
		return Vector2D(v1.x / d, v1.y / d);
}

//Overload << operator to output as <x, y>
ostream& operator << (ostream& out, Vector2D v1)
{
	out << "<" << v1.x << ", " << v1.y << ">";
	return out;
}