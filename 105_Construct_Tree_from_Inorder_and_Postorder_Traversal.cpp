//problem on this code
#include<iostream>
using namespace std;
#include<queue>
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
int find(int inorder[],int size,int val)
{
    for(int i=0;i<size;i++)
    {
        if(val==inorder[i])
        {
            return i;
        }
    }
    return -1;
}
Tree* InorderAndPostorder(int inorder[],int postorder[],int size,int &postorderstart,int const &inorderstart,int const &inorderend)
{
    if(postorderstart<0||inorderstart>inorderend)
    {
        return NULL;
    }
    //phir ham preorder vale index ko ek node bana kar usme dal dange sath hi uska index ko aage bhi bhada dange
    Tree* root=new Tree(postorder[postorderstart--]);
    //firstly ham preorder ke starting vale index ko inorder me search karange ki vo konse index par h
    int index=find(inorder,size,postorder[postorderstart]);
    //yha ham firstly root ke right me insert karange to index jo aaya tha uska -1 hamara inorder ka starting index hoga
    //LRN
    root->right=InorderAndPostorder(inorder,postorder,size,postorderstart,index+1,inorderend);
    //yha ham firstly root ke left me insert karange to index jo aaya tha uska -1 hama inorder ka ending index hoga left k lyea
    root->left=InorderAndPostorder(inorder,postorder,size,postorderstart,inorderstart,index-1);
    return root;
}
int main()
{
    int size=7;
    int inorder[7]={4,2,7,5,1,6,3};
    int postorder[7]={6,3,7,5,4,2,1};
    
    int postorderstart=size-1;
    int inorderstart=0;
    int inorderend=size-1;
    Tree* root=InorderAndPostorder(inorder,postorder,size,postorderstart,inorderstart,inorderend);
    levelOrderTraversal(root);
}