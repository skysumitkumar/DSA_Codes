#include<iostream>
using namespace std;
class Animal
{
    //By defalult it is in private we cant access it outside the class
    int weight;
    public:
    //public members are accaceble outside the class
    int size;
    string color;
    //to access private member outside the class we make geter and seter
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
    //firstly we set value to our private member by using seter
    a.setweight(50);
    //now we access the value of our private member by usig getter 
    cout<<a.getweight();
    //cout<<a.size;
}