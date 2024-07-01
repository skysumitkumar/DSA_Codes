#include<iostream>
using namespace std;
class Human
{
    public:
    int height;
    int size;
    int length;
    int print(int size)
    {
        this->size=size;
        return size;
    }
    //we use different parameter to do function overloading
    int print(int size,int length)
    {
        this->size=size;
        this->length=length;
        return size;
        //return length;
    }
};
int main()
{
    Human h;
    cout<<h.print(10,20)<<endl;
}