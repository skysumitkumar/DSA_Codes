#include<iostream>
using namespace std;
#include<stack>
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;// this is to find our stack is full or not if it give 0 so stack is full else stack is empty
    cout<<s.top();
}