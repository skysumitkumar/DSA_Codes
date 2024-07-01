#include<iostream>
using namespace std; 
int main()
{
    //const pointer const data
    //if we write * after int and before const then we get const pointer and const data
    const int *const a=new int(2);
    cout<<*a<<endl;
    //here we cant change data
    //*a=20;
    //here we change the pointer also 
    //int b=20;
    //b=&a;
    cout<<*a<<endl;
}