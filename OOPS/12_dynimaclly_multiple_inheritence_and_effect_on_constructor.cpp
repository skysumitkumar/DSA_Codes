#include<iostream>
#include<string>
using namespace std;
class Animal
{
    public:
    int height;
    int size;
    int weight;
    string color;
    //constructor cant be declare as virtual
    //constructor can be private
    Animal()
    {
        cout<<"I Am In The Animal Class"<<endl;
    }
};

class cat:public Animal
{
    public:
    int height;
    string color;
    cat()
    {
        cout<<"I Am In The Cat Class"<<endl;
    }
};

int main()
{   
    // //upstreaming
    // //firstly we use cat class reference and cat class obj
    // //when we make obj of cat than firstly animal constructor than cat constructor is called
    // dynamically allocate memory for an object of type cat and initialize a pointer to this object.
    // cat * c=new cat;
    
    
    // //upstreaming
    // //here we use Animal class reference and Animal class obj
    // //when we make animal obj than it call only animal constructor
    // dynamically allocate memory for an object of type Animal and initialize a pointer to this object.
    // Animal * c=new Animal;
    

    // //upstreaming
    // //here we use Animal class reference and cat class obj
    // It call members and methods of the reference class and we change object class variable using getter and setter we help of virtual keyword in base class
    // //when we make the Animal class obj than it call firstly Animal constructor than call cat constructor
    // Animal * c=new cat;
    

    // //downstreaming
    // It call members and methods of the reference class and we change object class variable with class name and scope resolution operator because here we inherited the reference class
    // //here we use cat class reference and Animal class as object
    // //it give error when we use previous method for downstreaming
    // //cat * c=new Animal;
    // //for downstreaming we use this
    // //when we make the cat class object than it call only Animal constructor
    // cat* c=(cat*) new Animal;
    // Animal* a = new cat(); // Correct upcasting, cat is a type of Animal it calls animal constructor
    // cat* c = dynamic_cast<cat*>(a); // Safe downcasting it calls cat constructor
}
