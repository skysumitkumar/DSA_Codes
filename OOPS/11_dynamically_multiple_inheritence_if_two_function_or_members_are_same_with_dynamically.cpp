//problem on dog *=(dog*) Animal
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
    Animal()
    {
        cout<<"I Am In The Animal Class"<<endl;
    }
    void printcolor()
    {
        cout<<"i am in Animal class"<<endl;
        cout<<color<<endl;
    }
   virtual ~Animal(){}
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
    void printcolor()
    {
        cout<<"i am in cat class"<<endl;
        cout<<color<<endl;
    }
};

int main()
{   
    // //upstreaming
    // //firstly we use cat class and cat obj
    // cat * c=new cat;
    // c->Animal::color="black";
    // c->cat::color="brown";
    // c->printcolor();
    
    // //upstreaming
    // //here we use Animal class and Animal obj
    // Animal * c=new Animal;
    // c->Animal::color="black";
    // //here we cant assign in the cat class becauese animal class not inherit cat class
    // //c->cat::color="brown";
    // c->printcolor();

    // //upstreaming
    // //here we use Animal class and cat obj
    // Animal * c=new cat;
    // c->Animal::color="black";
    // //when we are assigning value to cat class it give error because here we make Animal class obj and Animal class not inherited cat class
    // //c->cat::color="brown";
    // c->printcolor();
    // //when we want to call  print color of cat class than we have to use virtual keyword in Animal class than it go to print color of the cat class
    // //c->printcolor();

    //downstreaming
    //here we use cat class and Animal class as object
    //it give error when we use previous method for downstreaming
    //cat * c=new Animal;
    //for downstreaming we use this
    cat* c=(cat*) new Animal;
    // c->color="brown";
    // c->Animal::color="black";
    // c->printcolor();
    if (c != nullptr) 
    {
    // Successfully downcasted to cat
    c->color = "brown";
    c->Animal::color = "black";
    c->printcolor();
    delete c;  // Don't forget to delete the dynamically allocated object
    } 
    else 
    {
    // Failed to downcast, handle the error
    delete c;  // Delete the object since it's not a cat
    }

}