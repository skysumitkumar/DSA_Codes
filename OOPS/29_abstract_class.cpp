#include<iostream>
using namespace std;
#include"28_bird.h"
//here we make a function that call the interface class function
void birddoesSomething(Bird* &bird)
{
    bird->eat();
    bird->fly();
}
int main()
{
    Bird *bird=new sparrow();
    //here we make a obj of sparrow class
    sparrow *p=new sparrow();
    p->eat();
    birddoesSomething(bird);
    Bird *bird1=new eagle();
    //but when we make eagle implementation to private than we cant call anything from the object we call it only by the bird interface
    // eagle *p1=new eagle();
    // p1->eat();


    //kesi bhi abstract class ka ya c++ interface ka object nahi ban sakta
    //Bird *b2=new Bird();
    return 0;
}