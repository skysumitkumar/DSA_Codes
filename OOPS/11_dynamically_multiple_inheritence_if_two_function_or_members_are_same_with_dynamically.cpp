#include<iostream>
#include<string>
using namespace std;
class Animal
{
    public:
    int height;
    int size;
    int weight;
    string color;
    Animal()
    {
        cout<<"I Am In The Animal Constructor"<<endl;
    }
    void printcolor()
    {
        cout<<"i am in Animal class"<<endl;
        cout<<color<<endl;
    }
   virtual ~Animal(){}
};
class cat:public Animal
{
    public:
    int height;
    string color;
    cat()
    {
        cout<<"I Am In The Cat Constructor"<<endl;
    }
    void printcolor()
    {
        cout<<"i am in cat class"<<endl;
        cout<<color<<endl;
    }
};
// Upcasting and Downcasting
// Upcasting: Converting a derived class pointer or reference to a base class pointer or reference. 
//            This is always safe and does not require any explicit casting.
// Downcasting: Converting a base class pointer or reference to a derived class pointer or reference. 
//              This is potentially unsafe and requires runtime checking to ensure that the object being pointed to is actually of the derived type.
int main()
{   
    // //upstreaming
    // //firstly we use cat class reference and cat class obj
    // cat *c=new cat;
    // c->Animal::color="black";
    // c->cat::color="brown";
    // c->printcolor();
    
    // //upstreaming
    // //here we use Animal class reference and Animal class obj
    // Animal * c=new Animal;
    // c->color="black";
    // //here we can't assign in the cat class because animal class not inherit cat class
    // //c->cat::color="brown";
    // c->printcolor();

    // // upstreaming
    // //here we use Animal class reference and cat class obj we firstly create cat object and then assigns it to an Animal pointer(reference)
    // Animal * c=new cat;
    // It call reference class members and methods
    // c->color="black";
    // //when we are assigning value to cat class it give error because here we make Animal class obj and Animal class not inherited cat class
    // //c->cat::color="brown";
    // If we want to change the member variable value of the cat class we have to use getter and setter
    // c->printcolor();
    // //when we want to call  print color of cat class than we have to use virtual keyword in Animal class to enable polymorphism than it go to print color of the cat class
    // //c->printcolor();

    //downstreaming
    //here we use cat class reference and Animal class object
    //it give error when we use previous method for downstreaming
    //cat *c=new Animal;
    //for downstreaming we use this
    // This line uses a C-style cast to forcefully convert an Animal pointer to a Cat pointer. This is 
    // extremely unsafe because it does not check whether the object being pointed to is actually of the derived type Cat. This can lead 
    // to undefined behavior when trying to access or modify members specific to Cat.
    // cat* c=(cat*) new Animal;
    // to do it correctly we use upcast then downcast
    // Why Use a?: a is a pointer to Animal, but it actually points to a Cat object. By using dynamic_cast<cat*>(a), you are checking 
    //             at runtime if a indeed points to an object of type cat. If it does, c will be a valid pointer to cat; otherwise, c will be nullptr.
    // How dynamic_cast Works: dynamic_cast checks the actual type of the object pointed to by a. If a points to an object of 
    //                         type cat (or a type derived from cat), the cast succeeds, and c points to that cat object. If not, c is set to nullptr.
    Animal* a = new cat(); // Correct upcasting, cat is a type of Animal it calls animal constructor
    cat* c = dynamic_cast<cat*>(a); // Safe downcasting it calls cat constructor
    // c->color="brown";
    // c->Animal::color="black";
    // c->printcolor();
    if(c!=nullptr) 
    {
    // Successfully downcasted to cat
    c->cat::color="brown";
    // It change the color of the Animal class because cat class inherit Animal class
    c->Animal::color="black";
    c->color="pink";//it change the cat color
    c->printcolor();//it print the cat color
    c->Animal::printcolor();
    delete c;  // Don't forget to delete the dynamically allocated object
    } 
    else 
    {
    // Failed to downcast, handle the error
    delete c;  // Delete the object since it's not a cat
    }

}
//upcasting
// #include<iostream>
// #include<string>
// using namespace std;
// class Animal
// {
//     public:
//     int height;
//     int size;
//     int weight;
//     string color="pink";
//     Animal()
//     {
//         cout<<"I Am In The Animal Constructor"<<endl;
//     }
//     void printcolor()
//     {
//         cout<<"i am in Animal class"<<endl;
//         cout<<color<<endl;
//     }
//    virtual ~Animal(){}
// };
// class cat:public Animal
// {
//     public:
//     int height;
//     string color="BLUE";
//     cat()
//     {
//         cout<<"I Am In The Cat Constructor"<<endl;
//     }
//     void printcolor()
//     {
//         cout<<"i am in cat class"<<endl;
//         cout<<color<<endl;
//     }
// };
// int main()
// {   
//     Animal * c=new cat;
// It call reference class member and methods
//     cout<<c->color<<endl; //pink
//     c->printcolor();      //pink
// }

// #include<iostream>
// #include<string>
// using namespace std;
// class Animal
// {
//     public:
//     int height;
//     int size;
//     int weight;
//     string color="pink";
//     Animal()
//     {
//         cout<<"I Am In The Animal Constructor"<<endl;
//     }
//     virtual void printcolor()
//     {
//         cout<<"i am in Animal class"<<endl;
//         cout<<color<<endl;
//     }
//    virtual ~Animal(){}
// };
// class cat:public Animal
// {
//     public:
//     int height;
//     string color="BLUE";
//     cat()
//     {
//         cout<<"I Am In The Cat Constructor"<<endl;
//     }
//     void printcolor()
//     {
//         cout<<"i am in cat class"<<endl;
//         cout<<color<<endl;
//     }
// };
// int main()
// {   
//     Animal * c=new cat;
//     cout<<c->color<<endl; //pink 
// When we use virtual it call object class functions 
//     c->printcolor();      //BLUE
// }

// //downcasting
// #include<iostream>
// #include<string>
// using namespace std;
// class Animal
// {
//     public:
//     int height;
//     int size=50;
//     int weight;
//     string color="pink";
//     Animal()
//     {
//         cout<<"I Am In The Animal Constructor"<<endl;
//     }
//     void printcolor()
//     {
//         cout<<"i am in Animal class"<<endl;
//         cout<<color<<endl;
//     }
//    virtual ~Animal(){}
// };
// class cat:public Animal
// {
//     public:
//     int height;
//     int size=60;
//     string color="blue";
//     cat()
//     {
//         cout<<"I Am In The Cat Constructor"<<endl;
//     }
//     void printcolor()
//     {
//         cout<<"i am in cat class"<<endl;
//         cout<<color<<endl;
//     }
// };
// int main()
// {  
//     Animal* a = new cat(); // Correct upcasting, cat is a type of Animal it calls animal constructor
//     cat* c = dynamic_cast<cat*>(a); // Safe downcasting it calls cat constructor
//     if(c!=nullptr) 
//     {
//         //It call reference class members and methods
//         cout<<c->color<<endl;
//         c->printcolor();
//     delete c;  // Don't forget to delete the dynamically allocated object
//     } 
//     else 
//     {
//     // Failed to downcast, handle the error
//     delete c;  // Delete the object since it's not a cat
//     }
// }

// #include<iostream>
// #include<string>
// using namespace std;
// class Animal
// {
//     public:
//     int height;
//     int size=50;
//     int weight;
//     string color="pink";
//     Animal()
//     {
//         cout<<"I Am In The Animal Constructor"<<endl;
//     }
//     virtual void printcolor()
//     {
//         cout<<"i am in Animal class"<<endl;
//         cout<<color<<endl;
//     }
//    virtual ~Animal(){}
// };
// class cat:public Animal
// {
//     public:
//     int height;
//     int size=60;
//     string color="blue";
//     cat()
//     {
//         cout<<"I Am In The Cat Constructor"<<endl;
//     }
//     void printcolor()
//     {
//         cout<<"i am in cat class"<<endl;
//         cout<<color<<endl;
//     }
// };
// int main()
// {  
//     Animal* a = new cat(); // Correct upcasting, cat is a type of Animal it calls animal constructor
//     cat* c = dynamic_cast<cat*>(a); // Safe downcasting it calls cat constructor
//     if(c!=nullptr) 
//     {
//         //In case of virtual in any class it call reference class member and methods
//         cout<<c->color<<endl;
//         c->printcolor();
//     delete c;  // Don't forget to delete the dynamically allocated object
//     } 
//     else 
//     {
//     // Failed to downcast, handle the error
//     delete c;  // Delete the object since it's not a cat
//     }
// }
