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
    newNode->prev=tail;
    head->prev=newNode;
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
    newNode->prev=tail;
    newNode->next=head;
    head->prev=newNode;
    tail=newNode;
}
void InsertAtPosition(Node* &head,Node* &tail,int data,int position)
{
    int len=FindLength(head);
    if(position<1||position>len)
    {
        cout<<"This position doesn't exist"<<endl;
        return;
    }
    if(position==1)
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
    Node* left=head;
    int i=1;
    while(i<position-1)
    {
        left=left->next;
        i++;
    }
    newNode->prev=left;
    newNode->next=left->next;
    left->next=newNode;
    newNode->next->prev=newNode;
}
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
    First->next=Second;
    Second->prev=First;
    Second->next=First;
    First->prev=Second;
    Node* tail=Second;
    InsertAtHead(First,tail,30);
    InsertAtTail(First,tail,40);
    InsertAtPosition(First,tail,90,5);
    print(First);
    cout<<endl<<"First node is: "<<First->data<<endl;
    cout<<"Last node is : "<<tail->data;
    return 0;
}
