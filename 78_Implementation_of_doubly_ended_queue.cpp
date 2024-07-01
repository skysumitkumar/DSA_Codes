#include<iostream>
using namespace std;
class dqueue
{
    public:
    int *arr;
    int size;
    int front;
    int back;
    dqueue(int size)
    {
        this->size=size;
        arr=new int[size];
        front=back=-1;
    }   
    void pushback(int val)
    {
        if(front==-1&&back==-1)
        {
            front=back=0;
            arr[back]=val;
            return;
        }
        if(front!=0&&back==size-1)
        {
            back=0;
            arr[back]=val;
            return;
        }
        if(back==front-1)
        {
            cout<<"queue is full so we cant push more elements from back "<<endl;
            return;
        }
        if(front==0&&back==size-1)
        {
            cout<<"queue is full so we cant push more elements from back "<<endl;
            return;
        }
        back++;
        arr[back]=val;
    }
    void pushfront(int val)
    {
        if(back==front-1)
        {
            cout<<"queue is full we cant push any element in the queue from front "<<endl;
            return;
        }
        if(front==-1&&back==-1)
        {
            front=back=0;
            arr[front]=val;
            return;
        }
        if(front==0&&back!=size-1)
        {
            front=size-1;
            arr[front]=val;
            return;
        }
        if(front==0&&back==size-1)
        {
            cout<<"queue is full we cant push any element in the queue from front "<<endl;
        }
        front--;
        arr[front]=val;
    }
    void popfront()
    {
        if(front==-1&&back==-1)
        {
            cout<<"There is no element in the queue to pop "<<endl;
            return;
        }
        if(front==back)
        {
            front=-1;
            back=-1;
            return;
        }
        front++;
    }
    void popback()
    {
        if(front==-1&&back==-1)
        {
            cout<<"There is no element in the queue to pop "<<endl;
            return;
        }
        if(front==back)
        {
            front=-1;
            back=-1;
            return;
        }
        back--;
    }
    int getfront()
    {
        if(front==-1&&back==-1)
        {
            cout<<"There is no front element in the queue "<<endl;
            return -1;
        }
        return arr[front];
    }
    int getback()
    {
        if(front==-1&&back==-1)
        {
            cout<<"There is no element in the back of the queue "<<endl;
            return -1;
        }
        return arr[back];
    }
    int getsize()
    {
        if(front==-1&&back==-1)
        {
            cout<<"There is no element in the queue "<<endl;
            return -1;
        }
        if(front<back)
        {
            return size-back+1;
        }
        else
        return size-front+back+1;
    }
    bool isempty()
    {
        if(front==-1&&back==-1)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    cout<<"Enter the size of the dqueue ";
    int n;
    cin>>n;
    dqueue q(n);
    //int v;
    //cout<<"Enter the values in the queue "<<endl;
    //q.pushback(10);
    q.pushback(20);
    //q.pushback(30);
    q.pushfront(50);
    //q.pushfront(40);//1020304050
    //q.pushback(30);
    //q.pushfront(50);
    cout<<endl<<"The front element is "<<q.getfront();
}