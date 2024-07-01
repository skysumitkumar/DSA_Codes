#include<iostream>
using namespace std;
class A
{
    private:
    int a;
    int b;
    public:
    int c;
    int d;
    A():a(0),b(2),c(3),d(4){};
    int geta()
    {
        return a;
    }
    void seta(int _val)
    {
        a=_val;
    }
    //we are make class B as A's friend so it get all its private things
    friend class B;
    //now we use friend function to give all private things to some function
    //here we make print function to the friend of the classs A
    friend void print(A &a);
    //we can also write 
    //friend void print(A &);
};
class B
{
    public:
    //here we take obj a
    void print(A &a)
    {
        //by using getter and setter function we access the value of the class A
        a.seta(10);
        cout<<a.geta()<<endl;
        //we cant use this here without make class B as A's friend
        //cout<<a.b;

        //after making class B as class A's friend we can access all the private things of A
        cout<<a.a<<endl;
        
    }
};
//here we make a function that access private data of class A
void print(A &a)
{
    cout<<a.b<<endl;
}
int main()
{
    A a;
    B b;
    //here we pass object a to the B class
    b.print(a);

    print(a);
}