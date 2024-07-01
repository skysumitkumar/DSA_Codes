#include<iostream>
using namespace std;
#include<queue>
int main()
{
    queue<int> q;
    cout<<"Enter the size of the queue ";
    int n;
    cin>>n;
    cout<<"Enter the elements of the queue ";
    int v;
    for(int i=0;i<n;i++)
    {
        cin>>v;
        q.push(v);
    }
    int s=(q.size())/2;
    queue<int> q1;
    for(int i=0;i<s;i++)
    {
        q1.push(q.front());
        q.pop();
    }
    if(n%2==0)
    {
    for(int i=0;i<s;i++)
    {
        q.push(q1.front());
        q1.pop();
        q.push(q.front());
        q.pop();
    }
    }
    else
    {
        for(int i=0;i<s;i++)
        {
            q.push(q1.front());
            q1.pop();
            q.push(q.front());
            q.pop();
        }
        q.push(q.front());
        q.pop();
    }
    cout<<"Interleave_1st_and_2nd_half_of_queue"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<q.front()<<endl;
        q.pop();
    }
}