#include<iostream>
#include<queue>
#include<map>
using namespace std;
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
tree* maketree()
{
    int data;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    tree* root=new tree(data);
    root->left=maketree();
    root->right=maketree();
    return root;
}
void levelordertraversal(tree* root)
{
    queue<tree*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        tree* temp=q.front();
        q.pop();
        if(!q.empty()&&temp==NULL)
        {
            cout<<endl;
            q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void bottomview(tree* root)
{
    queue<pair<tree*,int>>q;
    map<int,int> topnode;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<tree*,int> temp=q.front();
        q.pop();
        tree* node=temp.first;
        int key=temp.second;
        if(topnode.find(key)==topnode.end())
        {
            topnode[key]=node->data;
        }
        if(node->left)
        {
            q.push(make_pair(node->left,key-1));
        }
        if(node->right)
        {
            q.push(make_pair(node->right,key+1));
        }
    }
    for(auto i=topnode.begin();i!=topnode.end();i++)
    {
        cout<<i->first<<" "<<i->second<<endl;
    }
}
int main()
{
    tree* root=maketree();
    bottomview(root);
}