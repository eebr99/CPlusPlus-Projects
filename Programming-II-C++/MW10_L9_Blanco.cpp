// Author: Eric Blanco
// Course: COSC 1337 Spring 2020 MW10; Instructor: Thayer
// Assignment: Lab 9
// Topic: This program has 3 sort algorithms and 2 search algorithms.
// The three sort algorithms are selection sort, bubble sort, and
// insertion sort. The two search algorithms are a linear search, 
// and a binary search. The selection sort and linear search, 
// along with the rest of the code, have been provided.
#include <iostream>
#include <iomanip>
#include <random> // needed for Orwell devcpp

using namespace std;

const int TARGET = 123456789;
// TARGET cannot be found. It is larger than any random number
// generated by rand(), as desired to test for worst-case performance.

// array helper functions:
void showArray(int array[], int size, const string &msg="") { // displays every element in array
  cout<<msg;
  for (int i{}; i<size; ++i)
    cout << setw(2) << array[i]; // assumes small numbers
  cout << endl;
}

// Useful to verify that array is really sorted!
bool verifySorted(int array[], int size) {
  // returns true if array is in ascending order, else false.
  for (int i=0; i<(size-1); ++i)
    if (array[i]>array[i+1]) return false;
  return true;
}

// selection sort below, deleted the others that weren't called after seeing how they work
void selectionSort(int[], int, bool);    // as expected for this lab

// my own two sorts below, one bubble and the other insertion
void my_bubble_sort(int[], int, bool);    // changed to my bubble sort
void my_insertion_sort(int[], int, bool);    // changed to my insertion sort

bool linearSearchArray(int [], int, int, int&); // provided
bool my_binary_search(int [], int, int, int&); // changed to my binary search,

const int testSizes[] = {1000, 5000, 10000, 20000, 30000, 40000, 50000, 0};

// This code helps to automate multiple test runs.

// Call this code as many times as desired to test your sort algorithms.
float testSortAlgorithm(void sortAlgorithm(int [], int, bool),
                        int array[], int arraySize, bool verbose=false) {
  // This function is interesting. The first parameter is a "function pointer",
  // It accepts any function that returns a void and has parameters of type: (int [], int, bool)
  // The first parameter (in the caller) can be the name of a function being tested.
  // This reduces redundant code. The same sequence of tests are performed on each
  // sort function. (Our textbook does not mention function pointers.)
  
  // fill array with random, unsorted numbers to be sorted
  for (int index = 0; index < arraySize; index++)
    array[index] = rand();  // initialize array with random values
  int startTime = clock();  // get the start time, in milliseconds
  sortAlgorithm(array, arraySize, verbose);  // ALGORITHM UNDER TEST
  int stopTime = clock();   // get the stop time, in milliseconds
  float duration = stopTime - startTime;
  if (!verifySorted(array, arraySize))
    duration=-duration; // return a negative duration to indicate sort failure
  return duration;
}

// testing linear search
float testLinearSearch(int array[], int arraySize, int retry=1000) {
  bool found = false; // true if TARGET is found in array
  int foundAt = 0;    // index in array where TARGET was found
  int startTime = clock();
  for (int repeat = 0; repeat < retry; ++repeat) // repeat test 1000 times to increase duration
    found = linearSearchArray(array, arraySize, TARGET, foundAt); // ALGORITHM UNDER TEST
  int stopTime = clock();
  float duration = stopTime - startTime;
  return duration/retry; // divide duration by 1000 to get time for single search
}

// testing binary search
float testBinarySearch(int array[], int arraySize, int retry=1000) {
  bool found = false; // true if TARGET is found 
  int foundAt = 0;    // index where TARGET was found
  int startTime = clock();
  for (int repeat = 0; repeat < retry; ++repeat) // test is repeated 1000 times
    found = my_binary_search(array, arraySize, TARGET, foundAt); // ALGORITHM UNDER TEST
  int stopTime = clock();
  float duration = stopTime - startTime;
  return duration/retry;}

void testAlgorithms(int array[], int arraySize, bool verbose=false) {
  // This draws a table of results for each algorithm tested.
  const int AlgorithmNameWidth=16;
  const int TestSizeWidth=10;
  const int DurationWidth=TestSizeWidth;
  cout << setw (AlgorithmNameWidth) << left << "Algorithm";
  for (int testCount=0; testSizes[testCount]; ++testCount)
    cout << setw(TestSizeWidth) << right << testSizes[testCount];
  cout << endl << string(AlgorithmNameWidth, '=');
  for (int testCount=0; testSizes[testCount]; ++testCount)
    cout << setw(DurationWidth) << right << " =======";
    
// Copy and/or reuse this code as desired to test your algorithms.
  cout << endl << setw (AlgorithmNameWidth) << left << "selection sort ";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testSortAlgorithm(selectionSort, array, testSizes[testCount]);
    // In the line above, I am passing the name of the function selectionSort as a parameter into
    // the function testSortAlgorithm. You can do the same thing for your sort algorithms, as long
    // as your sort algorithms return a void and have parameters: (int array[], int size).
  
  // loop to call and test my bubble sort
  cout << endl << setw (AlgorithmNameWidth) << left << "bubble sort ";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testSortAlgorithm(my_bubble_sort, array, testSizes[testCount]);
  
  // loop to call and test my insertion sort
  cout << endl << setw (AlgorithmNameWidth) << left << "insertion sort";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testSortAlgorithm(my_insertion_sort, array, testSizes[testCount]);

  // Here, the provided linear search is tested...
  cout << endl << setw (AlgorithmNameWidth) << left << "linear search ";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testLinearSearch(array, testSizes[testCount]);

  // binary search tested
  cout << endl << setw (AlgorithmNameWidth) << left << "binary search ";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testBinarySearch(array, testSizes[testCount]);
  cout << endl;
}


int main () {
  srand(time(0));  // seed the random number generator only once.

  // When first implementing your algorithm, test it on a very small array.
  const int defaultsmallArray[] = {5, 7, 2, 8, 9, 1}; // for testing purposes
  const int SMALLSIZE = sizeof(defaultsmallArray)/sizeof(defaultsmallArray[0]);
  int smallArray[SMALLSIZE] {}; // for testing purposes, resort several times
 
  cout << "Test sorting algorithms on small array:\n\n";
  for (int i{}; i<SMALLSIZE; ++i) smallArray[i] = defaultsmallArray[i]; // initialize smallArray
  showArray(smallArray, SMALLSIZE, "Selection sort start: smallArray is: ");
  selectionSort(smallArray, SMALLSIZE, true); // true means to show details
  showArray(smallArray, SMALLSIZE, "Selection sort stop:  smallArray is: ");
  cout << ((verifySorted(smallArray, SMALLSIZE)) ?
    "verified: smallArray is sorted.\n" :
    "Ooops!!!: smallArray is NOT sorted.\n");

  // When first implementing your algorithm, test it
  // on a very small array. Test your new sorts on smallArray below.
  for (int i{}; i<SMALLSIZE; ++i) smallArray[i] = defaultsmallArray[i]; // initialize smallArray
  showArray(smallArray, SMALLSIZE, "\nBubble sort start: smallArray is: ");
  my_bubble_sort(smallArray, SMALLSIZE, true); // true means to show details
  showArray(smallArray, SMALLSIZE, "Bubble sort stop:  smallArray is: ");
  cout << ((verifySorted(smallArray, SMALLSIZE)) ?
    "verified: smallArray is sorted.\n" :
    "Ooops!!!: smallArray is NOT sorted.\n");

  for (int i{}; i<SMALLSIZE; ++i) smallArray[i] = defaultsmallArray[i]; // initialize smallArray
  showArray(smallArray, SMALLSIZE, "\nInsertion sort start: smallArray is: ");
  my_insertion_sort(smallArray, SMALLSIZE, true); // true means to show details
  showArray(smallArray, SMALLSIZE, "Insertion sort stop:  smallArray is: ");
  cout << ((verifySorted(smallArray, SMALLSIZE)) ?
    "verified: smallArray is sorted.\n" :
    "Ooops!!!: smallArray is NOT sorted.\n");

  const int BIGSIZE = 50000;
  int bigArray[BIGSIZE];
  float duration = 0.0; // time in milliseconds

  // Startup code performs a single test run using the full size of bigArray
  duration = testSortAlgorithm(selectionSort, bigArray, BIGSIZE);
  cout << fixed << setprecision(2);
  cout << "\nSelection sort on bigArray took: "
       << setw(7) << duration << " milliseconds." << endl;

  duration = testSortAlgorithm(my_bubble_sort, bigArray, BIGSIZE);
  cout << fixed << setprecision(2);
  cout << "Bubble sort on bigArray took:    "
       << setw(7) << duration << " milliseconds." << endl;

  duration = testSortAlgorithm(my_insertion_sort, bigArray, BIGSIZE);
  cout << fixed << setprecision(2);
  cout << "Insertion sort on bigArray took: "
       << setw(7) << duration << " milliseconds." << endl;
       
  duration = testLinearSearch(bigArray, BIGSIZE);
  cout << "Linear search  of bigArray took: "
       << setw(7) << duration << " milliseconds.\n";

  duration = testBinarySearch(bigArray, BIGSIZE);
  cout << "Binary search  of bigArray took: "
       << setw(7) << duration << " milliseconds.\n\n";

  //Lengths of 1000, 5000, 10000, 20000, 30000,
  // 40000, 50000 are tested.
  testAlgorithms(bigArray, BIGSIZE);
  cout << endl;

  return 0;
} // end of main

// creation of a new sort, this will be a bubble sort
void my_bubble_sort(int array[], int size, bool sorted=false) {
	for (int max_items = size - 1; max_items > 0; max_items--){  // the outer loop contols
	// how many times we loop	as made known by variable	max items
		for (int location = 0; location < max_items; location++){
			// inner loop controls the array varaibles and compares them to each other 
			// to decide whether to swap or not
			if (array[location] > array[location + 1]){
				int temp = array[location];
				array[location] = array[location + 1];
				array[location + 1] = temp;
				if(sorted){ // to show the swapping to the user
					cout << array[location] << " has been swapped with " << array[location + 1] << endl;
				}
			}	
		}
	}
}

// creation of another sort, this one being an insertion sort
void my_insertion_sort(int array[], int size, bool sorted=false) {
  int position{}, temp{};  // position is the current place of comparison, and temp
  // is where a value is held temporarily for the swapping if it takes place
  for(int location = 0; location < size; location++){
  	position = location;
  	while( position > 0 and array[position] < array[position-1]){
  		// while loop instead of for loop, as was done for the previous sorts
  		temp = array[position];
  		array[position] = array[position - 1];
  		array[position - 1] = temp;
  		if (sorted){ // to show the swapping going on to the user
  			cout << array[position] << " has been swapped with " << array[position - 1] << endl;
			}
  		position--;
		}
	}
}

// Your new search algorithm cannot be linear search, which is provided here.
bool linearSearchArray(int array[], int size, int target, int &position) {
  for (int i = 0; i < size; ++i)
    if (array[i] == target) // found it!
      {position=i; return true;}
  position = -1;
  return false;
}

bool my_binary_search(int array[], int size, int target, int &position) {
  int first{0}, last{size - 1}, middle{}, place {-1};
  bool found = false;
  
  while (!found and first <= last){
  	middle = (first + last) / 2;  //calculate the mid point
  	if (array[middle] == target){  //if value is found at mid
			found = true;
			position = middle;
			return true;
		}
		else if (array[middle] > target){  //if value is in lower half
			last = middle - 1;
			return true;
		}
		else{
			first = middle + 1;
			return true;        //if value is in upper half
		}
	return false;
	}
}

// This selection sort displays details of its operation for each pass.
void selectionSort(int array[], int size, bool verbose=false) {
  int minIndexSoFar = 0, minValueSoFar{array[0]};
  for (int unsortedIndex = 0; unsortedIndex < (size - 1); unsortedIndex++) {
    // The outer loop looks at unsorted data, which is initially the whole array.
    // Gradually, a smaller and smaller portion of the array remains unsorted.
    minIndexSoFar = unsortedIndex;
    minValueSoFar = array[unsortedIndex];
    for (int seekMinIndex = unsortedIndex + 1; seekMinIndex < size; seekMinIndex++) {
      // the inner loop seeks the smallest value possible in the
      // remaining unsorted portion of the array.
      if (array[seekMinIndex] < minValueSoFar) {
        // found a smaller value than I had before, save it for now
        if (verbose)
          cout << "  prev min value: " << minValueSoFar << " at offset: " << minIndexSoFar;
        minValueSoFar = array[seekMinIndex];
        minIndexSoFar = seekMinIndex;
        if (verbose)
          cout << "; yet smaller value: " << minValueSoFar << " at offset: " << minIndexSoFar << endl;
      }
    }
    // The smallest value in the unsorted portion of the array has been found.
    // Replace the older minimum value, which wasn't really the actual minimum
    // value, with the new, real minimum value which was just found.
    array[minIndexSoFar] = array[unsortedIndex];
    array[unsortedIndex] = minValueSoFar;
    if (verbose) {
      cout << "  swap prev min value: " << array[minIndexSoFar]
          << " with new min value: " << array[unsortedIndex] << endl;
     cout << "After pass " << unsortedIndex << " the array is: ";
     showArray(array, size);
     cout << endl;
    }

    // ... continue seeking the minimum value in the smaller remaining portion.
  }
}

/*
Test sorting algorithms on small array:

Selection sort start: smallArray is:  5 7 2 8 9 1
  prev min value: 5 at offset: 0; yet smaller value: 2 at offset: 2
  prev min value: 2 at offset: 2; yet smaller value: 1 at offset: 5
  swap prev min value: 5 with new min value: 1
After pass 0 the array is:  1 7 2 8 9 5

  prev min value: 7 at offset: 1; yet smaller value: 2 at offset: 2
  swap prev min value: 7 with new min value: 2
After pass 1 the array is:  1 2 7 8 9 5

  prev min value: 7 at offset: 2; yet smaller value: 5 at offset: 5
  swap prev min value: 7 with new min value: 5
After pass 2 the array is:  1 2 5 8 9 7

  prev min value: 8 at offset: 3; yet smaller value: 7 at offset: 5
  swap prev min value: 8 with new min value: 7
After pass 3 the array is:  1 2 5 7 9 8

  prev min value: 9 at offset: 4; yet smaller value: 8 at offset: 5
  swap prev min value: 9 with new min value: 8
After pass 4 the array is:  1 2 5 7 8 9

Selection sort stop:  smallArray is:  1 2 5 7 8 9
verified: smallArray is sorted.

Bubble sort start: smallArray is:  5 7 2 8 9 1
2 has been swapped with 7
1 has been swapped with 9
2 has been swapped with 5
1 has been swapped with 8
1 has been swapped with 7
1 has been swapped with 5
1 has been swapped with 2
Bubble sort stop:  smallArray is:  1 2 5 7 8 9
verified: smallArray is sorted.

Insertion sort start: smallArray is:  5 7 2 8 9 1
7 has been swapped with 2
5 has been swapped with 2
9 has been swapped with 1
8 has been swapped with 1
7 has been swapped with 1
5 has been swapped with 1
2 has been swapped with 1
Insertion sort stop:  smallArray is:  1 2 5 7 8 9
verified: smallArray is sorted.

Selection sort on bigArray took: 2883.00 milliseconds.
Bubble sort on bigArray took:    6826.00 milliseconds.
Insertion sort on bigArray took: 2524.00 milliseconds.
Linear search  of bigArray took:    0.11 milliseconds.
Binary search  of bigArray took:    0.00 milliseconds.

Algorithm             1000      5000     10000     20000     30000     40000     50000
================   =======   =======   =======   =======   =======   =======   =======
selection sort        0.00     28.00    112.00    436.00    983.00   1738.00   2717.00
bubble sort           4.00    100.00    263.00   1052.00   2432.00   4371.00   6794.00
insertion sort        0.00     28.00    152.00    396.00    892.00   1590.00   2512.00
linear search         0.00      0.01      0.02      0.09      0.06      0.09      0.11
binary search         0.00      0.00      0.00      0.00      0.00      0.00      0.00


--------------------------------
Process exited after 39.83 seconds with return value 0
Press any key to continue . . .
*/
