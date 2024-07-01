#include<iostream>
using namespace std;
class stack
{
    public:
    int * arr;
    int size;
    int top;
    stack(int size)
    {
        arr=new int[size];
        this->size=size;
        top=-1;
    }
    void push(int data)
    {
        if(size-top<1)
        {
            cout<<"stack is full ";
            return;
        }
        top++;
        arr[top]=data;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"there is no element in stack to pop ";
            return;
        }
        top--;
    }
    int gettop()
    {
        if(top==-1)
        {
            cout<<"stack is empty currently ";
        }
        else
        return arr[top];
    }
    int getsize()
    {
        return top+1;
    }
    bool isempty()
    {
        if(top==-1)
        {
            return true;
        }
        else return false;
    }
};
void InsertTargetAtBottom(stack &s ,int target)
{
    if(s.isempty())
    {
        s.push(target);
        return;
    }
    int temp=s.gettop();
    s.pop();
    InsertTargetAtBottom(s,target);
    s.push(temp);
}
int main()
{
    int size,data;
    cout<<"Enter the size of stack ";
    cin>>size;
    stack s(size);
    int copyedsize=size;
    while(copyedsize--)
    {
        cout<<"Enter value that you want to push in stack ";
        cin>>data;
        s.push(data);
        cout<<endl;
    }
    int target=s.gettop();
    s.pop();
    InsertTargetAtBottom(s,target);
    cout<<"stack after putting topest element in bottom "<<endl;
    while(s.isempty()!=1)
    {
        cout<<s.gettop()<<endl;
        s.pop();
    }
}