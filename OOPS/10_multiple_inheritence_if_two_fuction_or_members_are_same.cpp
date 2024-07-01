#include<iostream>
using namespace std;
class Animal
{
    public:
    Animal()
    {
        cout<<"I am in the Animal class"<<endl;
    }
     int size;
     int length;
     int height;
     int printsize()
     {
        height=10;
        return size;
     }
};
class Animal_India
{
    public:
    Animal_India()
    {
        cout<<"I am in the Animal_India class"<<endl;
    }
    int size;
    int length;
    int height;
    int printsize()
    {
        height =11;
        return size;
    }
    int print()
    {
        return height;
    }
};
class dog:public Animal,public Animal_India
{
    public:
    dog()
    {
        cout<<"I am in the dog class"<<endl;
    }
    int height;

    // int print()
    // {
    //     return height;
    // }
};
int main()
{
    //when we make the object of dog it call parent class default constructor also
    dog a;
    //if we assign value to size in the class dog here compiler confuse to assign which class size value because both call take varible size
    //a.size=10;
    //so to solve this situation we use scope resolution operater to said compiler to assign value in that class
    a.Animal::size=10;
    //we also cant print it because complier is confuse to print which class value
    //cout<<a.printsize()<<endl;
    //so to solve this situation we use scope resolution operater to said compiler to print value of that class
    cout<<a.Animal::printsize()<<endl;
    //when we declare height variable in the dog class and when we assign height using dog class it take local variable and assign it in local variable
    a.height=50;
    //Animal_India print call give garbadge value if we make print function in the dog class than it call local function print and give output 50
    cout<<a.print()<<endl;
    //if i make printsize function in the class Animal and Animal_India than compiler confuse to call which function
    //cout<<a.printsize();
    //so to solve this problem we use scope resolution operater
    cout<<a.Animal::printsize()<<endl;
    //when we make constructor in all the class when we make object to the our child class than firstly Animal constructor than Animal_India constructor than dog constructor is called
}