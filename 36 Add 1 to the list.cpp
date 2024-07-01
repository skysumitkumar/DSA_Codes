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
        this->next=NULL
    }
};
void InsertAtTail(Node* &head,Node* &tail,int data)
{
    Node* newNode=new Node(data);
    tail->next=newNode;

}
