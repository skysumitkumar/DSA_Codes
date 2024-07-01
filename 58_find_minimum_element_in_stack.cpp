//we also find is with the sort stack but with sort stack it take o(n) time complexity 
//we use another aproach which is two element store in one index of stay

//this program is incomplete complete it 
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class stack
{
    public:
    vector<pair<int,int>>st;//to make a stay of which store two element in one position one is element and one is smallest element currently
    int size;
    int top;
    stack(int size)
    {
        st=new int[size];
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
        st[top]=data;
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
        return st[top];
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
    int min(int val)
    {
        
    }
};
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