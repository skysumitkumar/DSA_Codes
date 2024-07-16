#include<iostream>
using namespace std;
class Animal
{
    //By default it is in private we cant access it outside the class
    int weight;
    public:
    //public members are accessible outside the class
    int size;
    string color;
    //to access private member outside the class we make getter and setter
    int setweight(int w)
    {
        weight=w;
    }
    int getweight()
    {
        return weight;
    }
};
int main()
{
    //here we make a object to do work with class
    Animal a;
    //firstly we set value to our private member by using setter
    a.setweight(50);
    //now we access the value of our private member by using getter 
    cout<<a.getweight();
    //cout<<a.size;
    return 0;
}