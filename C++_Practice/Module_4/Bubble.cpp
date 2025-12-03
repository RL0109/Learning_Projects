/*
    Project 4-1
    Demonstrate bubble sort
*/
#include <iostream>
#include <cstdlib>

int main() {
    int nums[10];
    int a,b,t;
    int size;

    size = 10; // number of elements to sort

    //give array some random initial values
    for (t = 0; t < size; t++) {
        nums[t] = rand();
    }

    //display original array
    std::cout << "Original array is:\n";
    for (t = 0; t <size; t++) {
        std::cout << nums[t] << ' ';

    }

    std::cout << '\n';

    // This is the bubble sort
    for (a=1; a<size; a++)
        for (b = size -1; b >= a; b--) {
            if(nums[b-1] > nums[b]) {
                t = nums[b-1];
                nums[b-1] = nums[b];
                nums[b] = t;
            }

        }

    // display sorted array 
    std::cout << "\nSorted array is:\n";
    for(t=0; t<size; t++) {
        std::cout << nums[t] << ' ';
    }

    return 0;
}