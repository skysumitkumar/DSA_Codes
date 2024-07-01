#include<iostream>
using namespace std;
class xyz
{
    public:
    int x;
    int *y;
    xyz(int _x,int _y):x(_x),y(new int(_y)){}
    //deep copy constructor
    xyz(const xyz &obj)
    {
        x=obj.x;
        y=new int(*obj.y);//here you have to use *obj.y
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
    
    //deep copy constructor
    xyz b=a;
    
    cout<<"print all values"<<endl;
    b.print();

    //change value of y of b object
    *b.y=20;
    cout<<"print all values"<<endl;
    b.print();

    //but when we print all values of a obj then its value cant change because we use deep copy
    a.print();
    return 0;
}