#include<iostream>
using namespace std;
class Animal
{
    public:
    Animal()
    {
        cout<<"Animal class default constructor is called"<<endl;
    }
     int size;
     int length;
     int height;
     int printsize()
     {
        cout<<"This is Animal class "<<endl;
        height=10;
        return size;
     }
};
class Animal_India
{
    public:
    Animal_India()
    {
        cout<<"Animal_India class default constructor is called"<<endl;
    }
    int size;
    int length;
    int height;
    int printsize()
    {
        cout<<"This is Animal_India class "<<endl;
        height=11;
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
        cout<<"dog class default constructor is called"<<endl;
    }
    int height;
    int printsize()
    {
        cout<<"This is dog class"<<endl;
        height=12;
        return height;
    }
    // int print()
    // {
    //     return height;
    // }
};
int main()
{
    //when we make the object of dog it also call parent class default constructor also i.e:- Animal and Animal_India
    dog a;
    //if we assign value to size in the class dog here compiler confuse to assign which class size value because both call take variable size
    //a.size=10;
    //so to solve this situation we use scope resolution operator to said compiler to assign value in that class
    a.Animal::size=10;
    // when we make printsize() in all classes so it print only dog class printsize() function
    //cout<<a.printsize()<<endl;
    //when we not make printsize() function in dog class and make it to Animal and Animal_India class and then call it than compiler is confuses to call printsize() function of which class
    //cout<<a.printsize()<<endl;
    // so to solve this situation we use scope resolution operator to said compiler to print value of that class
    cout<<a.Animal::printsize()<<endl;
    //when we declare height variable in the dog class and when we assign height using dog class it take local variable and assign it in local variable
    a.height=50;
    //Animal_India print call give garbage value if we make print function in the dog class than it call local function print and give output 50
    cout<<a.print()<<endl;
    //if i make printsize function in the class Animal and Animal_India than compiler confuse to call which function
    //cout<<a.printsize();
    //so to solve this problem we use scope resolution operator
    cout<<a.Animal::printsize()<<endl;
    //when we make constructor in all the class when we make object to the our child class than firstly Animal constructor than Animal_India constructor than dog constructor is called
}