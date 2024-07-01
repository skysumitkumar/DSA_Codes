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
Node* ReverseInKGroup(Node* &head,int k)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty";
        return head;
    }
    int len=FindLength(head);
    cout<<len<<endl;
    if(k>len)//here we check if k value is greater than length of linked list than we return our head and stop reverse
    {
        return head;
    }
    if(head->next==NULL)
    {
        return head;
    }
    int i=k;
        Node* prev=NULL;
        Node* curr=head;
        Node* Forward=curr->next;//jo pointers bane vo loop se bhar banane h hamesha
    while(i>0)
    {
        Forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Forward;
        i--;
    }
    if(Forward!=NULL)
    {
       head->next=ReverseInKGroup(Forward,k);//k nodes ko next k nodes se jodne k lyea
    }
//return head
    return prev;

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
    Node* sixth=new Node(60);
    First->next=Second;
    Second->next=Third;
    Third->next=Forth;
    Forth->next=Fifth;
    Fifth->next=sixth;
    Node* tail=Fifth;
    int k;
    print(First);
    cout<<endl;
    cout<<"The value of k group to reverse is ";
    cin>>k;
    cout<<endl;
    Node* reverseK=ReverseInKGroup(First,k);
    print(reverseK);
}
