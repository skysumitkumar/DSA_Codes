#include<iostream>
using namespace std;
class Animal
{
    int weight;
    public:
    int size;
    string color;
    int setweight(int w)
    {
        weight=w;
    }
    int getweight()
    {
        return weight;
    }
};
int main()
{
    Animal a;
    //Dynamic memory
    Animal *dog=new Animal;
    //we cant set or get vlaue with the help of previous method(.) 
    //dog.size(); //when we use this this give error because dog give adderess but we assign or get int from that
    //so we use this to remove our error and assign int value
    (*dog).size=10;
    cout<<(*dog).size<<endl;
    (*dog).setweight(50);
    //insted of this we also use -> but we cant use it with the statc values we only use it with the dynamic pointer
    dog->setweight(60);
    cout<<(*dog).getweight()<<endl;
    //but when we call static object to get weight than we assign with dynamic object it cant assign any value in it and show garbadge value
    cout<<a.getweight()<<endl;
    //cout<<a.size;
}