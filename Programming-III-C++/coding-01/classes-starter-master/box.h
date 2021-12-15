/*
 * 
 * 
 * 
 * 
 */

/*********************
Name: Eric Blanco
Coding 01
Purpose: 1-3 sentences about your program.
**********************/

#ifndef CLASSES_BOX_H
#define CLASSES_BOX_H

#include "rectangle.h"

class Box : public Rectangle {
public:
    Box();
    Box(int, int, int);
    ~Box();

    /*
     * Getters
     */
    int getDepth();
    int getVolume();
    int getArea();

    /*
     * Setters
     */
    void setDepth(int);

private:
    //private variables that define a box (from a rectangle)
    int depth;


};

#endif //CLASSES_BOX_H