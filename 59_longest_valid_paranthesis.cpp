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
int checkpranthesis(stack &s,string &str)
{
    if(str.size()==0)
    {
        cout<<"Here pranthesis is empty firstly enter string ";
        return 0;
    }
    int count=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        {
            s.push(str[i]);
        }
        if(str[i]==')')
        {
            if(!s.isempty())
            {
                if(s.gettop()=='('&&str[i]==')')
            {
                s.pop();
                count=count+2;
            }
            }
            
        }
    }
    return count;
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
    cout<<"our longest pranthesis is ";
    int length=checkpranthesis(s,str);
    cout<<length;
}