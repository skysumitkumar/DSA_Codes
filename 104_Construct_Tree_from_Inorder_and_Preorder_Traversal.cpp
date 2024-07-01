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
Tree* InorderAndPreorder(int inorder[],int preorder[],int size,int &preorderstart,int const &inorderstart,int const &inorderend)
{
    //firstly we check ki preorder apne array se bhar to nahi chala gaya
    //or ham dakhange ki inorder vala array small hote hote uska inorederstart bada to nahi ho gaya inorderend se
    //agar esa h to matlab hamara tree ban chuka h ham leaf node par h
    if(preorderstart==size||inorderstart>inorderend)
    {
        return NULL;
    }
    //firstly ham preorder ke starting vale index ko inorder me search karange ki vo konse index par h
    int index=find(inorder,size,preorder[preorderstart]);
    //phir ham preorder vale index ko ek node bana kar usme dal dange sath hi uska index ko aage bhi bhada dange
    Tree* root=new Tree(preorder[preorderstart++]);
    //yha ham firstly root ke left me insert karange to index jo aaya tha uska -1 hama inorder ka ending index hoga left k lyea
    //NLR use hoga yha
    root->left=InorderAndPreorder(inorder,preorder,size,preorderstart,inorderstart,index - 1);
    //yha ham firstly root ke right me insert karange to index jo aaya tha uska +1 hamara inorder ka starting index hoga
    root->right=InorderAndPreorder(inorder,preorder,size,preorderstart,index + 1,inorderend);
    return root;
}
int main()
{
    int size=7;
    int inorder[7]={4,2,7,5,1,6,3};
    int preorder[7]={1,2,4,5,7,3,6};
    
    int preorderstart=0;
    int inorderstart=0;
    int inorderend=size-1;
    Tree* root=InorderAndPreorder(inorder,preorder,size,preorderstart,inorderstart,inorderend);
    levelOrderTraversal(root);
}