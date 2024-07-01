#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node()
    {
        this->data=0;
        this->next=this;
    }
    Node(int data)
    {
        this->data=data;
        this->next=this;
    }
};
void print(Node* &head)
{
    Node* temp=head;
    cout<<temp->data<<" ";
    temp=temp->next;
    while(temp!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    Node* First=new Node(10);
    Node* second=new Node(20);
    Node* Third=new Node(30);
    Node* Forth=new Node(40);
    First->next=second;
    second->next=Third;
    Third->next=Forth;
    Forth->next=First;
    Node* tail=Forth;
    print(First);
    cout<<endl;
    cout<<"The next node of tail is: "<<tail->next->data;
    return 0;
}
