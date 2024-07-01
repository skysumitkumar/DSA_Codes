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
Node* FindMiddleNode(Node* &head)
{
    Node* slow=head;
    Node* fast=slow->next;
    while(fast->next!=NULL)
    {
        fast=fast->next;
        if(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}
Node* ShortTwoLL(Node* &head1,Node* &head2)
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
Node* ShortUsingMerge(Node* &head)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty";
        return head;
    }
    if(head->next==NULL)
        return head;
    Node* Middle=FindMiddleNode(head);
    Node* head1=head;
    Node* head2=Middle->next;
    Middle->next=NULL;
    head1=ShortUsingMerge(head1);
    head2=ShortUsingMerge(head2);
    Node* mergeLL=ShortTwoLL(head1,head2);
    return mergeLL;
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
    Node* tail=First;
    InsertAtTail(First,tail,2);
    InsertAtTail(First,tail,3);
    InsertAtTail(First,tail,4);
    InsertAtTail(First,tail,5);
    InsertAtTail(First,tail,6);
    InsertAtTail(First,tail,7);
    InsertAtTail(First,tail,8);
    InsertAtTail(First,tail,9);
    Node* Merge=ShortUsingMerge(First);
    print(Merge);
}
