/*
 * This is a simple application to demonstrate classes and objects in C++.
 * Note the header structure and files for all cpp and h files.
 * The only thing included in main.cpp is it's main.h file.
 * This file, main.cpp, includes only main.h.
 */

/*********************
Name: Eric Blanco
Coding 01
Purpose: 1-3 sentences about your program.
**********************/

#include "main.h"

int main(int argc, char** argv) {
    //creates a rectangle object with no parameters
    Rectangle myRectangle1;
    //creates a rectangle object with height and width 5x4
    Rectangle myRectangle2(5, 4);

    //creates a box object with no parameters
    Box myBox1;
    //creates a box object with height, width, depth 5x4x6
    Box myBox2(5, 4, 6);


    //examples of passing objects by reference, yes sir.
    displayRectangle(&myRectangle1);
    displayRectangle(&myRectangle2);

    displayBox(&myBox1);
    displayBox(&myBox2);

    return 0;

    return 0;
}
