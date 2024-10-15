#include<iostream>
using namespace std;
// static data member:-That variable will share the memory with all the class instances
// static member function:-There is no instance of that class being passed into that method
class xyz
{
    public:
    // we can't pass variable that are not static in the static function
    // when we use this and want to print in static function than it give error
    // int x,y;
    // here we make static variables 
    static int x,y;
    // xyz()x(1),y(2){}
    static void print()
    {
        // we cant use this here because in static function no this pointer is passed
        // cout<<this->x<<" "<<this->y<<endl;
        cout<<x<<" "<<y<<endl;
    }
};
// yha hamne bataya h ki x jo h vo xyz class ka h or y jo h vo bhi xyz class ka h
int xyz::x;
int xyz::y;
int main()
{
    xyz a;
    xyz b;
    // assign values of x and y in obj a
    a.x=5;
    a.y=6;
    // print value of obj a
    a.print();
    // assign values of x and y in obj b
    b.x=10;
    b.y=20;
    // print value of obj b
    // but when again we print the value of a it will change because in obj b we change the static variable value 
    // these share memory with all the class instance
    a.print();
}

#include<iostream>
using namespace std;
class Vehicle 
{
public:
    static void displayType() 
    {
        cout<<"This is a vehicle."<<endl;
    }
};

class Car:public Vehicle{};
class Bike:public Vehicle{};

int main() 
{
    Vehicle::displayType(); // Calling static function from base class
    Car::displayType();     // Can also call it from derived class
    Bike::displayType();
    return 0;
}

#include <iostream>
using namespace std;

class Shape 
{
public:
    static void info() 
    {
        cout<<"This is a shape."<<endl;
    }
};

class Circle:public Shape 
{
public:
    static void info() 
    {
        cout<<"This is a circle."<<endl; // This hides the base class version
    }
};

int main() 
{
    Shape::info();   // Output: This is a shape.
    Circle::info();  // Output: This is a circle.
    return 0;
}

#include <iostream>
using namespace std;

class Account 
{
public:
    static double interestRate; // Base class static member
    static double getInterest(double amount) 
    {
        return amount*interestRate;
    }
};

double Account::interestRate=0.05;

class SavingsAccount:public Account 
{
public:
    static void setInterestRate(double rate) 
    {
        interestRate=rate; // Set interest rate for all accounts
    }
};

int main() 
{
    SavingsAccount::setInterestRate(0.07);
    double interest=Account::getInterest(1000); // Use base class function
    cout<<"Interest: $"<<interest<<endl; // Output: 70
    return 0;
}
#include<iostream>
using namespace std;

class Base 
{
public:
    static void display() 
    {
        cout<<"Base class display."<<endl;
    }
};

class Derived:public Base 
{
public:
    static void display() 
    {
        cout<<"Derived class display."<<endl;
    }

    static void callBaseDisplay() 
    {
        Base::display(); // Call the base class static function
    }
};

int main() 
{
    Derived::display();      // Calls Derived class display
    Derived::callBaseDisplay(); // Calls Base class display
    return 0;
}

#include<iostream>
using namespace std;

class Base 
{
public:
    static void publicFunction() 
    {
        cout<<"Base public function."<<endl;
    }

private:
    static void privateFunction() 
    {
        cout<<"Base private function."<<endl;
    }

public:
    static void callPrivate() 
    {
        privateFunction(); // Call the private function within the base class
    }
};

class Derived : public Base 
{
public:
    static void callBasePublic() 
    {
        Base::publicFunction(); // Call the base class public static function
    }

    // Cannot call privateFunction directly
};

int main() 
{
    Base::publicFunction();  // Works
    Derived::callBasePublic(); // Works
    Base::callPrivate();      // Works but can't call privateFunction directly
    return 0;
}

#include<iostream>
using namespace std;

template<typename T>
class Calculator {
public:
    static T add(T a, T b) 
    {
        return a+b;
    }

    static T multiply(T a, T b) 
    {
        return a*b;
    }
};

int main() 
{
    cout<<"Sum: "<<Calculator<int>::add(5,3)<<endl; // Calls static function for int
    cout<<"Product: "<<Calculator<double>::multiply(4.5, 2.0)<<endl; // Calls static function for double
    return 0;
}

