//1.    find tail in reverse
//2.how to make always head as First
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
Node* ReverseUsingLoop(Node* &head)
{
    Node* prev=NULL;
    Node* curr=head;
    while(curr!=NULL)
    {
        Node* Forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Forward;
    }
    return prev;// here we return prev because we make prev position to head in main function
}
Node* ReverseUsingRecursion(Node* &prev,Node* &curr)
{
    if(curr==NULL)
    {
        return prev;
    }
    Node* Forward=curr->next;
    curr->next=prev;
    return ReverseUsingRecursion(curr,Forward);
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
    Second->next=Third;
    Third->next=Forth;
    Forth->next=Fifth;
    Node* tail=Fifth;
    print(First);
    cout<<endl;
    Node* head=ReverseUsingLoop(First);//yha hamne jo function me prev return keya h usko head assign kar deya h taaaki hum linkedlist ko dhun sake head se
    print(head);//print through new head
    cout<<endl;
    Node* prev=NULL;
    Node* curr=head;
    Node* newhead=ReverseUsingRecursion(prev,curr);
    print(newhead);
    cout<<endl<<"First node is: "<<newhead->data;//new head data
    cout<<endl<<"Last node is: "<<tail->data;//previious  tail data
}
