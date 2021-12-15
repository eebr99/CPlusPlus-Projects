/*********************
Name: Eric Blanco
Coding 01
Purpose: Creates circles and calculates and returns the area
of the circle. Also sets and getsthe radius needed for the 
calculations.
**********************/

#include "circle.h"

Circle::Circle() {
    //own setters used
    setRadius(0);

}

Circle::Circle(int r) {
    //own setter used
    setRadius(r);

}

Circle::~Circle() { //not used
}

int Circle::getRadius() {
    return radius;
}


double Circle::getArea() {
    const double PI = 3.14; // simple pi created
	return PI * (radius * radius); //formula for area
}

void Circle::setRadius(int r) {
    //protection for the attribute in the setter
    if (r > 0) {
        radius = r;
    } else {
        radius = 0;
    }
}