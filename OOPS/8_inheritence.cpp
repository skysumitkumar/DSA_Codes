//inherited class that are in public
#include<iostream>
using namespace std;
class Animal
{
    public:
    int size;
    int length;
};
class NewAnimal:public Animal
{
    //here all Animal public member are inherited as publically
};
// class NewAnimal:private Animal
// {
//     //here all Animal public member are inherited as privated so we cant access these in out of the class 
      //if we want to access these we have to make getter and setter
// };
// class NewAnimal:protected Animal
// {
//     //here all Animal public member are inherited as protected
//     //so we cant access them out of the class if we want to access them so we want getter and setter
// };
int main()
{
    NewAnimal a;
    //public members are inherited as publically,protected and privatelly
    cout<<a.size<<endl;
}

// //inherit class that are in private
// #include<iostream>
// using namespace std;
// class Animal
// {
//     int size;
//     int height;
//     string name;
//     int height;
//     int length;
// };
// // class NewAnimal:public Animal
// // {
// //     //we cant inherit private members public
// // };
// // class NewAnimal:private Animal
// // {
// //     //we cant inherit private members private
// // };
// class NewAnimal:protected Animal
// {
//     //we cant inherit private members as protected
// };
// int main()
// {
//     NewAnimal a;
//     //   we cant inherit private members from any class
//     cout<<a.size<<endl;
// }

// //inherit class that are in protected
// #include<iostream>
// using namespace std;
// class Animal
// {
//     protected:
//     int size;
//     int height;
//     string name;
//     int height;
//     int length;
// };
// class NewAnimal:public Animal
// {
//     //here all Animal protected member are inherited as privatelly so we cant access these in out of the class
// };
// class NewAnimal:private Animal
// {
//     //here all Animal proteced member are inherited as privated so we cant access these in out of the class 
//       //if we want to access these we have to make getter and setter
// };
// class NewAnimal:protected Animal
// {
//     //here all Animal protected member are inherited as privatelly so we cant access these in out of the class
// };
// int main()
// {
//     NewAnimal a;
//        //we cant access protected and privated members without getter and setter
//     cout<<a.size<<endl;
// }