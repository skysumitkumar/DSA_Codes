#include<iostream>
using namespace std; 
//lvalue:-variable having memory location
//rvalur:-variable dont have memory location
int main()
{
    //this not work in new compilers
    //const int a=5;
    // int *p=&a;
    // *p=6;
    //const data,non const pointer
    const int *a =new int(2); //content of pointer is constant but pointer itself can be resign
    //we can also write 
    // int const*=new int(2);//if i write const before * then content will be const
    cout<<*a<<endl;
    //we cant change the content of pointer
    // *a=20;
    // cout<<*a<<endl;
    //but itself can be reassigned
    int b=20;
    a=&b;
    cout<<*a<<endl;
    return 0;
}