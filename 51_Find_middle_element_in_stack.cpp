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
void findMiddle(stack &s, int totalsize)
{
    if(s.isempty())
    {
        cout<<"there is no element in stack ";
        return;
    }
    if(s.getsize()==(totalsize/2)+1)//array ka total size devide by 2 plus 1 is middle element it hits when size or array is as that
    {
        cout<<"The middle element of the stack is "<<s.gettop()<<endl;
        return;
    }
    int temp=s.gettop();
    s.pop();
    findMiddle(s,totalsize);
    s.push(temp);//push all elements as it is after finding middle element
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
    findMiddle(s,size);
}
/*
//when we use STL library than we perform these steps
void MiddleElement(stack<int> &s,int &totalsize)//we get it by reference
{
    if((totalsize/2)+1==s.size())//array ka total size devide by 2 plus 1 is middle element it hits when size or array is as that
    {
        cout<<"Middle element of this stack is "<<s.top()<<endl;//print topest element
        return;
    }
    int temp=s.top();//assign toppest element in it
    s.pop();
    MiddleElement(s,totalsize);
    s.push(temp);//after finding middle element push all element in stack as it is
}
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    int totalsize=s.size();
    MiddleElement(s,totalsize);//firsty we have to assign the size of array than  pass it
    cout<<s.top();
    return 0;
}
*/