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
    tail=newNode;
}
int FindLength(Node* head)
{
    Node* temp=head;
    int s=1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        s++;
    }
    return s;
}
void InsertAtPosition(Node* &head,Node* &tail,int position,int data)
{
    int len=FindLength(head);
    if(position<1||position>len)
    {
        cout<<"There is no node at this position"<<endl;
        return;
    }
    if(position==1)
    {
        InsertAtHead(head,tail,data);
        return;
    }

    /*if(position==len)
    {
        InsertAtTail(head,tail,data);
        return;
    }*/

    Node* newNode=new Node(data);
    Node* prev=head;
    int i=1;
    while(i<position-1)
    {
        i++;
        prev=prev->next;
    }
    newNode->next=prev->next;
    prev->next=newNode;
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
    Node* FirstNode=new Node(30);
    Node* Tail=FirstNode;
    InsertAtHead(FirstNode,Tail,20);
    InsertAtTail(FirstNode,Tail,50);
    InsertAtPosition(FirstNode,Tail,1,10);
    InsertAtPosition(FirstNode,Tail,4,40);
    InsertAtPosition(FirstNode,Tail,3,0);
    InsertAtPosition(FirstNode,Tail,0,60);
    InsertAtPosition(FirstNode,Tail,9,60);
    print(FirstNode);
    return 0;
}
/*
//This code is more accurate then previous one
#include<iostream>
using namespace std;
class Node
{
public:
    Node* next;
    int data;
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
int FindLength(Node* &head)
{
    Node* temp=head;
    int len=1;
    while(temp->next!=NULL)
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
    }
    Node* newNode=new Node(data);
    newNode->next=head;
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
    tail=newNode;
}
void InsertAtPosition(Node* &head,Node* &tail,int position,int data)
{
    int len=FindLength(head);
    if(position<1||position>len+1)
    {
        cout<<"There is no node at this position"<<endl;
        return;
    }
    if(position==1)
    {
        InsertAtHead(head,tail,data);
        return;
    }
    if(position==len+1)
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
void print(Node*  &head)
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
    Node* newNode=new Node(30);
    Node* tail=newNode;
    InsertAtHead(newNode,tail,20);
    InsertAtTail(newNode,tail,40);
    InsertAtPosition(newNode,tail,1,10);
    InsertAtPosition(newNode,tail,3,70);
    InsertAtPosition(newNode,tail,0,0);
    InsertAtPosition(newNode,tail,7,90);
    print(newNode);
    return 0;
}

*/
