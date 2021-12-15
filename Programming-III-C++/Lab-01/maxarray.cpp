//Eric Blanco

#include <iostream>

template<class ItemType>
ItemType maxArray(ItemType myArray[], int left, int right){
    if(right - left == 1)
    //this means there is only one item in the array, which would make it the biggest
        return myArray[left];

    else if(right - left >= 1){
        int midpoint = (left + right) / 2;
        int maxLeft = maxArray(myArray, left, midpoint); //recursion
        int maxRight = maxArray(myArray, midpoint, right); // recursion
        return maxLeft > maxRight ? maxLeft : maxRight;
    }

}

int main(){
    //hard coded the items in array and the size
    int intArray[] = {6,45,17,84,2,26,77}; //contains 7 items
    char charArray[] = {'g', 't', 'j', 'x', 'a'}; //contains 5 items
    std::cout << "\nHere is an array filled with ints: ";
    for(int count = 0; count < 7; count++){
        std::cout << intArray[count];
        std::cout << ",";
    }
    std::cout << "\nbiggest int in the array is: " << maxArray(intArray, 0, 6);
    // 0-6 for location in array
    std::cout << std::endl;
    
    std::cout << "\nThis is an array filled with chars: ";
    for(int count = 0; count < 5; count++){
        std::cout << charArray[count];
        std::cout << ",";
    }
    std::cout << "\nbiggest char in the array is: " << maxArray(charArray, 0, 4);
    // 0-4 for location
    return 0;
}