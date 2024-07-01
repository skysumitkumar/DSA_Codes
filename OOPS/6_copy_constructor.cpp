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
        cout<<"paramatrize constructor called"<<endl;
        this->weight=weight;
        this->size=size;
        this->color=color;
    }
    //here we make copy constructor
    Animal(Animal &obj)//here we use by reference nahi to ye infine loop me chala jayega
    {
        cout<<"I am inside the copy constructor"<<endl;
        this->weight=obj.weight;
        this->size=obj.size;
        this->color=obj.color;
    }
    int setweight(int weight)
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
    // //here we make copy constructor using statically
    // Animal a(50,40,"brown");
    // //here b is this obj and a is obj that we pass here 
    // Animal b=a;
    // Animal c(b);
    // cout<<b.size<<endl;
    // cout<<c.size<<endl;
    // //it change the value of color index
    // b.color[1]='q';
    // cout<<b.color<<endl;
    // //but it cant change it here
    // cout<<c.color<<endl;

    // //here we make copy constructor using dynamically
    // Animal* dog = new Animal(85, 36, "white");
    // Animal* cat =  new Animal(30,21,"black");
    // cat=new Animal(*dog);// Use the copy constructor to copy the constructor of dog
    // //Animal* cat = new Animal(*dog);  // Use the copy constructor to create a new Animal
    // Animal* monkey = new Animal(*cat);  // Use the copy constructor for monkey as well
    // cout << cat->size << endl;
    // cout << monkey->color << endl;
    
    // //by using dynamically
    // Animal* dog=new Animal(85,36,"white");
    // Animal* cat=new Animal(30,21,"black");
    // //now copy the constructor value of dog in the cat constructor but cant call the copy constructor
    // cat=dog;//here it not going on copy constructor
    // Animal* monkey=cat;
    // //Animal* monkey(cat);//here it also not going on copy constructor
    // cout<<cat->size<<endl;
    // cout<<monkey->color;
    // //when you write cat = dog;, you are not actually copying the contents of the 
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
    //or we can use this but it call default constructor
    // Animal * mouse=new Animal;
    // *mouse=c;
    cout<<mouse->color<<endl;
    cout<<b.size<<endl;
}