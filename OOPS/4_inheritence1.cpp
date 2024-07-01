//important concept
#include<iostream>
using namespace std;
class father
{
    public:
    int age;
    int height;
    string color;
    string mood;
    //this is default constructor for father class if cant make it and inherit this class to another class it show error to no default constructor for father class
    father()
    {

    }
    father(int height,string color,int age,string mood)
    {
        this->height=height;
        this->color=color;
        this->age=age;
        this->mood=mood;
    }
    void sheight(int height)
    {
        this->height=height;
    }
    void gheight()
    {
        cout<<height<<endl;
        cout<<color<<endl;
        cout<<age<<endl;
        cout<<mood<<endl;
    }
};
class son:public father
{
    public:
    string name;
    string gf_name;
    //constructor
    //yha hame father ke constructor ki value bhi dani padegi tabhi father ki values son get kar paaega
    son(string name,string gf_name,int height,string color,int age,string mood): father(height,color,age,mood)//insilize father constructor
    {
        this->name=name;
        this->gf_name=gf_name;
    }
    
    // void mheight()
    // {
    //     cout<<height<<endl;
    //     cout<<color<<endl;
    //     cout<<age<<endl;
    //     cout<<mood<<endl;
    // }
};
int main()
{
    son a("amit","muskan",55,"brown",56,"hel");
    a.gheight();
}