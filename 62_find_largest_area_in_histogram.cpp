//wrong output in this code
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
vector<int> findnextsmallest(vector<int> &a,stack &s)
{
    vector<int >b(a.size());//remember here about the size of the vector
    if(a.size()==0)
    {
        cout<<"vector is empty firstly insert the vector ";
        return a;
    }
    for(int i=a.size()-1;i>=0;i--)
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
    return b;
}
vector<int> findprevioussmallest(vector<int> &a,stack &s)
{
    vector<int >b(a.size());//remember here about the size of the vector
    if(a.size()==0)
    {
        cout<<"vector is empty firstly insert the vector ";
        return a;
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
    return b;
}
int findlargestareaofhistogram(vector<int>&a,vector<int>& v1,vector<int>&v2)
{
    if(a.size()==0)
    {
        return 0;
    }
    int max,total;
    for(int i=0;i<a.size();i++)
    {
        if(v2[i]==-1)
        v2[i]=a.size();
        total=(v2[i]-v1[i]-1)*a[i];
        if(total>max)
        {
            max=total;
        }
    }
    return max;
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
    vector<int>v1=findprevioussmallest(a,s);
    vector<int>v2=findnextsmallest(a,s);
    int max=findlargestareaofhistogram(a,v1,v2);
    cout<<"The maximum size of histogram here is "<<max;
}
