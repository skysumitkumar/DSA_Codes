#include<iostream>
using namespace std;
#include<queue>
void reverse(queue<int> &q)
{
    if(q.empty())
    {
        return;
    }
    int temp=q.front();
    q.pop();
    reverse(q);
    q.push(temp);
}
int main()
{
    queue<int>q;
    cout<<"Enter the size of the queue ";
    int n,v;
    cin>>n;
    cout<<"Enter the elements in the queue "<<endl;
    while(n--)
    {
        cin>>v;
        q.push(v);
    }
    reverse(q);
    while(!q.empty())
    {
        cout<<q.front();
        q.pop();
    }
}
// #include<iostream>
// using namespace std;
// #include<queue>
// #include<stack>
// int main()
// {
//     queue<int> q;
//     stack<int> s;
//     cout<<"Enter the size of the queue "<<endl;
//     int n,a;
//     cin>>n;
//     while(n--)
//     {
//         cin>>a;
//         q.push(a);
//     }
//     cout<<endl;
//     while(!q.empty())
//     {
//         int b=q.front();
//         q.pop();
//         s.push(b);
//     }
//     while(!s.empty())
//     {
//         int b=s.top();
//         s.pop();
//         q.push(b);
//     }
//     while(!q.empty())
//     {
//         cout<<q.front();
//         q.pop();
//     }
// }