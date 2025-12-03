/*
    Project 5-1
    Version of the Quicksort for sorting ccharacters.
*/

#include <iostream>
#include <cstring>

using namespace std;

void quickSort(char *items, int len);

void qs(char *items, int left, int right);

int main() {

    char str[] = "jfmckldoelazlkper";

    cout << "Original order: " << str << "\n";

    quickSort(str, strlen(str));

    cout << "Sorted Order: " << str << "\n";

}

//Set up a call to the actual sorting function
void quickSort(char *items, int len) 
{
    qs(items, 0, len-1);
}

//A recursive version of Quicksort for sorting characters.
void qs(char *items, int left, int right) 
{
    int i,j;
    char x, y;
    i = left; j = right;
    x = items[(left + right) / 2];

    do {
        while((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > right)) j--;

        if(i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if(left < j) qs(items, left, j);
    if(i < right) qs(items, i, right);

}