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
        this->next=NULL;
        this->prev=NULL;
    }
    Node(int data)
    {
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};
void print(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
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
    Node* tail=Fifth;
    print(First);
    cout<<endl;
    cout<<"previous node of tail is : "<<tail->prev->data;
    return 0;
}
