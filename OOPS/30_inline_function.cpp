#include<iostream>
using namespace std;
// if we make this function inline than in compilation time compiler make it inline and paste value of num in main function
// we only use inline when our function is so small otherwise don't use it because it increase size of code
inline void print(int num)
{
    cout<<num<<endl;
}
int main()
{
    print(10);
    print(10);
    print(10);
    print(10);
    print(10);
    print(10);
}