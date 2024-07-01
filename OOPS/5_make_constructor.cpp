#include<iostream>
using namespace std;
class Animal
{
    int weight=10;
    public:
    int size;
    string color;
    //default constructor
    Animal()
    {
        cout<<"default constructor called"<<endl;
    }
    //paramatrize constructor
    //with this we also assign value to our private members
    Animal(int weight,int size,string color)
    {
        cout<<"paramatrize constructor called"<<endl;
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
};
int main()
{
    //this always call default constructor
    Animal a;
    //to call paramatrize constructor we give parameter to our constructor
    Animal b(50,30,"white");
    //a.setweight(50);
    cout<<a.getweight()<<endl;
    cout<<b.getweight()<<endl;
    //here default constructor is called
    Animal * dog=new Animal;
    //here paramatrize constructor is called
    Animal * cat=new Animal(60,40,"Brown");
}