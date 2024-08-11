#include<iostream>
using namespace std;
//static data member:-That variable will share the memory with all the class instances
//static member function:-There is no instance of that class being passed into that method
//A static member variable is a variable that is shared among all instances of a class. It is declared within a class, 
//but it exists independently of any object instances of the class.
//Shared Across All Instances:
//Only one copy of the static member variable exists, regardless of how many objects of the class are created.
//All instances of the class share the same static variable.
//Class-Level Variable:
//The static member variable is associated with the class itself, not with any specific object.
//It can be accessed using the class name, without creating an Storage Allocation:
//A static member variable must be defined outside the class
//Declaration vs. Definition: 
//Inside the class, the static member variable is only declared but not defined. A declaration tells the 
//compiler that a variable exists and specifies its type, but it does not allocate storage for the variable.
//The actual storage (memory allocation) for the static variable is done when the variable is defined. This definition is done outside 
//the class, typically in a .cpp file. Without this external definition, the linker would not know where to place the variable in memory, leading to a linking error.object.
class ClassA
{
    public:
    //here we make static variables 
    static int staticVariable,staticVariable1;
    // ClassA():staticVariable(1),staticVariable(2){}
    static void staticFunction() 
    {  // Static member function
        cout<<"Static function called. StaticVariable= "<<staticVariable<<endl;
    }
    void print()
    {
        cout<<this->staticVariable<<" "<<this->staticVariable1<<endl;
        // it also work
        // cout<<staticVariable<<" "<<staticVariable1<<endl;
    }
};

//here we define our static variable ans allocate memory to it
//yha hamne bataya h ki staticVariable jo h vo ClassA class ka h or staticVariable1 jo h vo bhi ClassA class ka h
int ClassA::staticVariable;
int ClassA::staticVariable1=10;

class ClassB {
public:
    void display() {
        //Access static variable from ClassA
        cout<<"Accessing ClassA's staticVariable:"<<ClassA::staticVariable<<endl;
        // Call static function from ClassA
        ClassA::staticFunction();
    }
};
int main()
{
    ClassB objB;
    objB.display();  // This will access and use ClassA's static members
    ClassA a;
    ClassA b;
    //assign values of staticVariable and staticVariable1 in obj a
    a.staticVariable=5;
    a.staticVariable1=6;
    //print value of obj a
    a.print();
    //assign values of staticVariable and staticVariable1 in obj b
    b.staticVariable=10;
    b.staticVariable1=20;
    //print value of obj b
    //but when again we print the value of a it will change because in obj b we change the static variable value 
    //these share memory with all the class instance
    a.print();
}
