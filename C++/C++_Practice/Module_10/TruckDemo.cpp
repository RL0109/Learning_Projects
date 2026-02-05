// Create a subclass of Vehicle called Truck

#include <iostream>
using namespace std;

//Declare Vehicle class
class Vehicle {
    //private
    int passengers;
    int fuelcap;
    int mpg;
public:
    Vehicle(int p, int f, int m) {
        passengers = p;
        fuelcap = f;
        mpg = m;
    }

    int range() { return mpg * fuelcap;}

    //Accessor functions
    int getPassengers() {return passengers;}
    int getFuelCap() {return fuelcap;}
    int getMPG() {return mpg;}


};

class Truck : public Vehicle {
    //private 
    int cargocap;
    public:
        Truck(int p, int f, int m, int c) : Vehicle (p,f,m)
        {
            cargocap = c;
        }
    // Accessir function 
    int getCargoCap() {return cargocap; }
};

int main() 
{
    // construct trucks
    Truck semi(2,200,7,44000);
    Truck pickup(3,28,15,2000);
    int dist = 252;

    cout << "Semi can carry " << semi.getCargoCap() << " pounds.\n";
    cout << "It has a range of " << semi.range() << " miles.\n";
    cout << "To go " << dist << " miles semi needs " << dist / semi.getMPG() << " gallons of fuel.\n\n";

    cout << "Pickup can carry " << pickup.getCargoCap() << " pounds.\n";
    cout << "It has a range of " << pickup.range() << " miles.\n";
    cout << "To go " << dist << " miles pickup needs " << dist / pickup.getMPG() << " gallons of fuel.\n\n";

    return 0;

}