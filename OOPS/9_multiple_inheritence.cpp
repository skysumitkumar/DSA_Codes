#include<iostream>
using namespace std;
class Animal
{
    public:
    int size;
    int length;
};
class Animal_India
{
    public:
    int size1;
    int length1;
};
class NewAnimal:public Animal
{
    //here all Animal public member are inherited as publicly
};
// class NewAnimal:private Animal
// {
//     //here all Animal public member are inherited as private so we can't access these in out of the class 
      //if we want to access these we have to make getter and setter
// };
// class NewAnimal:protected Animal
// {
//     //here all Animal public member are inherited as protected
//     //so we can't access them out of the class if we want to access them so we want getter and setter
// };
class dog:private NewAnimal,private Animal_India
{
    public:
    void setsize(int size)
    {
        this->size=size;
    }
    int getsize()
    {
        return size;
    }
    void setsize1(int size)
    {
        this->size=size;
        this->size1=size;
    }
    int getsize1()
    {
        return size,size1;
    }
};
int main()
{
    dog a;
    a.setsize1(10);
    cout<<a.getsize1()<<endl;
}