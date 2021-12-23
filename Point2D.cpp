#include "Point2D.h"
//using namespace std;

//Default constructor
Point2D::Point2D()
{
	x = 0.0;
	y = 0.0;
}

//Constructor 1
Point2D::Point2D(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

//Calculates distance between two Point2Ds
double GetDistanceBetween(Point2D p1, Point2D p2)
{
	return sqrt(pow((p1.x - p2.x),2.0) + pow((p1.y - p2.y), 2.0));
}

//Overloads << operator to output as (x, y) 
ostream& operator << (ostream& out, Point2D p1)
{
	out << "(" << p1.x << ", " << p1.y << ")";
	return out;
}

//Overloads + operator for vector addition
Point2D operator + (Point2D p1, Vector2D v1)
{
	return Point2D(p1.x + v1.x, p1.y + v1.y);
}

//Overloads - operator for creation of a vector from 2 Point2Ds
Vector2D operator - (Point2D p1, Point2D p2)
{
	return Vector2D(p1.x - p2.x, p1.y - p2.y);
}


