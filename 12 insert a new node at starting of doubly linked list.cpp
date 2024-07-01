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
        this->next=NULL;
        this->prev=NULL;
    }
};
void InsertAtHead(Node* &head,Node* &tail,int data)
{
    if(head==NULL)
    {
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node* newNode=new Node(data);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}
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
    Node* First=new Node(20);
    Node* Second=new Node(10);
    First->next=Second;
    Second->prev=First;
    Node* tail=Second;
    InsertAtHead(First,tail,30);
    InsertAtHead(First,tail,40);
    InsertAtHead(First,tail,50);
    print(First);
    return 0;
}
