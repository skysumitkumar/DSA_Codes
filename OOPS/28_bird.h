#include<iostream>
using namespace std;
// here we make interface with the name Bird
class Bird
{
    // this class is pure virtual class
    public:
    virtual void eat()=0;
    virtual void fly()=0;
    // classes that inherits this class
    // has to implement pure virtual functions
};
// here we give implementation of the interface
class sparrow:public Bird
{
    public:
    void eat()
    {
        cout<<"Sparrow is eating"<<endl;
    }
    void fly()
    {
        cout<<"Sparrow is flying"<<endl;
    }
};
class eagle:public Bird
{
    private:
    void eat()
    {
        cout<<"eagle is eating"<<endl;
    }
    void fly()
    {
        cout<<"eagle is flying"<<endl;
    }
};
class peagon:public Bird
{
    public:
    void eat()
    {
        cout<<"peagon is eating"<<endl;
    }
    void fly()
    {
        cout<<"peagon is flying"<<endl;
    }
};