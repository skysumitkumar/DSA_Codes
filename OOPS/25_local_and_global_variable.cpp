#include<iostream>
using namespace std;
int x=5;
int main()
{
    
    int x=2;
    x=3;
    cout<<"print local variable value"<<x<<endl;
    cout<<"global variable value "<<::x<<endl;
    //change value of global variable here 
    ::x=10;
    cout<<"print new global variable "<<::x<<endl;
}