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
};
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
    newNode->prev=tail;
    newNode->next=head;
    head->prev=newNode;
    tail=newNode;
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
    First->next=Second;
    Second->prev=First;
    Second->next=First;
    First->prev=Second;
    Node* tail=Second;
    InsertAtTail(First,tail,30);
    InsertAtTail(First,tail,40);
    InsertAtTail(First,tail,50);
    print(First);
    cout<<endl<<"First node is: "<<First->data<<endl;
    cout<<"Last node is: "<<tail->data;
    return 0;

}
