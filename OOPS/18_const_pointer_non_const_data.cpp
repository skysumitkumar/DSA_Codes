#include<iostream>
using namespace std; 
int main()
{
    //const pointer non const data
    //if we write * before const then we get const pointer and non const data
    int * const a=new int(2);
    cout<<*a<<endl;
    *a=20;
    cout<<*a<<endl;
}