//recheck the code of sum of left and right sum only
#include<iostream>
using namespace std;
#include<queue>
class tree
{
    public:
    int data;
    tree* left;
    tree* right;
    tree(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
tree* makeTree()
{
    //make varible to store the data of the trees
    int data;
    cout<<"Enter the data for the tree "<<endl;
    cin>>data;
    //if we give input -1 than NULL is after the left or the right of the tree
    if(data==-1)
    {
        return NULL;
    }
    //make the tree and stor the data 
    tree* root =new tree(data);
    cout<<"Enter the data to create tree at left of the "<<data<<endl;
    //here we connect the left pointer to the tree 
    root->left=makeTree();
    cout<<"Enter the data to create tree at right of the "<<data<<endl;
    //here we connect the right pointer to the tree
    root->right=makeTree();
    //after all return in recursion we return our root tree to the user to perform function on the tree
    return root;
}
// tree* ConvertToSum(tree* &root)
// {
//     if(root->left==NULL&&root->right==NULL)
//     {
//         return root;
//     }
//     else if(root->left==NULL)
//     {
//         return root->right;
//     }
//     else
//     {
//         return root->left;
//     }
//     tree* leftside=ConvertToSum(root->left);
//     tree* rightside=ConvertToSum(root->right);
//     root->data=leftside->data+rightside->data;
//     //root->data=sum;
//     return root;
// }
int ConvertToSum(tree* &root){
    // if we found the null in the root then we return 0 that time
    if(root == NULL){
        return 0;
    }
    //firstly we check the left side
    int leftAns = ConvertToSum(root->left);
    //then we check the right side
    int rightAns = ConvertToSum(root->right);
    //here we change the value of node by sum of left and right and its val
    root->data = root->data + leftAns + rightAns;
    return root->data;
}
void levelOrderTraversal(tree* root)
{
    //Here we make the queue that store the trees
    queue<tree* >q;
    //firstly we push the root tree
    q.push(root);
    //Then we push NULL because we have go to next level
    q.push(NULL);
    while(!q.empty())
    {
        //This loop is going while q is not empty
        tree* temp=q.front();
        //then pop tree from the queue 
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
            cout<<temp->data<<" ";
        //here we check that tree have tree in the left side
        if(temp->left)
        {
            //push that tree in the queue 
            q.push(temp->left);
        }
        //here we check that tree have tree in the right side
        if(temp->right)
        {
            //push that tree in the queue 

            q.push(temp->right);
        }
        }  
    }
}
int main()
{
    tree* root=makeTree();
    //levelOrderTraversal(root);
    // tree* newroot=ConvertToSum(root);
    // levelOrderTraversal(root);
    ConvertToSum(root);
    levelOrderTraversal(root);
}