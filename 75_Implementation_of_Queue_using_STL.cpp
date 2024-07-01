#include<iostream>
using namespace std;
#include<queue>
int main()
{
    queue<int> s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.pop();
    // cout<<s.size()<<endl;
    // cout<<s.back()<<endl;
    cout<<s.front()<<endl;
    cout<<s.empty()<<endl;
}