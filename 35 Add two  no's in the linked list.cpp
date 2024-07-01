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
Node* Reverse(Node* prev,Node* &curr)
{
    if(curr==NULL)
    {
        return prev;
    }
    Node* Forward=curr->next;
    curr->next=prev;
    return Reverse(curr,Forward);

}
Node* AddSum(Node* &head1,Node* &head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    Node* prev=NULL;
    Node* Rhead1=Reverse(prev,head1);
    Node* Rhead2=Reverse(prev,head2);
    Node* newNode=new Node(NULL);
    Node* tail=newNode;
    int sum;
    int carry=0;
    int digit;
    while(Rhead1!=NULL&&Rhead2!=NULL)//yha and aaega na ki or remember it
    {
        digit=Rhead1->data+Rhead2->data;
        digit=digit+carry;
        sum=digit%10;
        carry=digit/10;
        InsertAtTail(newNode,tail,sum);
        Rhead1=Rhead1->next;
        Rhead2=Rhead2->next;
    }
    while(Rhead1!=NULL)
    {
        digit=Rhead1->data+carry;
        sum=digit%10;
        carry=digit/10;
        InsertAtTail(newNode,tail,sum);
        Rhead1=Rhead1->next;
    }
    while(Rhead2!=NULL)
    {
        digit=Rhead2->data+carry;
        sum=digit%10;
        carry=digit/10;
        InsertAtTail(newNode,tail,sum);
        Rhead2=Rhead2->next;
    }
    while(carry!=0)
    {
        digit=carry;
        sum=digit%10;
        carry=digit/10;
        InsertAtTail(newNode,tail,sum);
    }
    Node* temp=newNode;
    newNode=newNode->next;
    temp->next=NULL;
    delete temp;
    Node* RSum=Reverse(prev,newNode);
    return RSum;
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
    Node* First=new Node(NULL);
    Node* tail1=First;
    InsertAtTail(First,tail1,2);
    InsertAtTail(First,tail1,5);
    InsertAtTail(First,tail1,5);
    Node* Second=new Node(NULL);
    Node* tail2=Second;
    //InsertAtTail(Second,tail2,5);
    InsertAtTail(Second,tail2,5);
    InsertAtTail(Second,tail2,5);
    if(First->data==0)
    {
        Node* temp=First;
        First=First->next;
        temp->next=NULL;
        delete temp;

    }
    if(Second->data==0)
    {
        Node* temp=Second;
        Second=Second->next;
        temp->next=NULL;
        delete temp;
    }
    Node* Sum=AddSum(First,Second);
    cout<<endl;
    print(Sum);
    return 0;
}

