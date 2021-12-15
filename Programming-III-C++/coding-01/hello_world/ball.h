/*********************
Name: Eric Blanco
Coding 01
Purpose: Header file that creates the Ball class and the prototypes
for the constructors and methods
**********************/

#ifndef CLASSES_BALL_H
#define CLASSES_BALL_H

#include "circle.h"

class Ball : public Circle {
public:
    Ball();
    Ball(int);
    ~Ball(); //not used

    /*
     * Getters
     */
    double getVolume();
    double getArea();

};

#endif //CLASSES_BALL_H