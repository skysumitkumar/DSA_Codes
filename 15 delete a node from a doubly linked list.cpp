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
    while(temp->next!=NULL)
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
        cout<<"we cant delete any this here no node is present";
        return;
    }
    Node* temp=head;
    head=head->next;
    temp->next =NULL;
    head->prev=NULL;
    delete temp;
}
void deleteAtTail(Node* &head,Node* &tail)
{
    if(head==NULL)
    {
        cout<<"we cant delete any this here no node is present";
        return;
    }
    Node* temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    temp->prev=NULL;
    delete temp;
}
void deleteAtPosition(Node* &head,Node* &tail,int position)
{
    if(head==NULL)
    {
        cout<<"we cant delete any this here no node is present";
        return;
    }
    int len=FindLength(head);
    if(position<1||position>len)
    {
        cout<<"In this position no node is present"<<endl;
        return;
    }

    if(position==1)
    {
        deleteAtHead(head,tail);
        return;
    }
    if(position==len)
    {
        deleteAtTail(head,tail);
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
    deleteAtPosition(First,tail,2);
    //int len=FindLength(First);
    print(First);
    cout<<endl;
    cout<<"First node is: "<<First->data;
    cout<<endl;
    cout<<"Last node is: "<<tail->data;
    return 0;
}
