#include<iostream>
using namespace std;
#include"28_bird.h"
// here we make a function that call the interface class function
void birddoesSomething(Bird* &bird)
{
    bird->eat();
    bird->fly();
}
int main()
{
    Bird *bird=new sparrow();
    //we use this or we call our function birddoesSomething direct
    //bird->eat();
    // here we make a obj of sparrow class but it won't work we have to call only from Bird because our interface is bird
    //sparrow *p=new sparrow();
    //p->eat();
    birddoesSomething(bird);
    Bird *bird1=new eagle();
    // but when we make eagle implementation to private than we can't call anything from the object we call it only by the bird interface
    // eagle *p1=new eagle();
    // p1->eat();
    Bird *b2=new eagle();
    birddoesSomething(b2);

    // kesi bhi abstract class ka ya c++ interface ka object nahi ban sakta
    // Bird *b3=new Bird();
    return 0;
}