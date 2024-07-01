//problem on making the linked list
#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node* bottom;
    Node()
    {
        this->data=0;
        this->next=NULL;
        this->bottom=NULL;
    }
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->bottom=NULL;
    }
};

void InsertAtTailNext(Node* &head,Node* &tail,int data)
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
void InsertAtTailBottom(Node* &head,Node* &tail1,int data)
{
    if(head==NULL)
    {
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    Node* newNode=new Node(data);
    tail1->bottom=newNode;
    tail1=newNode;
}
void print(Node* &head)
{
    Node* temp=head;
    Node* temp1=head;
    while(temp!=NULL)
    {
        while(temp1!=NULL)
        {
            cout<<temp1->data<<" ";
            temp1=temp1->bottom;
        }
        temp=temp->next;
        temp1=temp;
    }
}
int main()
{
    Node* First=new Node(5);
    Node* tail=First;
    Node* tail1=First;
    InsertAtTailNext(First,tail,5);
    InsertAtTailBottom(First,tail1,5);
    print(First);
}
