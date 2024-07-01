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
/*
Approach - 1

void sortLinkedList(Node *&head)
{
    // Step 1 -> Count
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else
        {
            twoCount++;
        }
        temp = temp->next;
    }
    // Step 2 -> Fill 0s 1s and 2s
    temp = head;
    // Fill zeroes
    while (zeroCount--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    // Fill ones
    while (oneCount--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    // Fill two
    while (twoCount--)
    {
        temp->data = 2;
        temp = temp->next;
    }
}
*/

// Approach 2 (Dummy node)
/*Node* ShortZeroOneTwo(Node* &head)
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
    Node* ZeroHead=new Node(-1);
    Node* ZeroTail=ZeroHead;
    Node* OneHead=new Node(-1);
    Node* OneTail=OneHead;
    Node* TwoHead=new Node(-1);
    Node* TwoTail=TwoHead;
    Node* temp=head;
    while(head!=NULL)
    {
        if(head->data==0)
        {
            temp=head;
            head=head->next;
            temp->next=NULL;
            ZeroTail->next=temp;
            ZeroTail=temp;
        }
        if(head->data==1)
        {
            temp=head;
            head=head->next;
            temp->next=NULL;
            OneTail->next=temp;
            OneTail=temp;
        }
        if(head->data==2)
        {
            temp=head;
            head=head->next;
            temp->next=NULL;
            TwoTail->next=temp;
            TwoTail=temp;
        }
    }
    if(ZeroHead->next!=NULL)
    {
        if(OneHead->next!=NULL)
        {
            temp=OneHead;
            OneHead=OneHead->next;
            temp->next=NULL;
            delete temp;
            ZeroTail->next=OneHead;
            if(TwoHead->next!=NULL)
            {
                temp=TwoHead;
                TwoHead=TwoHead->next;
                temp->next=NULL;
                delete temp;
                OneTail->next=TwoHead;
                temp=ZeroHead;
                ZeroHead=ZeroHead->next;
                temp->next=NULL;
                delete temp;
                return ZeroHead;
            }
            else
            {
                delete TwoHead;
                temp=ZeroHead;
                ZeroHead=ZeroHead->next;
                temp=temp->next;
                delete temp;
                return ZeroHead;
            }
        }
        else
        {
            delete OneHead;
            if(TwoHead->next!=NULL)
            {
                temp=TwoHead;
                TwoHead=TwoHead->next;
                temp->next=NULL;
                delete temp;
                ZeroTail->next=TwoHead;
                temp=ZeroHead;
                ZeroHead=ZeroHead->next;
                temp->next=NULL;
                delete temp;
                return ZeroHead;
            }
            else
            {
                delete TwoHead;
                temp=ZeroHead;
                ZeroHead=ZeroHead->next;
                temp->next=NULL;
                delete temp;
                return ZeroHead;
            }
        }
    }
    else
    {
        delete ZeroHead;
       if(OneHead->next!=NULL)
        {
            temp=OneHead;
            OneHead=OneHead->next;
            temp->next=NULL;
            delete temp;
            if(TwoHead->next!=NULL)
            {
                temp=TwoHead;
                TwoHead=TwoHead->next;
                temp->next=NULL;
                delete temp;
                OneTail->next=TwoHead;
                return OneHead;
            }
            else
            {
                delete TwoHead;
                return OneHead;
            }
        }
        else
        {
            delete OneHead;
            if(TwoHead->next!=NULL)
            {
                temp=TwoHead;
                TwoHead=TwoHead->next;
                temp->next=NULL;
                delete temp;
                return TwoHead;
            }
            else
            {
                delete TwoHead;
                cout<<"Linked list is empty";
            }
        }
    }
}*/
Node* ShortZeroOneTwo(Node* &head)
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
    Node* ZeroHead=new Node(-1);
    Node* ZeroTail=ZeroHead;
    Node* OneHead=new Node(-1);
    Node* OneTail=OneHead;
    Node* TwoHead=new Node(-1);
    Node* TwoTail=TwoHead;
    Node* temp=head;
    while(head!=NULL)
    {
        if(head->data==0)
        {
            temp=head;
            head=head->next;
            temp->next=NULL;
            ZeroTail->next=temp;
            ZeroTail=temp;
        }
        if(head->data==1)
        {
            temp=head;
            head=head->next;
            temp->next=NULL;
            OneTail->next=temp;
            OneTail=temp;
        }
        if(head->data==2)
        {
            temp=head;
            head=head->next;
            temp->next=NULL;
            TwoTail->next=temp;
            TwoTail=temp;
        }
    }
    temp=OneHead;
    OneHead=OneHead->next;
    temp->next=NULL;
    delete temp;
    temp=TwoHead;
    TwoHead=TwoHead->next;
    temp->next=NULL;
    delete temp;
    if(ZeroHead->next!=NULL)
    {
        if(OneHead!=NULL)
        {
            ZeroTail->next=OneHead;
            if(TwoHead->next!=NULL)
            {
                OneTail->next=TwoHead;
                temp=ZeroHead;
                ZeroHead=ZeroHead->next;
                temp->next=NULL;
                delete temp;
                return ZeroHead;
            }
            else
            {
                temp=ZeroHead;
                ZeroHead=ZeroHead->next;
                temp=temp->next;
                delete temp;
                return ZeroHead;
            }
        }
        else
        {
            if(TwoHead!=NULL)
            {
                ZeroTail->next=TwoHead;
                temp=ZeroHead;
                ZeroHead=ZeroHead->next;
                temp->next=NULL;
                delete temp;
                return ZeroHead;
            }
            else
            {
                temp=ZeroHead;
                ZeroHead=ZeroHead->next;
                temp->next=NULL;
                delete temp;
                return ZeroHead;
            }
        }
    }
    else
    {
        delete ZeroHead;
       if(OneHead!=NULL)
        {
            if(TwoHead!=NULL)
            {
                OneTail->next=TwoHead;
                return OneHead;
            }
            else
            {
                return OneHead;
            }
        }
        else
        {
            if(TwoHead!=NULL)
            {
                return TwoHead;
            }
            else
            {
                delete TwoHead;
                cout<<"Linked list is empty";
            }
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
    Node* First=new Node(0);
    Node* tail=First;
    InsertAtTail(First,tail,2);
    InsertAtTail(First,tail,2);
    InsertAtTail(First,tail,1);
    InsertAtTail(First,tail,0);
    InsertAtTail(First,tail,2);
    Node* Short=ShortZeroOneTwo(First);
    cout<<endl;
    print(Short);
    return 0;
}

