/*********************
Name: Eric Blanco
Coding 01
Purpose: Functions to display the information about the circle
and the ball that are sent to it.
**********************/

#include "functions.h"
//pointer usage
void displayCircle(Circle *myCircle){

    std::cout << myCircle->getRadius() << std::endl;
    std::cout << myCircle->getArea() << std::endl;
    std::cout << std::endl;

}

void displayBall(Ball *myBall){

    std::cout << myBall->getRadius() << std::endl;
    std::cout << myBall->getVolume() << std::endl;
    std::cout << myBall->getArea() << std::endl;
    std::cout << std::endl;

}