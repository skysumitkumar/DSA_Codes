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
void PrintTopView(Tree* root)
{
    //firstly we make a map to store teh distance in this we have only unique distances and we are not update any map value
    map<int,int> mapping;
    //here we make a queue of pair that have a node and the distance mapping
    queue<pair<Tree*,int>>q;
    if(root==NULL)
    {
        return;
    }
    //push first node and map it with 0 because it is the root node;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        //here we make a temp that contain node and int value and give it the q.front() value
        pair<Tree*,int>temp=q.front();
        //pop the queue front
        q.pop();
        //here we make a pointer that take the node that are of temp first val
        Tree* node=temp.first;
        //here we make a integer that take the temp second value that are integer type
        int dis=temp.second;
        //here we check in map that jo bhi hamare pas yha distance aaya h vo already map me h ya nahi
        //yha agar hamara dis map me search karne par map end nahi hua to matlab we found that distance in the map or agar vo key hamare map me nahi meli to ye if me chala jyega
        if(mapping.find(dis)==mapping.end())
        {
            //here we create the entry in map
            mapping[dis]=node->data;
        }
        //here we check ki node ke left me koi node h ki nahi agar h to us node ko
        //or ham left me jaane par dis ko -1 karke save karange queue me
        if(node->left)
        {
            q.push(make_pair(node->left,dis-1));
        }
        //here we check ki node ke right me koi node h ki nahi agar h to us node ko 
        //or ham right me jaane par dis ko +1 karke save karange queue me
        if(node->right)
        {
            q.push(make_pair(node->right,dis+1));
        }
    }

    cout<<"Our top view elements are"<<endl;
    for(auto i: mapping)
    {
        cout<<i.second;
        cout<<endl;
    }

}
int main()
{
    Tree* root=makeTree();
    //levelOrderTraversal(root);
    map<int,int> mapping;
    PrintTopView(root);
}