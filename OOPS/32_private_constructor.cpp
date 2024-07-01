#include<iostream>
using namespace std;
class ctorprivate
{
    int a;
    //yes we can make constructor as private
    ctorprivate(int _val):a(_val){};
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
//this is used to insilized the value of constructor with another class that are the friend of A
class B
{
    public:
    //here we insilize our class A constructor
    ctorprivate setctor()
    {
        return ctorprivate(10);
    }
};
int main()
{
    //so here we cant assign value in the constructor with main function
    //ctorprivate x(5);

    B c;
    ctorprivate x=c.setctor();
    //now our constructor is insilized so we perform task by using the obj x
    cout<<"firstly our value of a is "<<x.getval()<<endl;
    x.setval(20);
    cout<<"after set the value of a is "<<x.getval();
    //y.getval();
}