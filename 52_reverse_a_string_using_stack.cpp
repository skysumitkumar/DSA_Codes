#include<iostream>
using namespace std;
#include<stack>
/*class stack
{
    public:
    char * arr;//for store character in array we have to make character array
    int size;
    int top;
    stack(int size)
    {
        arr=new char[size];//for store character in array we have to make character array
        this->size=size;
        top=-1;
    }
    void push(int data)
    {
        if(size-top==1)
        {
            cout<<"stack is full"<<endl;
            return;
        }
        top++;
        arr[top]=data;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"no element in stack to pop"<<endl;
            return;
        }
        top--;
    }
    char gettop()//for returning characters we have to use char
    {
        if(top==-1)
        {
            cout<<"no element in stack"<<endl;
        }
        else
        return arr[top];
        //cout<<arr[top]<<endl;
    }
    int getsize()
    {
        return top+1;
    }
    bool empty()
    {
        if(top==-1)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    string a="sumit";
    int sizeofstring=a.size();
    stack s(sizeofstring);
    int i;
    for(i=0;i<sizeofstring;i++)
    {
        s.push(a[i]);
    }
    while(!s.empty())
    {
        cout<<s.gettop()<<endl;
        s.pop();
    }
    
}*/
//By use of STL library
int main()
{
    string a="sumit";
    stack<char> s;
    int i;
    for(i=0;i<a.size();i++)
    {
        s.push(a[i]);
    }
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    
}
