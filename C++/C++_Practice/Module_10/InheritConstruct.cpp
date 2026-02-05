// Create constructor for base class and derived class

#include <iostream>
#include <cstring>
using namespace std;

// A class for two dimensional objects
class TwoDShape {
    //private 
    double width;
    double height;

    public:

        //Constructor for TwoDShape
        TwoDShape(double w, double h) {
            width = w;
            height = h;
        }


        void showDim() {
            cout << "Width and height are " << width << " and " << height << "\n";

        }

        //accessor functions
        double getWidth() {return width;}
        double getHeight() { return height;}
        void setWidth(double w) {width = w;}
        void setHeight(double h) {height = h;}

};

// Triangle is derived from TwoDShape
class Triangle : public TwoDShape{
    //private 
    char style[20];
    
    public:
        //Constructor for Triangle
        Triangle(const char *str, double w, double h) : TwoDShape(w,h)
        {
            // // Initialize base class
            // setWidth(w);
            // setHeight(h);


            // Initialize derived class
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

int main() 
{
    Triangle t1("isosceles", 4.0,4.0);
    Triangle t2("right", 8.0, 12.0);

    cout << "Info for t1:\n";
    t1.showStyle();
    t1.showDim();
    cout << "area is " << t1.area() << "\n";

    cout << "Info for t2:\n";
    t2.showStyle();
    t2.showDim();
    cout << "area is " << t2.area() <<  "\n";

    return 0;
}