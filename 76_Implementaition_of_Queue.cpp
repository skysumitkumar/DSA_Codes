#include<iostream>
using namespace std;
class queue
{
    public:
    int * arr;
    int size;
    int front;
    int back;
    queue(int size)
    {
        //remember this->size=size of if you dont want to use this statement then firsly use another variable int function then assign size in function
        this->size=size;
        arr=new int[size];
        front=back=-1;
    }
    void push(int val)
    {
        if(back==size)
        {
            cout<<"we cant push any element on queue because queue is full ";
            return;
        }
        else if(front==back)
        {
            front=back=0;
            arr[back]=val;
            back++;
            return;
        }
        else
        {
            arr[back]=val;
            back++;
        }
    }
    void pop()
    {
        if(front>=back)
        {
            cout<<"we cant pop any element queue is empty ";
            return;
        }
        //this is important step
        else
        {
            front++;
            //if queue is empty restore our queue from starting
            if(front==back)
            {
                front=back=0;
            }
        }
        
    }
    int getsize()
    {
        return back-front;
    }
    int getfront()
    {
        if(front==size||front==back)
        {
            cout<<"queue is empty "<<endl;
            return 0;
        }
        return arr[front];
    }
    bool isempty()
    {
        if(front==back)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    cout<<"Enter the size of queue ";
    int v,n;
    cin>>v;
    queue q(v);
    cout<<endl<<"Enter the value in queue "<<endl;
    while(v--)
    {
        cin>>n;
        q.push(n);
    }
    cout<<endl<<"check queue is empty or not ";
    cout<<q.isempty()<<endl;
    //cout<<q.getfront();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<q.getfront();
    // while(n--)
    // {
    //     cout<<q.getfront()<<endl;
    //     q.pop();
    // }
    // cout<<q.getfront()<<endl;
}