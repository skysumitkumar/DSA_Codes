#include<iostream>
using namespace std;
class queue
{
    public:
    int *arr;
    int size;
    int front;
    int back;
    queue(int n)
    {
        size=n;
        arr=new int[size];
        front=back=-1;
    }
    void push(int val)
    {
        if(front==-1&&back==-1)//remember this also
        {
            front=back=0;
            arr[back]=val;//after this i firstly increase the back than insert element
            return;
        }
        if(back==front-1||front==0&&back==size-1)
        {
            cout<<"Queue is full we cant push any element in the queue "<<endl;
            return;
        }
        if(front==size-1&&back!=0)
        {
            front=0;
            arr[back]=val;
        }
        if(front!=0&&back==size-1)
        {
            back=0;
            arr[back]=val;
            return;
        }
        back++;
        arr[back]=val;
    }
    void pop()
    {
        if(front==-1&&back==-1)
        {
            cout<<"There is no element int the queue ";
            return;
        }
        if(front==back)
        {
            //This is important condition remember it
            front=-1;
            back=-1;
            return;
        }
        //Remember it is in below of conditon of front==back
        if(front==size-1)
        {
            front=0;
            return;
        }
        front++;
    }
    //This function is wrong recheck it
    int getsize()
    {
        if(front<back)
        {
            return (back-front)+1;
        }
        else
        return size-front+back+1;
    }

    int getfront()
    {
        if(front==-1)
        {
            cout<<"There is no element in the queue "<<endl;
            return -1;
        }
        return arr[front];
    }
    bool isempty()
    {
        if(front==-1&&back==-1)//remember this point
        {
            return true;
        }
        else
        return false;
    }
};
int main()
{
    cout<<"Enter the size of the queue ";
    int s,n;
    cin>>s;
    queue q(s);
    cout<<"Enter the values in queue "<<endl;
    while(s--)
    {
        cin>>n;
        q.push(n);
    }
    cout<<endl;
    q.pop();
    q.pop();
    //q.push(10);
    
    q.pop();
    q.push(20);
    q.pop();
    q.pop();
    // q.pop();
    // q.pop();
    // while(!q.isempty())
    // {
    //     cout<<q.getfront()<<endl;
    //     q.pop();
    // }
    //cout<<"our front is in "<<q.getfront()<<endl;
    cout<<endl;
    cout<<"size of queue is "<<q.isempty();
    //cout<<endl<<"The front elemenet of the queue is"<<endl;
    //cout<<q.getfront();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.push(10);
    // q.push(20);
    //cout<<q.getfront()<<endl;
    // q.pop();
    // q.push(10);
    // q.push(20);
    //cout<<endl;
    //cout<<q.getsize();
    //cout<<q.getfront();
}
