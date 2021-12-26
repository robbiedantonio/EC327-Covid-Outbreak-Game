# EC327-Covid-Outbreak-Game
Programming Assignment from EC327: Introduction to Software Engineering

Gameplay:
The overall goal of this game is to graduate. This is done by completeing all of the assignments in each classroom.
Students lose antibodies with each step they take. There are also viruses that accelerate this depletion.
There are doctors offices where students can get vaccinated to recover antibodies.

Commands:
m ID x y 
  - "move": command Student ID to move to location (x, y)
d ID1 ID2 
  - "move towards a DoctorsOffice": command Student ID1 to start heading to DoctorsOffice ID2.
c ID1 ID2 
  - “movetowardsaClassroom”: command Student ID1 tostart heading towards ClassRoom ID2.
s ID 
  - "stop": command Student ID to stop doing whatever it is doing
v ID vaccine_amount 
  - “buy vaccines”: command Student ID to buy vaccine_amount of vaccines at a Doctors Office.
a ID assignment_amount 
  - “complete assignment_amount assignments at a ClassRoom”: command Student ID to complete assignment_amount of training units at a ClassRoom.
g 
  - "go": advance one-time step by updating each object once.
r 
  - "run": advance one time step and update each object, and repeat until either something major changes for an object, or 5 time steps have been done.
q 
  - "quit": terminate the program
