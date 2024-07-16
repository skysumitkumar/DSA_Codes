#include<iostream>
using namespace std;
class Animal
{
    int weight=10;
    public:
    int size;
    string color;
    int setweight(int weight)
    {
        //when we use same name in the parameter and class use assign it by itself compiler confuse with this 
        //thing and can't assign any new value in it it give previous value of that 
        //weight=weight;
        //so to remove this confusion we use this keyword
        //this keyword points current ka object
        this->weight=weight;
    }
    int getweight()
    {
        return weight;
    }
};
int main()
{
    Animal a;
    a.setweight(50);
    cout<<a.getweight();
}