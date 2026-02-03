/*
    Project 9-1 

    A set class for characters
*/

#include <iostream>
using namespace std;

const int MaxSize = 100;

class Set {
    int len;
    char members[MaxSize]; // An array of chars

    /* The find() function is provate because it 
    is not used outside the Set class. */
    int find(char ch); // find an element

    public:

    // Construct a null set.
    Set() {len = 0;}

    //Return the number of elements in the set.
    int getLength() {return len;}

    void showset(); // display the set
    bool isMember(char ch); // check for membership

    Set operator +(char ch); // add an element
    Set operator -(char ch); // remove an element

    Set operator +(Set ob2); // set union
    Set operator -(Set ob2); // Set difference

    bool operator <(Set ob2); // check for subset
    bool operator >(Set ob2); // check for superset

    Set operator &(Set ob2); // find intersection 
    Set operator |(Set ob2); // find difference
};

/* Return the index of the element
 specified by ch, or -1 if not found*/
 int Set::find(char ch) {
    int i; 

    for (i = 0; i < len; i++) {
        if (members[i] == ch) return i;
    }
    return -1;
 }

 // Show the set
 void Set::showset() {
    cout << "{ ";
    for (int i = 0; i < len; i++) 
        cout << members[i] << " ";

    cout << "}\n";
 }


 /* Return true if ch is a member of the set.
    Return false otherwise. */
bool Set::isMember(char ch) {
    if (find(ch) != -1) return true;
    return false;
}

// Add a unique element to a set
Set Set::operator +(char ch) {
    Set newset;

    if (len == MaxSize) {
        cout << "Set is full.\n";
        return *this; // return existing set
    }

    newset = *this; // duplicate the existing set

    // see if element already exists
    if(find(ch) == -1) { // if not found, then add
        // add new element to new set
        newset.members[newset.len] = ch;
        newset.len++;
    }
    return newset; // return updated set
}

// Remove an element from the set.
Set Set::operator -(char ch) {
    Set newset;
    int i = find(ch); // i will be -1 if element not found

    //copy and compress the remaining elements
    for (int j = 0; j  < len; j ++) 
        if (j != i) newset = newset + members[j];
    return newset;
}

// Set union
Set Set::operator +(Set ob2) {
    Set newset = *this; // copy the first set

    //Add unique elements from second set. 
    for (int i = 0; i < ob2.len; i++) 
        newset = newset + ob2.members[i];

    return newset;
}

// Set difference
Set Set::operator -(Set ob2) 
{
    Set newset = *this; // copy the first set

    // Subtract elements from second set.
    for (int i = 0; i < ob2.len; i++) 
        newset = newset - ob2.members[i];

    return newset; //return updated set
}

bool Set::operator <(Set ob2)
{
    //Set firstset = *this; //copy the first set
    if (len > ob2.len)
        return false;

    for (int i = 0; i < len; i++)
    {
        if (ob2.isMember(members[i]) == 0)
            return false;
    }

    return true;
}

bool Set::operator >(Set ob2)
{
    if (len < ob2.len)
        return false;

    for (int i = 0; i < ob2.len; i++)
    {
        if (this->isMember(ob2.members[i]) == 0)
            return false;
    }
    return true;
}

Set Set::operator &(Set ob2)
{
    Set newset;
    if (len > ob2.len)
    {
        for (int i = 0; i < ob2.len; i++) {
            if (ob2.isMember(members[i]) == 1)
                newset = newset + members[i];
        }
    } else
    {
        for (int i = 0; i < len; i++) {
            if (this->isMember(ob2.members[i]) ==1)
                newset = newset + members[i];
        }

    }
    return newset;
}

Set Set::operator |(Set ob2)
{
    Set newset;
    for (int i = 0; i < ob2.len; i++) {
        if (ob2.isMember(members[i]) == 0)
            newset = newset + ob2.members[i];
    }
    for (int i = 0; i < len; i++) {
        if (this->isMember(ob2.members[i]) == 0)
            newset = newset + members[i];
    }
    return newset;
}

// Demonstrate the Set class.
int main() 
{
    Set s1;
    Set s2;
    Set s3;
    Set s4;

    s1 = s1 + 'A'; s1 = s1 + 'B'; s1 = s1 + 'C';
    s2 = s1 + 'D'; s2 = s2 + 'E';
    
    cout << "Showing Sets s1 and s2.\n"; 
    cout << "s1: ";
    s1.showset();
    cout << "s2: ";
    s2.showset();
    cout << "\n";
    if ((s1 < s2) == true) {
        cout << "s1 is a subset of s2" << "\n";
    } else {
        cout << "s1 is not a subset of s2" << "\n";
    }
    
    if ((s2 > s1) == true) {
        cout << "s2 is a superset of s1" << "\n";
    } else {
        cout << "s2 is not a superset of s1" << "\n";
    }

    cout << "\n";

    s1 = s1 + 'F';

    s3 = (s1 & s2);
    cout << "Showing intersection of Sets: ";
    s3.showset();

    s4 = (s1 | s2);
    cout << "Showing differences of Sets: ";
    s4.showset();
    return 0;
}