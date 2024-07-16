#include<iostream>
using namespace std;
class privConstructor
{
    int a;
    // yes we can make constructor as private
    privConstructor(int _val):a(_val){};
    public:
    int b,c;
    void setval(int _val)
    {
        a=_val;
    }
    int getval()const
    {
        return a;
    }
    friend class B;
};
// this is used to initalized the value of constructor with another class that are the friend of A
class B
{
    public:
    // here we initialize our class A constructor
    privConstructor setctor()
    {
        return privConstructor(10);
    }
};
int main()
{
    // so here we can't assign value in the constructor with main function
    // privConstructor x(5);

    B c;
    privConstructor x=c.setctor();
    // now our constructor is initialized so we perform task by using the obj x
    cout<<"firstly our value of a is "<<x.getval()<<endl;
    x.setval(20);
    cout<<"after set the value of a is "<<x.getval();
}