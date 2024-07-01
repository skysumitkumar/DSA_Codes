#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* prev;
    Node* next;
    Node()
    {
        this->data=0;
        this->prev=NULL;
        this->next=NULL;
    }
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
int FindLength(Node* head)
{
    Node* temp=head;
    int len=1;
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
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
    }
    Node* newNode=new Node(data);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}
void InsertAtTail(Node* &head,Node* &tail,int data)
{
    if(head==NULL)
    {
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    Node* newNode=new Node(data);
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
}
void InsertAtPosition(Node* &head,Node* &tail,int data,int position)
{
    int len=FindLength(head);
    if(position<1||position>len)
    {
        cout<<"This position does'not exist"<<endl;
        return;
    }
    if(position==1)
    {
        InsertAtHead(head,tail,data);
        return;
    }
    if(position==len)
    {
        InsertAtTail(head,tail,data);
        return;
    }
    Node* newNode=new Node(data);
    Node* left=head;
    int i=1;
    while(i<position-1)
    {
        left=left->next;
        i++;
    }
    newNode->next=left->next;
    left->next->prev=newNode;
    newNode->prev=left;
    left->next=newNode;
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
    Node* Second=new Node(30);
    First->next=Second;
    Second->prev=First;
    Node* tail=Second;
    InsertAtHead(First,tail,10);
    InsertAtTail(First,tail,40);
    InsertAtPosition(First,tail,90,5);
    print(First);
    cout<<endl;
    cout<<"Head is: "<<First->data;
    cout<<endl;
    cout<<"Tail is: "<<tail->data;
    return 0;
}
