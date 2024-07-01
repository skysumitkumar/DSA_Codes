#include<iostream>
using namespace std;
class tree
{
    public:
    int data;
    tree* left;
    tree* right;
    tree(int val)
    {
        this->data=val;
        left=NULL;
        right=NULL;
    }
};
tree* makeTree()
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
    tree* root =new tree(data);
    cout<<"Enter the data to create node at left of the "<<data<<endl;
    //here we connect the left pointer to the node 
    root->left=makeTree();
    cout<<"Enter the data to create node at right of the "<<data<<endl;
    //here we connect the right pointer to the node
    root->right=makeTree();
    //after all return in recursion we return our root node to the user to perform function on the tree
    return root;
}
int Height(tree* root)
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
    //when right and left of one node and it dont have null then we check the max length of left side traverse and right side trverse and 1 to it to count that node also
    int ans=max(temp,temp1)+1;
    //return our length
    return ans;
}
bool BalancedBinaryTree(tree* root)
{
    //here firstly we check our root node is null or not if it is null we return 1 for length is 1
    if(root==NULL)
    {
        return 1;
    }
    //here we check the height of the left subtree
        //yha hame height vaale function se null aane par max count karne par firstly one and phir vo uper uper count karke hame btta dega
        int checkleft=Height(root->left);
        //here we check the height of the right subtree
        int checkright=Height(root->right);
        //here we check the abslute diff of the left sub tree and right subtree if it is atmost 1 then our tree is balanced
        int diff=abs(checkleft-checkright);
        bool ans=diff<=1;
        //then we go to the left node of the root node to check its subtree height
        bool temp1=BalancedBinaryTree(root->left);
        //then we go to the right node of the root node to check its subtree height
        bool temp2=BalancedBinaryTree(root->right);
        //here we check out abs diff is atmost 1 or not and right side lenght is true or not and left side length is true or not
        if(ans&&temp1&&temp2)
        {
            return true;
        }
        else
        return false;
    
}
int main()
{
    tree* root=makeTree();
    bool ans=BalancedBinaryTree(root);
    cout<<endl<<ans;
}