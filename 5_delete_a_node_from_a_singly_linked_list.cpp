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
    ~Node()
    {
        int val=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
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
void deleteHead(Node* &head,Node* &tail)
{
    if(head==NULL)
    {
        cout<<"There is no node here to delete here id NULL"<<endl;
        return;
    }
    Node* temp=head;
    head=temp->next;
    temp->next=NULL;
    delete temp;
}
void deleteTail(Node* &head,Node* &tail)
{
    if(head==NULL)
    {
        cout<<"There is no node here to delete here id NULL"<<endl;
        return;
    }
    Node* temp=head;
    int len=FindLength(head);
    int i=1;
    while(i<len-1)
    {
        temp=temp->next;
        i++;
    }
    temp->next=NULL;
    delete tail;
    tail=temp;
}

void deletePosition(Node* &head,Node* &tail,int position)
{
    int len=FindLength(head);
    if(position<1||position>len)
    {
        cout<<"There is no node at this position"<<endl;
        return;
    }
    if(position==1)
    {
        deleteHead(head,tail);
        return;
    }
    if(position==len)
    {
        deleteTail(head,tail);
        return;
    }
    Node* temp=head;
    int i=1;
    while(i<position-1)
    {
        temp=temp->next;
        i++;
    }
    Node* curr=temp->next;
    temp->next=curr->next;
    curr->next=NULL;
    delete curr;

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
    InsertAtTail(newNode,tail,50);
    InsertAtPosition(newNode,tail,1,10);
    InsertAtPosition(newNode,tail,4,40);
    //deleteHead(newNode,tail);
    //deleteTail(newNode,tail);
    deletePosition(newNode,tail,2);
    print(newNode);
    return 0;
}
