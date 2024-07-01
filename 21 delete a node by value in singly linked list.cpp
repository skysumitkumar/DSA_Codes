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
int FindLength(Node* head)
{
    Node* temp=head;
    int len=1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        len++;
    }
    return len;
}
void DeleteByValue(Node* &head,Node* &tail,int val)
{
    int i;
    int len=FindLength(head);
    if(head==NULL)
    {
        cout<<"No value exist in node to delete"<<endl;
        return;
    }
    else if(val==head->data)
    {
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    else if(val==tail->data)
    {
        Node* temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
        return;
    }
    Node* temp=head;
    for(i=1;i<=len;i++)
    {
        Node* curr=temp->next;
        if(val==curr->data)
        {
            temp->next=curr->next;
            curr->next=NULL;
            delete curr;
            return;
        }
        temp=temp->next;
        if(i==len-1)
        {
            cout<<"This value doesn't exist in linked list"<<endl;
            return;
        }

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
    Node* Second=new Node(20);
    Node* Third=new Node(30);
    Node* Forth=new Node(40);
    Node* Fifth=new Node(50);
    First->next=Second;
    Second->next=Third;
    Third->next=Forth;
    Forth->next=Fifth;
    Node* tail=Fifth;
    DeleteByValue(First,tail,60);
    print(First);
    cout<<endl<<"First node is: "<<First->data<<endl;
    cout<<"Last node is: "<<tail->data;
    return 0;
}
