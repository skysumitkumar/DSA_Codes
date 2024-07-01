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
int FindLength(Node* head)
{
    Node* temp=head;
    int len=1;
    while(temp->next!=head)
    {
        len++;
        temp=temp->next;
    }
    return len;
}
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
    tail->next=newNode;
    head=newNode;
}
void InsertAtTail(Node* &head,Node* &tail,int data)
{
    if(head==NULL)
    {
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node* newNode=new Node(data);
    tail->next=newNode;
    newNode->next=head;
    tail=newNode;
}
void InsertAtPosition(Node* &head,Node* &tail,int data,int position)
{
    int len=FindLength(head);
    if(head==NULL)
    {
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    if(position<=1)
    {
        InsertAtHead(head,tail,data);
        return;
    }
    if(position>len)
    {
        InsertAtTail(head,tail,data);
        return;
    }
    Node* newNode=new Node(data);
    Node* prev=head;
    int i=1;
    while(i<position-1)
    {
        prev=prev->next;
        i++;
    }
    newNode->next=prev->next;
    prev->next=newNode;
}
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
    Node* First=new Node(30);
    Node* Second=new Node(40);
    First->next=Second;
    Second->next=First;
    Node* tail=Second;
    InsertAtHead(First,tail,20);
    InsertAtTail(First,tail,50);
    InsertAtPosition(First,tail,10,6);
    print(First);
    cout<<endl;
    cout<<"The node after the tail is : "<<tail->next->data;
    return 0;
}
