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
        while(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
    }
};
int FindLength(Node* &head)//remember here it returns integer so we have to give integer as a data type
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
Node* MergeTwoShortedLinkedList(Node* &head1,Node* &head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    Node* newNode=new Node(-1);
    Node* newTail=newNode;
    Node* temp1=head1;
    Node* temp2=head2;
    while(head1!=NULL&&head2!=NULL)
    {
        if(temp1->data<temp2->data)
        {
            head1=head1->next;
            temp1->next=NULL;
            newTail->next=temp1;
            newTail=temp1;
            temp1=head1;
        }
        else
        {
            head2=head2->next;
            temp2->next=NULL;
            newTail->next=temp2;
            newTail=temp2;
            temp2=head2;
        }
    }
    if(head1!=NULL)
    {
        newTail->next=head1;
    }
    else
        newTail->next=head1;
    Node* temp=newNode;
    newNode=newNode->next;
    temp->next=NULL;
    delete temp;
    return newNode;
}
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
void print(Node* &head)
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
    Node* First=new Node(1);
    Node* tail1=First;
    Node* Second=new Node(2);
    Node* tail2=Second;
    InsertAtTail(First,tail1,3);
    InsertAtTail(First,tail1,5);
    InsertAtTail(First,tail1,7);
    InsertAtTail(First,tail1,9);
    InsertAtTail(First,tail1,11);
    InsertAtTail(First,tail1,13);
    InsertAtTail(First,tail1,15);
    InsertAtTail(First,tail1,16);
    InsertAtTail(Second,tail2,4);
    InsertAtTail(Second,tail2,6);
    InsertAtTail(Second,tail2,8);
    InsertAtTail(Second,tail2,10);
    InsertAtTail(Second,tail2,12);
    InsertAtTail(Second,tail2,14);
    Node* shortedlist=MergeTwoShortedLinkedList(First,Second);
    print(shortedlist);
}
