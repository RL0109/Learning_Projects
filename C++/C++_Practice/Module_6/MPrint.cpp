/*
    Project 6-1 -- Updated for mastery check

    Create overloaded print() and println() functions
    that display various types of data
*/
#include <iostream>
using namespace std; // Only use in practice cases

// These output a newline
void println(bool b, int indent = 0);
void println(int i, int indent = 0);
void println(long i, int indent = 0);
void println(char ch, int indent = 0);
void println(const char *str, int indent = 0);
void println(double d, int indent = 0);

// These functions do not output a newline
void print(bool b, int indent = 0);
void print(int i, int indent = 0);
void print(long i, int indent = 0);
void print(char ch, int indent = 0);
void print(const char *str, int indent = 0);
void print(double d, int indent = 0);

int main() {

    println(true,10);
    println(10);
    println("This is a test",10);
    println('x');
    println(99L,10);
    println(123.23);

    print("Here are some values: ");
    print(false);
    print(' ',10);
    print(88);
    print(' ');
    print(100000L);
    print(' ',10);
    print(100.01);
    println(" Done! ");

    return 0;
}

// Here are the println functions

void println(bool b, int indent)
{
    if(indent) {
        for (int i = 0; i != indent; i++) {
            std::cout << ' ';
        }
    }
    if(b) cout << "true\n";
    else cout << "false\n";
}

void println(int i, int indent)
{   
    if(indent) {
        for (int i = 0; i != indent; i++) {
            std::cout << ' ';
        }
    }
    cout << i << "\n";
}

void println(long i, int indent) 
{
    if(indent) {
        for (int i = 0; i != indent; i++) {
            std::cout << ' ';
        }
    }
    cout << i << "\n";
}

void println(char ch, int indent) 
{
    if(indent) {
        for (int i = 0; i != indent; i++) {
            std::cout << ' ';
        }
    }
    cout << ch << "\n";
}

void println(const char *str, int indent) 
{
    if(indent) {
        for (int i = 0; i != indent; i++) {
            std::cout << ' ';
        }
    }
    cout << str << "\n";
}

void println(double d, int indent)
{
    if(indent) {
        for (int i = 0; i != indent; i++) {
            std::cout << ' ';
        }
    }
    cout << d << "\n";
}

// Here are print functions

void print(bool b, int indent) 
{
    if(indent) {
        for (int i = 0; i != indent; i++) {
            std::cout << ' ';
        }
    }
    if(b) cout << "true";
    else cout << "false";
}

void print(int i, int indent) 
{   
    if(indent) {
        for (int i = 0; i != indent; i++) {
            std::cout << ' ';
        }
    }
    cout << i;
}

void print (long i, int indent) 
{
    if(indent) {
        for (int i = 0; i != indent; i++) {
            std::cout << ' ';
        }
    }
    cout << i;
}

void print (char ch, int indent) 
{
    if(indent) {
        for (int i = 0; i != indent; i++) {
            std::cout << ' ';
        }
    }
    cout << ch;
}

void print (const char *str, int indent) 
{
    if(indent) {
        for (int i = 0; i != indent; i++) {
            std::cout << ' ';
        }
    }
    cout << str;
}

void print (double d, int indent)
{
    if(indent) {
        for (int i = 0; i != indent; i++) {
            std::cout << ' ';
        }
    }
    cout << d;
}