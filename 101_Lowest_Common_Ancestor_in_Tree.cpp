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
int LowestCommonAncestor(tree* root,int p,int q)
{
    //if we found the null in any side so we return 0 because in this side there is no p and q
    if(root==NULL)
    {
        return 0;
    }
    //if we found the p in any side so we return p
    if(root->data==p)
    {
        return p;
    }
    //if we found the q in any side so we return q
    if(root->data==q)
    {
        return q;
    }
    //here we firstly check the left side of the tree 
    int leftside=LowestCommonAncestor(root->left,p,q);
    //then we check the right side of the tree
    int rightside=LowestCommonAncestor(root->right,p,q);
    //if we found our p and q in left and right or right and left side so we return common node val
    if (leftside != 0 && rightside != 0) {
        return root->data;
    } 
    //if we found the p or q in the left side and in right side we there is no p or q so we return our leftside value
    else if (leftside != 0) {
        return leftside;
    }
    //if we found the p or q in the right side and in left side we have no p or q so we retun 0 then so here we return right side value
    else {
        return rightside;
    }

}
int main()
{
    int p,q;
    tree* root=makeTree();
    cout<<endl<<"Enter the value of p ";
    cin>>p;
    cout<<"Enter the value of q ";
    cin>>q;
    int CommonAncestor=LowestCommonAncestor(root,p,q);
    cout<<CommonAncestor;
    //levelOrderTraversal(root);
}