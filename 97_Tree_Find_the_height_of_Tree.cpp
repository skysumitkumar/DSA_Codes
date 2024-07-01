#include<iostream>
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
int Height(Node* root)
{
    //here our base condition is the when we found null we return 0 as count
    if(root==NULL)
    {
        return 0;
    }
    //firstly we travers to left
    int temp=Height(root->left);
    //when we left is traversed and we found null then we go to its right
    int temp1=Height(root->right);
    //when right and left of one node and it dont have null then we check the max length of left side traverse and right side trverse and add 1 to it to count that node also
    //yha ham length find kar rahe h jo int temp,int temp 1 me jaaegi jab null aa jyega to ye 0 return karvaega or max find karne par 1 jodkar length 1 de dega 
    //phir aage aase hi chlta rahega
    int ans=max(temp,temp1)+1;
    //return our length
    return ans;
}
int main()
{
    Node* root=makeTree();
    cout<<"The height of the tree is ";
    int h=Height(root);
    cout<<h;
}
