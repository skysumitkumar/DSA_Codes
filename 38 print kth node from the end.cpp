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
/*Node* KthNodeFromEnd(Node* &head,int position)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty";
        return head;
    }
    int len=FindLength(head);
    if(position>=len)
    {
        cout<<"No node is present in this position";
        return NULL;
    }
    int p=len-position-1;
    Node* temp=head;
    for(int i=0;i<p;i++)
    {
        temp=temp->next;
    }
    return temp;

}*/
void KthNodeFromEnd(Node* &head,Node* &tail,int &position)//here we have to make sure ki position ko bhi by reference lena h
{
    if(head==NULL)
    {
        return;
    }
    KthNodeFromEnd(head->next,tail,position);
    if(position==0)
    {
        cout<<head->data<<endl;
        return;
    }
    position--;
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
    int n=5;
    KthNodeFromEnd(First,tail,n);
    //Node* no=KthNodeFromEnd(First,5);
    //cout<<no->data;
}
