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
void checkpranthesis(stack &s,string &str)
{
    char starting,ending;
    if(str.size()==0)
    return;
    int lengthstr=str.size();
    for(int i=0;i<lengthstr;i++)
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
        {
            starting=str[i];
            s.push(starting);
        }
        else if(str[i]==')'||str[i]=='}'||str[i]==']')
        {
            ending=str[i];
            if(ending==')'&&s.gettop()=='('||ending=='}'&&s.gettop()=='{'||ending==']'&&s.gettop()=='[')
            //if(s.gettop()=='('||s.gettop()=='{'||s.gettop()=='[')
            {
                s.pop();
            }
            else
            {
                cout<<"wrong pranthesis";
                return;
            }
        }
    }
    cout<<"right pranthesis";
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
    cout<<"our pranthesis is ";
    checkpranthesis(s,str);
}