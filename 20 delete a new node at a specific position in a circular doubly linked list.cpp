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
        len++;
        temp=temp->next;
    }
    return len;
}
void deleteHead(Node* &head,Node* &tail)
{
    if(head==NULL)
    {
        cout<<"we cant delete no node is present"<<endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    head->prev=tail;
    tail->next=head;
    temp->next=NULL;
    temp->prev=NULL;
    delete temp;
}
void deleteTail(Node* &head,Node* &tail)
{
    if(head==NULL)
    {
        cout<<"we cant delete no node is present"<<endl;
        return;
    }
    Node* temp=tail;
    tail=tail->prev;
    tail->next=head;
    head->prev=tail;
    temp->next=NULL;
    temp->prev=NULL;
    delete temp;
}
void deletePosition(Node* &head,Node* &tail,int position)
{
    int len=FindLength(head);
    if(position<=1)
    {
        deleteHead(head,tail);
        return;
    }
    if(position>=len)
    {
        deleteTail(head,tail);
        return;
    }
    Node* left=head;
    int i=1;
    while(i<position-1)
    {
        left=left->next;
        i++;
    }
    Node* curr=left->next;
    left->next=curr->next;
    curr->next->prev=left;
    curr->prev=NULL;
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
    Second->prev=First;
    Second->next=Third;
    Third->prev=Second;
    Third->next=Forth;
    Forth->prev=Third;
    Forth->next=Fifth;
    Fifth->prev=Forth;
    Fifth->next=First;
    First->prev=Fifth;
    Node* tail=Fifth;
    deletePosition(First,tail,6);
    print(First);
    cout<<endl<<"First node is : "<<First->data<<endl;
    cout<<"Last node is : "<<tail->data;
    return 0;
}

