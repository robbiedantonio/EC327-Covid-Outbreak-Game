#ifndef VIRUS_H
#define VIRUS_H

#include <iostream>
#include <cstring>
#include "GameObject.h"
#include "Student.h"
#include "Point2D.h"
using namespace std;

enum VirusStates{
    IN_ENVIRONMENT = 0,
    DEAD = 1,
    IN_STUDENT = 2
};

class Virus: public GameObject
{
protected:
    double virulence;
    double resistance;
    bool variant;
    double energy;
    bool is_in_student;
    string name;
    Student* current_student;
    Point2D StudentLoc;
public:
    Virus();
    Virus(string name, double virulence, double resistance, double energy, bool variant, int id, Point2D in_loc);
    ~Virus();
    void ShouldBeInfected(Student* s);
    void infect(Student* s);
    bool get_variant();
    double get_virulence();
    double get_resistance();
    double get_energy();
    string GetName();
    bool get_in_student();
    bool Update();
    void ShowStatus();
    bool IsAlive();
    bool ShouldBeVisible();
};




#endif
