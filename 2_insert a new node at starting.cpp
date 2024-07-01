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
void InsertAtHead(Node* &head,Node* &tail,int data)
{
    if(head==NULL)
    {
        Node* FirstNode=new Node(data);
        head=FirstNode;
        tail=FirstNode;
        return;
    }
    Node* FirstNode=new Node(data);
    FirstNode->next=head;
    head=FirstNode;

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
    Node* tail=FirstNode;//taking tail at staring node
    InsertAtHead(FirstNode,tail,20);//remember here when making a node at starting without inserting name of that node assuming as head and give it to new insertion node
    print(FirstNode);
    return 0;
}
