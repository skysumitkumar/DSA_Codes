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
void RemoveDuplicate(Node* &head)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty";
        return;
    }
    Node* temp=head;
    while(temp!=NULL)
    {
        if((temp->next!=NULL)&&(temp->data==temp->next->data))// this is most important step in this questiion
        {
            Node* temp1=temp->next;
            temp->next=temp1->next;
            temp1->next=NULL;
            delete temp1;
        }
        else
        temp=temp->next;
    }
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
    Node* tail=First;
    InsertAtTail(First,tail,10);
    InsertAtTail(First,tail,50);
    //InsertAtTail(First,tail,30);
    //InsertAtTail(First,tail,20);
    //InsertAtTail(First,tail,10);
    RemoveDuplicate(First);
    cout<<endl;
    print(First);
    return 0;
}
