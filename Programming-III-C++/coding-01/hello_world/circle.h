/*********************
Name: Eric Blanco
Coding 01
Purpose: Creates the Circle class and prototypes for the constructors,
setters, and getters.
**********************/

#ifndef CLASSES_CIRCLE_H
#define CLASSES_CIRCLE_H

class Circle {

    public:
    /*
     * constructors
     * one with no params, one with params (overloading)
     */
    Circle();
    Circle(int);

    //destructor (not used)
    ~Circle();

    /*
     * Getters
     */
    int getRadius();
    double getArea();

    /*
     * Setters
     */
    void setRadius(int);


protected:
    //private variable that defines a circle
    int radius;

};

#endif //CLASSES_CIRCLE_H