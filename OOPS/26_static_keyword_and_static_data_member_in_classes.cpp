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

//here we define our static variable and allocate memory to it
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
#include<iostream>
using namespace std;
class Counter 
{
public:
    static int count; // Static member variable

    Counter() 
    {
        count++;
    }
};
// Initialize the static member variable
int Counter::count=0;

int main() 
{
    Counter c1;
    Counter c2;
    Counter c3;

    cout<<"Number of Counter instances: "<<Counter::count<<endl; // Output: 3
    return 0;
}
#include<iostream>
using namespace std;
class Math 
{
public:
    static int add(int a, int b) 
    { // Static member function
        return a+b;
    }
};

int main() 
{
    int sum=Math::add(5,3); // Calling static function
    cout<<"Sum: "<<sum<<endl; // Output: 8
    return 0;
}
#include<iostream>
using namespace std;
class Sample 
{
public:
    void staticFunction() 
    {
        static int count=0; // Static variable
        count++;
        cout<<"Function called "<<count<<" times."<<endl;
    }
};

int main() 
{
    Sample s;
    s.staticFunction(); // Output: Function called 1 times.
    s.staticFunction(); // Output: Function called 2 times.
    s.staticFunction(); // Output: Function called 3 times.
    return 0;
}
#include<iostream>
using namespace std;
class Calculator 
{
public:
    static int multiply(int a,int b) 
    {
        return a*b;
    }
};

int main() 
{
    int product=Calculator::multiply(4,5); // Calling static function
    cout<<"Product: "<<product<<endl; // Output: 20
    return 0;
}
#include<iostream>
using namespace std;
class BankAccount 
{
private:
    static double interestRate; // Static member variable
public:
    static void setInterestRate(double rate) 
    {
        interestRate=rate; // Set static variable
    }
    static double calculateInterest(double amount) 
    {
        return amount*interestRate; // Use static variable
    }
};

// Initialize static member variable
double BankAccount::interestRate=0.05;

int main() 
{
    BankAccount::setInterestRate(0.07); // Set interest rate
    double interest=BankAccount::calculateInterest(1000); // Calculate interest
    cout<<"Interest: $"<<interest<<endl; // Output: Interest: $70
    return 0;
}
#include<iostream>
using namespace std;
struct Library 
{
    static int totalBooks; // Static member variable

    static void addBooks(int count) 
{
        totalBooks+=count; // Add to static variable
    }
};
// Initialize static member variable
int Library::totalBooks=0;

int main() 
{
    Library::addBooks(10);
    Library::addBooks(5);
    cout<<"Total Books in Library: "<<Library::totalBooks<<endl; // Output: 15
    return 0;
}

