#include<iostream>
#include <bits/stdc++.h>
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
bool kthAncestor(tree* root,int& k,int p)
{
    //if root is null then we return false here we not found our p value
    if(root == NULL){
        return false;
    }
    //if we found p in any side then we return we found it true or 1
    if(root -> data == p){
        return true;
    }
    
    //then we search it in left subtree
    bool leftAns = kthAncestor(root->left,k,p);
    //then we search it in right subtree
    bool rightAns = kthAncestor(root->right,k,p);
    // here we decrease our value of k when going upside
    if(leftAns || rightAns){
        k--;
    }
    //when we found k=0 then we return value of node where we fond k==0
    if(k == 0){
        cout<<"Ans = "<<root->data<<" ";
        //this is important to change k to -1 because when we return in recursion it print another values where k=0
        k = -1;
    }
    return leftAns || rightAns;

}
int main()
{
    tree* root=makeTree();
    int k = 1;
    int p = 5;
    bool found = kthAncestor(root,k,p);
    return 0;
}
    