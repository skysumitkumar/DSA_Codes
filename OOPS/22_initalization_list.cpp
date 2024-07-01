#include<iostream>
using namespace std;
class sumit
{
    int x;
    int *y;
    const int z;
    public:
    //by using our old style  constructor if we make z as const and then we want to reassign it in the constructor than it give error
    // sumit(int _x,int _y,int _z)
    // {
    //     x=_x;
    //     y=new int(_y);
    //     z=_z;
    // }

    //but by using initalization list we reassign it
    sumit(int _x,int _y,int _z):x(_x),y(new int(_y)),z(_z){}//we also write in these prianthesis
    
    void set(int _x)
    {
        x=_x;
    }
    int get()
    {
        return z;
    }
};
int main()
{
    sumit a(1,2,3);
    cout<<a.get();
}