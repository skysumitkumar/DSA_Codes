#include<iostream>
#include<queue>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node( int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
Node* makeTree()
{
    //make varible to store the data of the nodes
    int data;
    cout<<"Enter the data for the node "<<endl;
    cin>>data;
    //if we give input -1 than NULL is after the left or the right of the node
    if(data==-1)
    {
        return NULL;
    }
    //make the node and stor the data 
    Node* root =new Node(data);
    cout<<"Enter the data to create node at left of the "<<data<<endl;
    //here we connect the left pointer to the node 
    root->left=makeTree();
    cout<<"Enter the data to create node at right of the "<<data<<endl;
    //here we connect the right pointer to the node
    root->right=makeTree();
    //after all return in recursion we return our root node to the user to perform function on the tree
    return root;
}
void levelOrderTraversal(Node* root)
{
    //Here we make the queue that store the nodes
    queue<Node* >q;
    //firstly we push the root node
    q.push(root);
    //Then we push NULL because we have go to next level
    q.push(NULL);
    while(!q.empty())
    {
        //This loop is going while q is not empty
        Node* temp=q.front();
        //then pop node from the queue 
        q.pop();
        if(!q.empty()&&temp==NULL)
        {
            //for print next level in the next line
            cout<<endl;
            //when we fount NULL then we also push NULL to track level
            q.push(NULL);
        }
        else
        {
            cout<<temp->data;
        //here we check that node have node in the left side
        if(temp->left)
        {
            //push that node in the queue 
            q.push(temp->left);
        }
        //here we check that node have node in the right side
        if(temp->right)
        {
            //push that node in the queue 

            q.push(temp->right);
        }
        }  
    }
}
int main()
{
    Node* root=makeTree();
    cout<<"The level order traversal is "<<endl;
    levelOrderTraversal(root);
}