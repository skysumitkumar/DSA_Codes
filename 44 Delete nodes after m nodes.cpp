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
        while(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
    }
};
int FindLength(Node* &head)
{
    Node* temp=head;
    int i=1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        i++;
    }
    return i;
}
void DeleteMNodesAfterNNodes(Node* &head,int m,int n)
{
    if(head==NULL)
        return;
        Node* temp=head;
        for(int i=0;i<n-1;i++)
        {
            if(temp==NULL)
                return;
            temp=temp->next;
        }
        if(temp==NULL)
            return;
        Node* DeleteHead=temp;
        DeleteHead=temp->next;
        for(int i=0;i<m;i++)
        {
            if(DeleteHead==NULL)
                return;
            Node* del=DeleteHead->next;
            DeleteHead->next=NULL;
            delete DeleteHead;
            DeleteHead=del;
        }
        temp->next=DeleteHead;
        temp=temp->next;
        return DeleteMNodesAfterNNodes(temp,m,n);

}
void InsertAtTail(Node* &head,Node* &tail,int data)
{
    if(head==NULL)
    {
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node* newNode=new Node(data);
    tail->next=newNode;
    tail=newNode;
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
    Node* FirstNode=new Node(10);
    Node* tail=FirstNode;
    InsertAtTail(FirstNode,tail,20);
    InsertAtTail(FirstNode,tail,30);
    InsertAtTail(FirstNode,tail,40);
    InsertAtTail(FirstNode,tail,50);
    InsertAtTail(FirstNode,tail,60);
    int len=FindLength(FirstNode);
    cout<<len<<endl;
    DeleteMNodesAfterNNodes(FirstNode,3,2);
    print(FirstNode);
    return 0;
}
