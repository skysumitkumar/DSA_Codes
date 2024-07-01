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
        this->next=NULL;
    }
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
int FindLength(Node* head)
{
    Node* temp=head;
    int len=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
    return len;
}
Node* GoToTailPrev(Node* &head,Node* &tail)
{
    Node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    return temp;
}
void Rotate(Node* &head,Node* &tail,int k)
{
    if(head==NULL)
    {
        cout<<"we have no linked list here"<<endl;
        return;
    }
    int len=FindLength(head);
    if(k%len==0)
    {
        return ;
    }
    k=k%len;
    int a=len-k-1;
    Node* temp=head;
    while(a!=0)
    {
        temp=temp->next;
        a--;
    }
    Node* newHead=temp->next;
    temp->next=NULL;
    tail->next=head;
    temp=tail;
    head=newHead;
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
    tail=newNode;
}
void print(Node* &head)
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
    Node*  First=new Node(10);
    Node* tail=First;
    InsertAtTail(First,tail,20);
    InsertAtTail(First,tail,30);
    //InsertAtTail(First,tail,40);
    //InsertAtTail(First,tail,50);
    //InsertAtTail(First,tail,60);
    //InsertAtTail(First,tail,70);
    //InsertAtTail(First,tail,80);
    //InsertAtTail(First,tail,90);
    //InsertAtTail(First,tail,100);
    Rotate(First,tail,2);
    print(First);
    return 0;
}
