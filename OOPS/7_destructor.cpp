#include<iostream>
using namespace std;
class Animal
{
    int weight=10;
    public:
    int size;
    string color;
    Animal()
    {
        cout<<"default constructor called"<<endl;
    }
    Animal(int weight,int size,string color)
    {
        cout<<"parametrize constructor called"<<endl;
        this->weight=weight;
        this->size=size;
        this->color=color;
    }
    int setweight(int weight)
    {
        this->weight=weight;
    }
    int getweight()
    {
        return weight;
    }
    //default destructor
    //it automatically call in case of static obj after the execution
    //but in case of dynamic we have to call it
    //And remember when you use many classes than you have to use the virtual to the parent constructor so our child class constructor also called
    ~Animal()
    {
        cout<<"I am inside the destructor"<<endl;
    }
};
int main()
{
    //in case of static
    Animal a;
    //in case of dynamic obj destructor can't called automatically 
    Animal * b=new Animal;
    //destructor for static object is called automatically 
    //but for dynamic object we have to call here we call destructor for dynamic obj
    delete b;

}