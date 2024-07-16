//operate that are not overload
//sizeof
//typeid
//Scope resolution (::)
//Class member access operators (.(dot), .* (pointer to member operator))
//Ternary or conditional (?:)


//Operators that can be overloaded	Examples
// Binary Arithmetic	+, -, *, /, %
// Unary Arithmetic 	+, -, ++, —
// Assignment	        =, +=,*=, /=,-=, %=
// Bitwise	            & , | , << , >> , ~ , ^
// De-referencing	    (->)
// Dynamic memory allocation,
// De-allocation	    New, delete 
// Subscript	        [ ]
// Function call 	    ()
// Logical 	            &,  | |, !
// Relational	        >, < , = =, <=, >=


// Restrictions
// The operators :: (scope resolution), . (member access), .* (member access through pointer to member), and ?: (ternary conditional) cannot be overloaded.
// New operators such as **, <>, or &| cannot be created.
// It is not possible to change the precedence, grouping, or number of operands of operators.
// The overload of operator -> must either return a raw pointer, or return an object (by reference or by value) for which operator -> is in turn overloaded.
// The overloads of operators && and || lose short-circuit evaluation.
// &&, ||, and , (comma) loose their special sequencing properties when overloaded and behave like regular function calls even when they are used without function-call notation.

// #include<iostream>
// using namespace std;
// class Sum
// {
//     public:
//     int a;
//     //here this is happened a.add(b)  here a is current object, add is function call in parameter or member function and b is input parameter
//     void operator+(Sum& obj1)
//     {
//         //int val=a;
//         //here we also use this keyword here this keyword points to current object and here current object is obj
//         int val=this->a;
//         //but we cant use -> here because here obj1 is a object not a pointer
//         int val1=obj1.a;
//         cout<<(val-val1)<<endl;
//     }
// };
// int main()
// {
//     Sum obj,obj1;
//     obj.a=5;
//     obj1.a=6;
//     //here we add both the object
//     //cout<<obj.a+obj1.a<<endl;//here it give 11
//     //but when we add objects than it does nothing and also not give any error
//     //obj.a+obj1.a;
//     //here this is happened a.add(b)  here a is current object, add is function call in parameter or member function and b is input parameter
//     //but we want when we add it it give difference so we have to overload + operator
//     obj+obj1;//here it give -1
//     return 0;
// }


// #include<iostream>
// using namespace std;
// class Sum
// {
//     public:
//     int no1;
//     int no2;
//     int operator+(Sum & obj)
//     {
//         int val1=this->no1;
//         int val2=obj.no2;
//         return (val1-val2);
//     }
//     int operator-(Sum &obj);
// };
// //here i use class function by using class name with scope resolution 
// int Sum::operator-(Sum &obj)
// {
//     int val1=this->no1;
//     int val2=obj.no2;
//     return (val1+val2);
// }
// int main()
// {
//     Sum obj1,obj2;
//     obj1.no1=5;
//     obj2.no2=6;
//     cout<<obj1+obj2<<endl;
//     cout<<obj1-obj2;
//     return 0;
// }


// #include<iostream>
// using namespace std;
// class Sum
// {
//     public:
//     int no1;
//     int no2;
//     int operator+=(Sum&obj)
//     {
//         int val1=this->no1;
//         int val2=obj.no1;
//         return (val1-val2);
//         //cout<<(val1-val2);
//     }
//     // here we return int not an object
//     int operator+=(int obj)
//     {
//         int val1=this->no1;
//         int val2=obj;
//         return (val1-val2);
//         //cout<<(val1-val2);
//     }
//     int operator-=(int obj);
// };
// int Sum::operator-=(int obj)
// {
//     int val1=this->no1;
//     int val2=obj;
//     return (val1+val2);
// }
// int main()
// {
//     Sum obj1,obj2;
//     obj1.no1=5;
//     obj2.no1=6;
//     int n=6;
//     int x=obj1+=obj2;//it gives -1
//     cout<<x<<endl;
//     int y=obj1+=n;//it gives -1
//     cout<<y<<endl;
//     int z=obj1-=n;//it gives 11
//     cout<<z;
// }



// #include<iostream>
// using namespace std;
// class Sum
// {
//     public:
//     int no1;
//     int no2;
//     int operator++()//remember here to not give any parameter 
//     {
//         no1-=1;
//         //we also write like this
//         //no1=this->no1-1;
//         return no1;
//     }
//     friend int operator--(Sum &obj);
// };
// //when we make this function to the friend of our class we don't have need to use scope resolution operator
// int operator--(Sum &obj)
// {
//     obj.no1+=1;
//     return obj.no1;
// }
// int main()
// {
//     Sum obj1,obj2;
//     obj1.no1=5;
//     cout<<++obj1<<endl;
//     cout<<--obj1<<endl;
// }



// #include<iostream>
// using namespace std;
// class Sum
// {
//     public:
//     int no1;
//     int no2;
//     Sum operator++(int obj)
//     {
//         Sum duplicate(*this);
//         no1-=1;
//         return duplicate;
//     }
//     void print()
//     {
//         cout<<no1<<endl;
//     }
//     friend Sum operator--(Sum &obj,int);
// };
// Sum operator--(Sum &obj,int)
// {
//     Sum duplicate(obj);
//     obj.no1+=1;
//     return duplicate;
// }
// int main()
// {
//     Sum obj1;
//     obj1.no1=5;
//     obj1.print();
//     (obj1++).print();
//     (obj1--).print();
//     (obj1++).print();
//     obj1.print();
// }


// #include<iostream>
// using namespace std;
// class Sum
// {
//     public:
//     int no[3];
//     Sum(int no1,int no2,int no3)
//     {
//         this->no[0]=no1;
//         this->no[1]=no2;
//         this->no[2]=no3;
//     }
//   //The interesting part is the operator[] overload. This is a special member function that allows objects 
//   //of the Sum class to be indexed like an array. In other words, it allows you to use the [] operator on an object of type Sum, like obj1[2].
//     int operator[](int obj)
//     {
//         return no[obj];
//     }
// };

// int main()
// {
//     Sum obj1(10,20,30);
//     cout<<obj1[2];
// }



// #include<iostream>
// using namespace std;
// class Sum
// {
//     public:
//     int no1;
//     int no2;
//     Sum(int a)
//     {
//         no1=a;
//     }
//     Sum operator()(int obj)
//     {
//         no1=obj;
//         cout<<no1;
//         return *this;
//     }  
// };
// int main()
// {
//     Sum obj1(30);
//     obj1(50);
//     return 0;
// }


// #include<iostream>
// using namespace std;
// class Sum
// {
//     public:
//     int no1;
//     int no2;
//     Sum(int a)
//     {
//         no1=a;
//     }
//     Sum *operator->()
//     {
//         return this;
//     }
//     void print()
//     {
//         cout<<no1<<endl;
//     }
// };

// int main()
// {
//     Sum obj1(66);
//     obj1->print();
//     return 0;
// }


// #include<iostream>
// using namespace std;
// class Sum
// {
//     public:
//     string name;
//     int age;
//     Sum(string name,int age)
//     {
//         this->name=name;
//         this->age=age;
//     }
//     void *operator new(size_t size)
//     {
//         void *pointer;
//         cout<<"Allocating "<<size<<" bytes of memory"<<endl;
//         pointer=malloc(size);
//         if(!pointer)
//         {
//             bad_alloc ba;
//             throw ba;
//         }
//         return pointer;
//     }    
//     void print()
//     {
//         cout<<" name is "<<name<<", age is "<<age<<endl;
//     }
// };
// int main()
// {
//     Sum *obj1;
//     try{
//         obj1=new Sum("sumit",24);
//         obj1->print();
//         delete obj1;
//     }
//     catch(bad_alloc b)
//     {
//         cout<<b.what()<<endl;
//     }
// }



#include<iostream>
using namespace std;
class Sum
{
    public:
    int age;
    string name;
    Sum()
    {
        name="sumit";
        age=24;
    }
    friend ostream &operator<<(ostream &output,Sum &obj);
    friend istream &operator<<(istream &output,Sum &obj);
};
ostream &operator<<(ostream &output,Sum & obj)
{
    output<<"my name is "<<obj.name<<"and my age is "<<obj.age<<endl;
    return output;
}
istream &operator>>(istream &input,Sum &obj)
{
    input>>obj.name>>obj.age;
    return input;
}
int main()
{
    cout<<"enter the name and age "<<endl;
    Sum obj1;
    cin>>obj1;
    cout<<obj1;
    return 0;
}




