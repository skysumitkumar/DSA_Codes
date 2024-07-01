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
int FindLength(Node* head)
{
    Node* temp=head;
    int len=1;
    while(temp->next!=head)
    {
        temp=temp->next;
        len++;
    }
    return len;
}
void deleteAtHead(Node* &head,Node* &tail)
{
    if(head==NULL)
    {
        cout<<"we have no node to delete"<<endl;
        return;
    }
    Node* temp=head;
    tail->next=head->next;
    head=head->next;
    temp->next=NULL;
    delete temp;
}
void deleteAtTail(Node* &head,Node* &tail)
{
    if(head==NULL)
    {
        cout<<"we have no node to delete"<<endl;
        return;
    }
    Node* prev=head;
    while(prev->next!=tail)
    {
        prev=prev->next;
    }
    prev->next=head;
    tail->next=NULL;
    delete tail;
    tail=prev;
}
void deleteAtPosition(Node* &head,Node* &tail,int position)
{
    int len=FindLength(head);
    if(position<=1)
    {
        deleteAtHead(head,tail);
        return;
    }
    if(position>=len)
    {
        deleteAtTail(head,tail);
        return;
    }
    Node* prev=head;
    int i=1;
    while(i<position-1)
    {
        prev=prev->next;
        i++;
    }
    Node* curr=prev->next;
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
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
    Node* Third=new Node(30);
    Node* Forth=new Node(40);
    Node* Fifth=new Node(50);
    First->next=Second;
    Second->next=Third;
    Third->next=Forth;
    Forth->next=Fifth;
    Fifth->next=First;
    Node* tail=Fifth;
    //deleteAtHead(First,tail);
    //deleteAtTail(First,tail);
    deleteAtPosition(First,tail,6);
    print(First);
    cout<<endl;
    cout<<"node after tail is : "<<tail->next->data;
    return 0;
}
