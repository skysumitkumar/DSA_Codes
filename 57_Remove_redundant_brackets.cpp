#include<iostream>
#include<string>
using namespace std;
class stack
{
    public:
    char * arr;
    int size;
    int top;
    stack(int size)
    {
        arr=new char[size];
        this->size=size;
        top=-1;
    }
    void push(char data)
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
    char gettop()
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
void CheckRedundantBrackets(stack &s,string str)
{
    int length=str.size();
    for(int i=0;i<length;i++)
    {
        int start=str[i];
        if(start=='('||start=='+'||start=='-'||start=='*'||start=='/')
        {
            s.push(start);
        }
        else if(start==')')
        {
            if(s.gettop()=='+'||s.gettop()=='-'||s.gettop()=='*'||start=='/')
            {
                s.pop();
                if(s.gettop()=='('||start==')')
                {
                    s.pop();
                }
            }
            else
            {
                cout<<"There is redundant bracket in this expression";
                return;
            }
        }
    }
    if(s.isempty())
    cout<<"There is no redundant bracket in this expression";
    else cout<<"There is redundant bracket in this expression";
}
int main()
{
    int size;
    string str;
    cout<<"Enter the size of stack ";
    cin>>size;
    stack s(size);
        cout<<"Enter the string ";
        cin>>str;
    CheckRedundantBrackets(s,str);
}