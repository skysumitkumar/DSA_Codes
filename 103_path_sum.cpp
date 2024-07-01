//incomplete program
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#include<vector>
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
void pathsum(tree* root,int Targetsum,vector<int>&v,vector<vector<int>> &ans,int sum)
{
    //here we check if we cant find the targetsum and we are on Null then return
    if(root==NULL)
    {
        return;
    }
    //here we check that we are on leaf node or not
    if(root->left==NULL&&root->right==NULL)
    {
        //then we push our leaf node on vector and add value of root node in sum
        v.push_back(root->data);
        sum+=root->data;
        //then we check our sum is equal to target sum or not if it is than we push it in another vector becaue when we come pack from recursion or vector is changed or sum is changed so here we have the path of sum so firsly store it in another place so it change when we are come back from recursion
        if(sum==Targetsum)
        {
            cout<<"we got our target sum"<<endl;
            ans.push_back(v);
        }
        //when our sum is not equal to the target sum then we pop leaf value from the vector and sum
        v.pop_back();
        sum-=root->data;
        return;
    }
    //here we push the value of nodes in the vector when we are searching the sum
    v.push_back(root->data);
    sum=sum+root->data;
    //firstly check on the left side
    pathsum(root->left,Targetsum,v,ans,sum);
    //then check on the right side
    pathsum(root->right,Targetsum,v,ans,sum);
    //when we are comming back from them node when we not found our sum then we remove that node from the queue and sum
    v.pop_back();
    sum=sum-root->data;
}
int main()
{
    int Targetsum;
    tree* root=makeTree();
    cout<<"Enter the value of Targetsum ";
    cin>>Targetsum;
    int sum=0;
    vector<int>v;
    vector<vector<int>> ans;
    pathsum(root,Targetsum,v,ans,sum);
    int size=ans.size();
    for (int i = 0; i < size; i++)  
    { 
        for (int j = 0; j < ans[i].size(); j++) 
        { 
            cout << ans[i][j] << " "; 
        }     
        cout << endl; 
    }
}

//this is completed
// #include<iostream>
// using namespace std;
// #include<vector>
// class tree
// {
//     public:
//     int data;
//     tree* left;
//     tree* right;
//     tree(int data)
//     {
//         this->data=data;
//         left=NULL;
//         right=NULL;
//     }
// };
// tree* maketree()
// {
//     int data;
//     cin>>data;
//     if(data==-1)
//     {
//         return NULL;
//     }
//     tree* root=new tree(data);
//     root->left=maketree();
//     root->right=maketree();
//     return root;
// }
// int findpath(tree* root,int target,int &sum,vector<int>&v,vector<int>&v1)
// {
//     if(root==NULL)
//     {
//         return 0;
//     }
//     sum=sum+root->data;
//     v.push_back(root->data);
//     if(sum==target)
//     {
//         int size=v.size();
//         for(int i=0;i<size;i++)
//         {
//             v1.push_back(v[i]);
//         }
//     }
//     int leftside=findpath(root->left,target,sum,v,v1);
//     int rightside=findpath(root->right,target,sum,v,v1);
//         int last=v.back();
//         v.pop_back();
//         sum=sum-last;
// }
// int main()
// {
//     tree* root=maketree();
//     int target=14;
//     int sum=0;
//     vector<int>v;
//     vector<int>v1;
//     findpath(root,target,sum,v,v1);
//     for(int i=0;i<v1.size();i++)
//     {
//         cout<<v1[i]<<endl;
//     }
// }
    