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
};
void InsertAtTail(Node* &head,Node* &tail,int data)
{
    if(head==NULL)
    {
        Node* newNode= new Node(data);
        head=newNode;
        tail=newNode;
    }
    Node* newNode=new Node(data);
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
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
    First->next=Second;
    Second->prev=First;
    Node* tail=Second;
    InsertAtTail(First,tail,30);
    InsertAtTail(First,tail,40);
    print(First);
    cout<<endl;
    cout<<"Head is : "<<First->data;
    cout<<endl;
    cout<<"Tail is : "<<tail->data;
    return 0;
}
