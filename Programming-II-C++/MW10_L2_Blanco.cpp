// Author: Eric Blanco
// Course: COSC 1337 Spring 2020 MW10; Instructor: Thayer
// Assignment: Lab 2
// Topic: This program displays a diamond shape of however many lines the user specifies
// and continues to do so until the user decides to quit.
/*
IPO Chart

INPUT
	num, number of lines the user wants the diamond to be
	any number <= 0 to quit the program
PROCESSING
	bring up the prompt asking how many lines to use, or to quit the program
	if the number entered is > 0:
	using nested loops, use the number specified by the user to start making the diamond
	if the number is <= 0, quit the program 
OUTPUT
	display the prompt asking for number of lines, or option to quit
	display the diamond with as many lines as the user specified
	display the prompt again to continues making diamonds or to quit
*/

#include <iostream>
using namespace std;
int main()
{
  cout << "This program will display a diamond of whatever size you want!" << endl;
  cout << endl;
  
  int n, c, k, space = 1;
  while(true)
  {
    cout<<"Please enter the number of rows desired (0 to quit): ";
  	cin>>n;
  	if(n >= 1)
	  {
	    n = (n/2) + 1;
  		space = n - 1;
  		cout << endl;
 
  		for (k = 1; k<=n; k++)
  		{
    	  for (c = 1; c<=space; c++)
      	    cout<<" ";
 
    	    space--;
 
    	  for (c = 1; c<= 2*k-1; c++)
      	    cout<<"*";
 
    	    cout<<"\n";
  		}
 
  		  space = 1;
 
  		for (k = 1; k<= n - 1; k++)
  		{
    	  for (c = 1; c<= space; c++)
      	    cout<<" ";
 
    	    space++;
 
    	  for (c = 1 ; c<= 2*(n-k)-1; c++)
      	    cout<<"*";
 
    	    cout<<"\n";
  		}
		cout << endl;
  	  }
  	  else
		{
		  cout << "\n";
  	  	  cout << "Goodbye!";
  	  	  break;
  	    }

  }
 return 0; 
}

/*
This program will display a diamond of whatever size you want!

Please enter the number of rows desired (0 to quit): 7

   *
  ***
 *****
*******
 *****
  ***
   *

Please enter the number of rows desired (0 to quit): 5

  *
 ***
*****
 ***
  *

Please enter the number of rows desired (0 to quit): 4

  *
 ***
*****
 ***
  *

Please enter the number of rows desired (0 to quit): 3

 *
***
 *

Please enter the number of rows desired (0 to quit): 1

*

Please enter the number of rows desired (0 to quit): 0

Goodbye!
--------------------------------
Process exited after 21.97 seconds with return value 0
Press any key to continue . . .
*/
