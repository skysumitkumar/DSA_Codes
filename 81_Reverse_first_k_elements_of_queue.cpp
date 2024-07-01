#include<iostream>
using namespace std;
#include<queue>
void reverse(queue<int> &q,int k)
{
    if(k==0)
    {
        return;
    }
    int temp=q.front();
    q.pop();
    reverse(q,--k);
    q.push(temp);
}
int main()
{
    queue<int>q;
    cout<<"Enter the size of the queue "<<endl;
    int n;
    cin>>n;
    cout<<"Enter the element in the queue "<<endl;
    int v;
    while(n--)
    {
        cin>>v;
        q.push(v);
    }
    cout<<endl<<"how many elements that you want to reverse "<<endl;
    int k;
    cin>>k;
    int rest=5-k;
    reverse(q,k);
    while(rest--)
    {
        int a=q.front();
        q.pop();
        q.push(a);
    }
    cout<<endl;
    while(!q.empty())
    {
        cout<<q.front();
        q.pop();
    }
}