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
        this->next=NULL;
        this->prev=NULL;
    }
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
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
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
    return len;
}
void deleteByValue(Node* &head,Node* &tail,int val)
{
    int i,len=FindLength(head);
    cout<<len<<endl;
    if(head==NULL)
    {
        cout<<"No node is present so we cant delete any node";
        return;
    }
    if(val==head->data)
    {
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        temp->prev=NULL;
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
        temp->next=NULL;
        tail->prev=NULL;
        delete tail;
        tail=temp;
        return;
    }
    Node* temp=head;
    for(i=1;i<=len;i++)
    {
        Node* curr=temp->next;
        if(curr->data==val)
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
            cout<<"This value is not present in the list"<<endl;
            return;
        }
    }
}
void print(Node* head)
{
    Node* temp=head;
    cout<<temp->data<<" ";
    temp=temp->next;
    while(temp!=NULL)
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
    Node* tail=Fifth;
    deleteByValue(First,tail,60);
    print(First);
    cout<<endl<<"First node is: "<<First->data;
    cout<<endl<<"Last node is: "<<tail->data;
    return 0;
}
