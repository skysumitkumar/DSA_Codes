#include<iostream>
using namespace std;
class stack
{
    public:
    int * arr;
    int size;
    int top1;
    int top2;
    stack(int size)
    {
        arr=new int[size];
        this->size=size;
        top1=-1;
        top2=size;
    }
    void push1(int data)
    {
        if(top2-top1==1)
        {
            cout<<"stack is overflow"<<endl;
            return;
        }
        top1++;
        arr[top1]=data;
    }
    void pop1()
    {
        if(top1==-1)
        {
            cout<<"no element in stack1 to pop"<<endl;
            return;
        }
        top1--;
    }
    void gettop1()
    {
        if(top1==-1)
        {
            cout<<"no element in stack1"<<endl;
            return;
        }
        cout<<arr[top1]<<endl;
    }
    int getsize1()
    {
        return top1+1;
    }
    bool empty1()
    {
        if(top1==-1)
        {
            return true;
        }
        else 
        return false;
    }
    void push2(int data)
    {
        if(top2-top1==1)
        {
            cout<<"stack2 is full"<<endl;
            return;
        }
        top2--;
        arr[top2]=data;
    }
    void pop2()
    {
        if(top2==size)
        {
            cout<<"no element in stack2 to pop"<<endl;
            return;
        }
        top2++;
    }
    void gettop2()
    {
        if(top2==size)
        {
            cout<<"no element in stack2"<<endl;
            return;
        }
        cout<<arr[top2]<<endl;
    }
    bool empty2()
    {
        if(top2==size||top2-top1==1)
        {
            return true;
        }
        return false;
    }
    int getsize2()
    {
        return size-top2;
    }
};
int main()
{
    stack s(10);
    s.push1(10);
    s.push1(30);
    cout<<"topest element of stack1 is ";
    s.gettop1();
    cout<<"topest element of stack2 is ";
    s.push2(20);
    s.push2(40);
    s.gettop2();
    cout<<"stack1 is "<<s.empty1()<<endl;
    cout<<"stack2 is "<<s.empty2()<<endl;
    // s.pop1();
    // s.pop2();
    cout<<"topest element of stack1 is ";
    s.gettop1();
    cout<<"topest element os stack2 is ";
    s.gettop2();
    cout<<"size of stack1 is "<<s.getsize1()<<endl;
    cout<<"size of stack2 is "<<s.getsize2()<<endl;
}