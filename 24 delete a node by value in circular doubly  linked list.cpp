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
        temp=temp->next;
        len++;
    }
    return len;
}
void deleteByValue(Node* &head,Node* &tail,int val)
{
    int i,len=FindLength(head);
    if(head==NULL)
    {
        cout<<"Currenty no node is present in list"<<endl;
        return;
    }
    if(val==head->data)
    {
        Node* temp=head;
        head=head->next;
        head->prev=tail;
        tail->next=head;
        temp->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }
    if(val==tail->data)
    {
        Node* temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        temp->next=head;
        head->prev=temp;
        tail->next=NULL;
        tail->prev=NULL;
        delete tail;
        tail=temp;
        return;
    }
    Node* temp=head;
    for(i=1;i<=len;i++)
    {
        Node* curr=temp->next;
        if(val==curr->data)
        {
            temp->next=curr->next;
            curr->next->prev=temp;
            curr->next=NULL;
            curr->prev=NULL;
            delete curr;
            return;
        }
        temp=temp->next;
        if(i==len-1)
        {
            cout<<"This value is note present in the linked list"<<endl;
            return;

        }

    }
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
    deleteByValue(First,tail,10);
    print(First);
    cout<<endl<<"First node is: "<<First->data<<endl;
    cout<<"Last node is: "<<tail->data<<endl;
    return 0;
}
