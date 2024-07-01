#include<iostream>
#include<queue>
#include<map>
using namespace std;
class Tree
{
    public:
    int data;
    Tree* left;
    Tree* right;
    Tree(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
Tree* makeTree()
{
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    Tree* root=new Tree(data);
    root->left=makeTree();
    root->right=makeTree();
    return root;
}
void levelOrderTraversal(Tree* root)
{
    //Here we make the queue that store the trees
    queue<Tree* >q;
    //firstly we push the root tree
    q.push(root);
    //Then we push NULL because we have go to next level
    q.push(NULL);
    while(!q.empty())
    {
        //This loop is going while q is not empty
        Tree* temp=q.front();
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
// void PrintLeftView(Tree* root)
// {
//     //Here we make the queue that store the trees
//     queue<Tree* >q;
//     //firstly we push the root tree
//     q.push(root);
//     //Then we push NULL because we have go to next level
//     q.push(NULL);
//     //firstly we print the root node because it always see from both sides
//     cout<<root->data;
//     while(!q.empty())
//     {
//         //This loop is going while q is not empty
//         Tree* temp=q.front();
//         //then pop tree from the queue 
//         q.pop();
//         if(!q.empty()&&temp==NULL)
//         {
//             //for print next level in the next line
//             cout<<endl;
//             //here we print the front node data in the queue
//             cout<<q.front()->data;
//             //when we fount NULL then we also push NULL to track level
//             q.push(NULL);
//         }
//         else
//         {
//         if(temp->left)
//         {
//             //push that tree in the queue 
//             q.push(temp->left);
//         }
//         //here we check that tree have tree in the right side
//         if(temp->right)
//         {
//             //push that tree in the queue
//             q.push(temp->right);
//         }
//         }  
//     }
// }
void printleftview(Tree* root,vector<int>&v,int const &level)
{
    //if root is null then we return 
    if(root==NULL)
    {
        return;
    }
    //here we check our level if level is equal to the size of vector only than we push the node in vector
    if(level==v.size())
    {
        v.push_back(root->data);
    }
    //go to the left side
    printleftview(root->left,v,level+1);
    //go to the right side
    printleftview(root->right,v,level+1);
}
int main()
{
    Tree* root=makeTree();
    //levelOrderTraversal(root);
    //PrintLeftView(root);
    vector<int>v;
    int level=0;
    printleftview(root,v,level);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}