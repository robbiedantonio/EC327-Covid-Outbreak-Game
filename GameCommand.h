#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

#include <iostream>
#include "Model.h"
#include "Point2D.h"
#include "Student.h"
#include "View.h"

using namespace std;

void DoMoveCommand(Model& model, int student_id, Point2D p1);
void DoMoveToDoctorCommand(Model& model, int student_id, int office_id);
void DoMoveToClassCommand(Model& model, int student_id, int class_id);
void DoStopCommand(Model& model, int student_id);
void DoLearningCommand(Model& model, int student_id, unsigned int assignments);
void DoRecoverInOfficeCommand(Model& model, int student_id, unsigned int vaccine_needs);
void DoGoCommand(Model& model, View& view);
void DoRunCommand(Model& model, View& view);

#endif