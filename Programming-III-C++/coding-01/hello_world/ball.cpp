/*********************
Name: Eric Blanco
Coding 01
Purpose: This file has 2 constructors that use my own setters
and calculates and returns the volume and surface area of a ball
**********************/

#include "ball.h"

Ball::Ball() {
    //own setters used
    setRadius(0);

}

Ball::Ball(int r) {
    //own setter used
    setRadius(r);

}

Ball::~Ball() { //not used
}

double Ball::getVolume() {
	const double PI = 3.14; // created a simple PI for calculations
    return (4 * PI * (radius * radius * radius)) / 3; //formula for volume
}

double Ball::getArea() {
    /*
     * This returns surface area overriding the getArea() of Circle
     * since 2D area makes no sense for a ball
    */
	const double PI = 3.14;
    return 4 * PI * (radius * radius); // formula for surface area
}

