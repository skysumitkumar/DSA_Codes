#include<iostream>
using namespace std;
class dog
{
    //size of empty class is 1
};
class Animal
{
    //By default it is in private we can't access it outside the class
    int weight;
    public:
    //public members are accessible outside the class
    int size;
    string color;     //sizeof this is 32

};
int main()
{
    //here we make a object to do work with class
    Animal a;
    //this is the private member we cant access it outside the class
    //cout<<a.weight<<endl;
    cout<<sizeof("")<<endl; //1
    cout<<a.size<<endl;
    dog b;
    cout<<sizeof(dog);
}
