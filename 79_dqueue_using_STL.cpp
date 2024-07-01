#include<iostream>
using namespace std;
#include<deque>
int main()
{
    deque<int> s(5);
    s.push_front(5);
    s.push_back(6);
    s.push_front(7);
    s.push_back(8);
    s.push_front(9);
    //s.push_back(10);
    
    //cout<<s.size()<<endl;
    s.pop_front();
    s.pop_back();
    cout<<s.front()<<endl;
    cout<<s.empty();
}
