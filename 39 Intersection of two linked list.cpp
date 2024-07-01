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
Node* FindIntersectionPoint(Node* &head1,Node* &head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    Node* temp1=head1;
    Node* temp2=head2;
    int d1=0;
    int d2=0;
    while(temp1->next!=NULL&&temp2->next!=NULL)
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp1->next!=NULL)
        {
            while(temp1->next!=NULL)
            {
                temp1=temp1->next;
                d1=d1+1;
            }
        }
        if(temp2->next!=NULL)
            {
                while(temp2->next!=NULL)
                {
                    temp2=temp2->next;
                    d2=d2+1;
                }
            }
            if(temp1->data!=temp2->data)
            {
                cout<<"There is no intersection point between these linked list";
                return NULL;
            }
            if(d1>0)
            {
                temp1=head1;
                while(d1!=0)
                {
                    temp1=temp1->next;
                    d1=d1-1;
                }
                temp2=head2;
            }
            if(d2>0)
            {
                temp2=head2;
                while(d2!=0)
                {
                    temp2=temp2->next;
                    d2=d2-1;
                }
                temp1=head1;
            }
            while(temp1->data!=temp2->data)
            {
                temp1=temp1->next;
                temp2=temp2->next;
            }
            return temp1;
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
    Node* Second=new Node(10);
    Node* tail2=Second;
    InsertAtTail(First,tail1,2);
    InsertAtTail(First,tail1,3);
    InsertAtTail(First,tail1,4);
    InsertAtTail(First,tail1,5);
    InsertAtTail(First,tail1,6);
    InsertAtTail(First,tail1,7);
    InsertAtTail(First,tail1,8);
    InsertAtTail(First,tail1,9);
    InsertAtTail(Second,tail2,12);
    InsertAtTail(Second,tail2,5);
    InsertAtTail(Second,tail2,6);
    InsertAtTail(Second,tail2,7);
    InsertAtTail(Second,tail2,8);
    InsertAtTail(Second,tail2,9);
    /*InsertAtTail(Second,tail2,13);
    InsertAtTail(Second,tail2,14);
    InsertAtTail(Second,tail2,15);
    InsertAtTail(Second,tail2,16);
    InsertAtTail(Second,tail2,17);*/
    Node* Intersect=FindIntersectionPoint(First,Second);
    cout<<Intersect->data;
}
