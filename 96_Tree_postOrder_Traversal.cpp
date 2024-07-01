#include<iostream>
using namespace std;
#include<queue>
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
void postorderTraversal(Node* root)
{
    //when we found the NULL we return our previous node
    if(root==NULL)
    {
        return ;
    }
    //use here LRN
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data;
}
int main()
{
    Node* root=makeTree();
    cout<<"The inorder traversal of tree is ";
    postorderTraversal(root);
}