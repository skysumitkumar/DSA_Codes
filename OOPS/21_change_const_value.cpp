//use mutable keyword
#include<iostream>
using namespace std;
class abc
{
    mutable int x;//by using mutable keyword we can change the value of x in any const function
    int *y;
    public:
    abc()
    {
        x=0;
        y=new int(0);
    }
    abc(int _x,int _y)//remember here not to use similar names
    {
        x=_x;
        y=new int(_y);
    }
    int getx() const
    {
        //here we can modify the value of x because we mutate it already
        x=4;
        return x;
    }
    void setx(int val)
    {
        x=val;
    }
    int gety() const//const function
    {
        return *y;
    }
    void sety(int val)
    {
        *y=val;
    }
};
//this function only print those function those are const
void printABC(const abc &a)//here we can't change any member variable
{
    //here remember that here you call only those function that are already const
    cout<<a.getx()<<" "<<a.gety()<<endl;
}
int main()
{
    // abc a;
    // cout<<a.getx()<<endl;
    // cout<<a.gety()<<endl;

    abc a(1,2);
    printABC(a);
    return 0;
}