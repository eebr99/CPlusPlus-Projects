/*********************
Name: Eric Blanco
Coding 01
Purpose: This file, main.cpp, includes only main.h.
This file creates 2 circles and 2 spheres, and displays the
radius, area of the circles. It also display the radius, surface
volume, and surface area of the ball.
**********************/

#include "main.h"

int main(int argc, char** argv) {
    //creates a circle object with no parameters
    Circle myCircle1;
    //creates a circle object with radius 2
    Circle myCircle2(2);

    //creates a ball object with no parameters
    Ball myBall1;
    //creates a ball object with radius 2
    Ball myBall2(2);

    //simple number used to easily check output

    //passing objects by reference
    displayCircle(&myCircle1);
    displayCircle(&myCircle2);

    displayBall(&myBall1);
    displayBall(&myBall2);

    return 0;

    return 0;
}
