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
Node* FindStartingLoopNode(Node* &head)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return head;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
            if(slow==fast)
            {
               slow=head;
               break;

            }
        }

    }
    while(fast!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
        if(slow==fast)
            {
                return slow;
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
    Node* Sixth=new Node(60);
    Node* Seventh=new Node(70);
    Node* Eighth=new Node(80);
    Node* Nine=new Node(90);
    Node* Tenth=new Node(100);
    First->next=Second;
    Second->next=Third;
    Third->next=Forth;
    Forth->next=Fifth;
    Fifth->next=Sixth;
    Sixth->next=Seventh;
    Seventh->next=Eighth;
    Eighth->next=Nine;
    Nine->next=Tenth;
    Tenth->next=Sixth;
    //print(First);
    Node* slow=FindStartingLoopNode(First);
    cout<<slow->data;
    return 0;
}
