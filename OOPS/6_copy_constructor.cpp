#include<iostream>
using namespace std;
class Animal
{
    int weight=10;
    public:
    int size;
    string color;
    Animal()
    {
        cout<<"default constructor called"<<endl;
    }
    Animal(int weight,int size,string color)
    {
        cout<<"parametrize constructor called"<<endl;
        this->weight=weight;
        this->size=size;
        this->color=color;
    }
    //here we make copy constructor
    Animal(Animal &obj)//here we use by reference nahi to ye infinite loop me chala jaayega
    {
        cout<<"I am inside the copy constructor"<<endl;
        this->weight=obj.weight;
        this->size=obj.size;
        this->color=obj.color;
    }
    // assignment operator if we can't make it compiler by default make it and assign values
    Animal& operator=(const Animal& obj) 
    {
        cout<<"I am inside the assignment operator"<<endl;
        if (this!= &obj) 
        {
            this->weight = obj.weight;
            this->size = obj.size;
            this->color = obj.color;
        }
        return *this;
    }
    void setweight(int weight)
    {
        this->weight=weight;
    }
    int getweight()
    {
        return weight;
    }
};
int main()
{
    // //here parametrize constructor is called
    // Animal a(50,40,"brown");
    // // here default constructor is called
    // // Animal b;
    // // here assignment operator is called to assign a to b this is know as copy assignment
    // // b=a;
    // // here we call copy constructor
    // //here b is this obj and a is obj that we pass here 
    // Animal b=a;
    // Animal c(b);
    // cout<<b.size<<endl;
    // cout<<c.size<<endl;
    // //it change the value of color index
    // b.color[1]='q';
    // cout<<b.color<<endl;
    // //but it can't change it here
    // cout<<c.color<<endl;

    // //here we make copy constructor using dynamically(this is the right way to copy constructor dynamically)
    // Animal* dog=new Animal(85,36,"white");
    // Animal* cat=new Animal(30,21,"black");
    // cat=new Animal(*dog);// Use the copy constructor to copy the constructor of dog
    // //Animal* cat=new Animal(*dog);  // Use the copy constructor to create a new Animal
    // Animal* monkey=new Animal(*cat);  // Use the copy constructor for monkey as well
    // // when we write like this it also call copy constructor it is different than static constructor here assignment operator is not call remember
    // // Animal* monkey;
    // // monkey=new Animal(*dog);
    // cat->color="red";
    // cout<<cat->size<<endl;
    // cout<<monkey->color<<endl;
    
    // //by using dynamically(wrong way it can't copy)
    // Animal* dog=new Animal(85,36,"white");
    // Animal* cat=new Animal(30,21,"black");
    // //now copy the constructor value of dog in the cat constructor but can't call the copy constructor
    // //cat=dog;//here it not going on copy constructor it just point the value of dog it can't copy the values of dog
    // Animal* monkey=cat;//here it not going on copy constructor it just point the value of cat it can't copy the values of cat
    // //Animal* monkey(cat);//here it not going on copy constructor it just point the value of cat it can't copy the values of cat
    // // here we change the size of cat but it also change the size of the dog because it point to the same location
    // cat->size=10;
    // cout<<monkey->size<<endl;
    // cat->color="pink";
    // cout<<cat->size<<endl;
    // cout<<monkey->color;
    // //when you write cat = dog;, you are not actually copying the contents of the dog
    // //Animal object pointed to by dog into the Animal object pointed to by cat. 
    // //Instead, you are making cat point to the same object as dog. This results in a memory leak because the original Animal object that cat was pointing to is not being properly deallocated.

    //by using both dynamically and static
    Animal c(46,85,"pink");
    Animal * dog=new Animal(555,45,"black");
    //ham static object ke constructor me dynamic obj ke constructor ko copy kar sakte h
    Animal b=*dog;
    cout<<b.color<<endl;
    //dynamic oject ke constructor me static obj ke constructor ko copy
    Animal * mouse=new Animal(c);
    // this call default constructor
    // Animal * mouse=new Animal;
    // this call assignment operator
    // *mouse=c;
    cout<<mouse->color<<endl;
    cout<<b.size<<endl;
}
