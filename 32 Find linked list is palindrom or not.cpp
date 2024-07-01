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
Node* Reversell(Node* &prev,Node* &curr)
{
    if(curr==NULL)
    {
        return prev;
    }
    Node* Forward=curr->next;
    curr->next=prev;
    return Reversell(curr,Forward);

}
void CheckPalindrome(Node* &head)
{
    if(head==NULL)
    {
        cout<<"ll is empty";
        return;
    }
    if(head->next==NULL)
    {
        cout<<"It is a palindrome";
        return;
    }
    Node* Fast=head->next;
    Node* slow=head;
    while(Fast!=NULL)
    {
        Fast=Fast->next;
        if(Fast!=NULL)
        {
            Fast=Fast->next;
            slow=slow->next;
        }
    }
    Node* temp=slow->next;
    Node* prev=NULL;
    Node* Middle=Reversell(prev,temp);
    slow->next=Middle;
    temp=head;
    while(Middle!=NULL)
    {
        if(temp->data!=Middle->data)
        {
            cout<<"It is not a palindrome";
            return;
        }
        temp=temp->next;
        Middle=Middle->next;
    }
    cout<<"It is a palindrome";
    return;
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
    InsertAtTail(First,tail,20);
    InsertAtTail(First,tail,10);
    //InsertAtTail(First,tail,30);
    //InsertAtTail(First,tail,20);
    //InsertAtTail(First,tail,10);
    Node* prev=NULL;
    //Node* head=Reversell(prev,First);
    CheckPalindrome(First);
    return 0;
}
