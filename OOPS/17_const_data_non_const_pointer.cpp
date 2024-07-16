#include<iostream>
using namespace std; 
//lvalue:-variable having memory location
//rvalue:-variable don't have memory location
int main()
{
    //this not work in new compilers
    // const int a=5;
    // int *p=&a;
    // *p=6;
    //const data,non const pointer
    const int *a=new int(2); //content of pointer is constant but pointer itself can be reassign
    //we can also write 
    // int const*a=new int(2);//if i write const before * then content will be constant but we will change the value of the pointer
    cout<<*a<<endl;
    //we can't change the content of pointer
    // *a=20;
    // cout<<*a<<endl;
    //but itself can be reassigned or we can say address can be reassigned
    int b=20;
    a=&b;
    cout<<*a<<endl;
    return 0;
}