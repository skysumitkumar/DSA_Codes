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
/*Node* FindMiddleNode(Node* &head)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return head;
    }
    if(head->next==NULL)
    {
        return head;
    }
    Node* slow=head;
    Node* Fast=head;
    while(Fast!=NULL)
    {
        Fast=Fast->next;
        if(Fast!=NULL)  //remember this point if i write if(Fast->next!=NULL) when fast at null and i go to NUll next then it goes nowere positon then our code is break
        //if(Fast->next!=NULL) this is wrong
        {
            Fast=Fast->next;
            slow=slow->next;
        }
    }
    return slow;
}*/
//if in even node we want the 30 as our middle node then our code is below
Node* FindMiddleNode(Node* &head)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty";
        return head;
    }
    if(head->next==NULL)
    {
        return head;
    }
    Node* Fast=head;
    Node* slow =head;
    while(Fast->next!=NULL)//if we want 30 as middle node then we have to check Fast->next!=NULL in this step
    {
        Fast=Fast->next;
        if(Fast->next!=NULL)//if we want 30 as middle node then we have to check Fast->next!=NULL in this step
        {
            Fast=Fast->next;
            slow=slow->next;
        }
    }
    return slow;
}
void print(Node* head)
{
    Node* temp=head;
    cout<<temp->data<<" ";
        temp=temp->next;
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
    Node* tail=sixth;
    print(First);
    cout<<endl<<"The middle node is :";
    Node* middle=FindMiddleNode(First);
    cout<<middle->data;
}
