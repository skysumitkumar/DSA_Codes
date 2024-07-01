#include<iostream>
using namespace std;
class xyz
{
    public:
    int x;
    int *y;
    xyz(int _x,int _y):x(_x),y(new int(_y)){}
    //default dumb copy constructor it does shallow copy
    xyz(const xyz &obj)
    {
        x=obj.x;
        y=obj.y;
    }
    void print()const
    {
        printf("x:%d\nPointer y:%p\nContent of y(*y):%d\n\n",x,y,*y);
    }
    ~xyz()
    {
        delete y;
    }
};
int main()
{
    xyz a(1,2);
    cout<<"print all values "<<endl;
    a.print();
    
    //copy constructor
    xyz b=a;
    
    cout<<"print all values"<<endl;
    b.print();

    //change value of y of b object
    *b.y=20;
    cout<<"print all values"<<endl;
    b.print();

    //but when we print all values of a obj then its value also change thant is falut here of shallow copy
    a.print();
    //when we use shallow copy it copy the value not make another variable 
    //this also make problem when we delete the pointer of one obj that you make in heap then it also delete other copyed obj
    //delete a;
    return 0;
}