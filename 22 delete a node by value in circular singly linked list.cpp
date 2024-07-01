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
        while(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
    }
};
int FindLength(Node* head)
{
    Node* temp=head;
    int len=0;
    temp=temp->next;
    len++;
    while(temp!=head)
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
        cout<<"all nodes are empty so we cant delete any node";
        return;
    }
    if(val==head->data)
    {
        Node* temp=head;
        head=head->next;
        tail->next=head;
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
        tail->next=NULL;
        delete tail;
        tail=temp;
        return;
    }
    Node* temp=head;
    for(i=0;i<=len;i++)
    {
        Node* curr=temp->next;
        if(val==curr->data)
        {
            temp->next=curr->next;
            curr->next=NULL;
            delete curr;
            return;
        }
        temp=temp->next;
        if(i==len)
            cout<<"This value doesn't exist in this list"<<endl;
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
    Second->next=Third;
    Third->next=Forth;
    Forth->next=Fifth;
    Fifth->next=First;
    Node* tail=Fifth;
    deleteByValue(First,tail,60);
    print(First);
    cout<<endl<<"First node is: "<<First->data;
    cout<<endl<<"Last node is: "<<tail->data;
    return 0;
}
