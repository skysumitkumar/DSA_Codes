#include<iostream>
using namespace std;
#include<vector>
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
void findprevioussmallest(vector<int> &a,stack &s)
{
    vector<int >b(a.size());//remember here about the size of the vector
    if(a.size()==0)
    {
        cout<<"vector is empty firstly insert the vector ";
        return;
    }
    for(int i=0;i<a.size();i++)
    {
        if(s.gettop()<a[i])
        {
            b[i]=s.gettop();
            s.push(a[i]);
        }
        else
        {
        while(s.gettop()>a[i])
        {
            s.pop();
            if(s.gettop()<a[i])
            {
                b[i]=s.gettop();
                s.push(a[i]);
            }
        }
        }
    }
    cout<<"The next smallest elements of this vectors are ";
    for(int i=0;i<b.size();i++)
    {
        cout<<b[i]<<" ";
    }
}
int main()
{
    int N,i;
    vector<int> a;
    cout<<"Enter the size of vector ";
    cin>>N;
    stack s(N);
    s.push(-1);
    cout<<"Enter the elements in vector ";
    while(N--)
    {
        cin>>i;
        a.push_back(i);
    }
    findprevioussmallest(a,s);
}
