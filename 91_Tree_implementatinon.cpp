#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
//make a node pointer function to return the root node
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
int main()
{
    makeTree();
}