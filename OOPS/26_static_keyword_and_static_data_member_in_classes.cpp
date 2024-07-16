#include<iostream>
using namespace std;
//static data member:-That variable will share the memory with all the class instances
//static member function:-There is no instance of that class being passed into that method
class xyz
{
    public:
    //here we make static variables 
    static int x,y;
    // xyz():x(1),y(2){}
    void print()
    {
        cout<<this->x<<" "<<this->y<<endl;
        // it also work
        // cout<<x<<" "<<y<<endl;
    }
};
//yha hamne bataya h ki x jo h vo xyz class ka h or y jo h vo bhi xyz class ka h
int xyz::x;
int xyz::y;
int main()
{
    xyz a;
    xyz b;
    //assign values of x and y in obj a
    a.x=5;
    a.y=6;
    //print value of obj a
    a.print();
    //assign values of x and y in obj b
    b.x=10;
    b.y=20;
    //print value of obj b
    //but when again we print the value of a it will change because in obj b we change the static variable value 
    //these share memory with all the class instance
    a.print();
}