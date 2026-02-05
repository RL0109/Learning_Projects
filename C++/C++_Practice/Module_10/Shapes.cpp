/*
    Using polymorphism to generate multiple derived shape classes
*/
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// A class for two dimensional objects
class TwoDShape {
    //private 
    double width;
    double height;
    char name[40];

    public:

        //Constructor for TwoDShape
        TwoDShape(const char *n, double w, double h) {
            width = w;
            height = h;
            strcpy(name, n);
        }

        //Default constructor
        TwoDShape(const char *n) 
        {
            strcpy(name, n);
        }


        void showDim() {
            cout << "Width and height are " << width << " and " << height << "\n";

        }


        //accessor functions
        double getWidth() {return width;}
        double getHeight() { return height;}
        void setWidth(double w) {width = w;}
        void setHeight(double h) {height = h;}
        char* getName() { return name;}

        virtual double area() = 0;

};

// Triangle is derived from TwoDShape
class Triangle : public TwoDShape{
    //private 
    char style[20];
    
    public:
        //Constructor for Triangle
        Triangle(const char *str, double w, double h) : TwoDShape("Triangle",w,h)
        {
            strcpy(style, str);
        }

        double area() 
        {
            return getWidth() * getHeight() /2;
        }

        void showStyle() {
            cout << "Triangle is " << style << "\n";
        }
};

class Circle : public TwoDShape 
{
    //private 
    double radius;
    double PI = 3.14159265358979323846;
    public: 

        Circle (double r) : TwoDShape("Circle") 
        {
            radius = r;
        }

        double area() {
            return PI *(radius * radius); 
        }


};

int main() 
{
    const int arrSize = 2;
    TwoDShape *shapes[arrSize];

    shapes[0] = new Triangle("isosceles", 4.0,4.0);
    shapes[1] = new Circle(4.0);

    for (int i = 0; i < arrSize; i++) 
    {
        cout << "Name of shape: " << shapes[i] -> getName() << "\n"; 
 
        cout << "Area of " << shapes[i] -> getName() << ": " << shapes[i] -> area() << "\n";
    }


}