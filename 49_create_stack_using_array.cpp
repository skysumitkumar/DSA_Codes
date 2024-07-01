#include<iostream>
using namespace std;
class stack
{
    public:
    int* arr;
    int size;
    int top;
    stack(int size)
    {
        arr=new int[size];
        this->size=size;
        top=-1;// hame yha dobera top ka data type dane ki need nahi h hamne ise already uper declare kar rekha h
    }    
    void push(int data)
    {
        if(size-top>1)
        {
            top++;
            arr[top]=data;
        }
        else
        cout<<"stack is overflow"<<endl;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"stack underflow"<<endl;
            return;
        }
        else
        top--;
    }
    void gettop()   //make it also a void 
    {
        if(top==-1)
        {
            cout<<"no element in stack";
            return;
        }
        else
        {
            cout<<arr[top]<<endl;
        }
    }
    int getsize()  // here we make it getsize in place of size because i give size name in array size
    {
        return top+1;
    }
    bool isempty()
    {
        if(top==-1)
        {
            return true;
        }
        else 
        return false;
    }   
};
int main()
{
    stack s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    // s.gettop();// it return your topest element no need to print it 
    // s.pop();
    // cout<<endl;
    // s.gettop();
    // cout<<endl;
    // cout<<s.empty()<<endl;    //it return bool so we have to print it
    // cout<<s.getsize();  
    // cout<<endl;
    while(!s.isempty())
    {
        s.gettop();
        cout<<endl;
        s.pop();
    }
}