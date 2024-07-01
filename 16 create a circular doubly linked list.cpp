#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    Node()
    {
        this->data=0;
        this->next=this;
        this->prev=this;
    }
    Node(int data)
    {
        this->data=data;
        this->next=this;
        this->prev=this;
    }
};
void print(Node* head)
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
    Node* Second=new Node(20);
    Node* Third=new Node(30);
    Node* Forth=new Node(40);
    Node* Fifth=new Node(50);
    First->next=Second;
    Second->prev=First;
    Second->next=Third;
    Third->prev=Second;
    Third->next=Forth;
    Forth->prev=Third;
    Forth->next=Fifth;
    Fifth->prev=Forth;
    Fifth->next=First;
    First->prev=Fifth;
    Node* Tail=Fifth;
    print(First);
    cout<<endl;
    cout<<"First node is : "<<First->data<<endl;
    cout<<"Tail node is : "<<Tail->data<<endl;
    return 0;
}
