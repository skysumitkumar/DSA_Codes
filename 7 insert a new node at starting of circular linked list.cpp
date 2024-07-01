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
        this->next=NULL;
    }
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void InsertAtHead(Node* &head,Node* &tail,int data)
{
    if(head==NULL)
    {
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node* newNode=new Node(data);
    newNode->next=head;
    tail->next=newNode;
    head=newNode;
}
void print(Node* &head)
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
    Node* First=new Node(20);
    Node* Second=new Node(30);
    Node* Third=new Node(40);
    First->next=Second;
    Second->next=Third;
    Node* tail=Third;
    //InsertAtHead(First,tail,10);
    print(First);
    cout<<endl;
    cout<<"The next node of tail is: "<<tail->next->data;
    return 0;
}
