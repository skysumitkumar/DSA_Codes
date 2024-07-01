#include<iostream>
using namespace std;
#include<queue>
#include<vector>
void FindNegativeInteger(int *arr,int size,int k)
{
    //create a queue to store indexes of negative element firstly
    queue<int> s;
    //create a vector to store ans
    vector<int> a;
    //process of first window of size =k
    for(int i=0;i<k;i++)
    {
        //if negative no found we push its index in new queue
        if(arr[i]<0)
        {
            s.push(i);
        }
    }//process the remaining window
    for(int i=k;i<size;i++)
    {
        //first store answer of previous window
        if(s.empty())
        {
            a.push_back(0);
        }
        else
        {
            int temp=s.front();
            a.push_back(arr[temp]);
        }
        //here pop elements that are out of window in the new queue
        while(!s.empty()&&(i-s.front())>=k)//remember here s.front insted of q.front
        {
            s.pop();//remember here we pop from the queue where we store the indexes
        }
        if(arr[i]<0)
        {
            s.push(i);
        }
        //q.pop();
    }
    //here we process last window that are not processed
    if(s.empty())
    {
        a.push_back(0);
    }
    else
    {
        int temp=s.front();
        a.push_back(arr[temp]);
    }
    cout<<endl<<"The first negative integer in window of size k is "<<endl;
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    
}
int main()
{
    cout<<"Enter the size of the aay ";
    int size;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the aay "<<endl;
    int v;
    for(int i=0;i<size;i++)
    {
        cin>>v;
        arr[i]=v;
    }
    cout<<endl<<"Enter the value of k ";
    int k;
    cin>>k;
    FindNegativeInteger(arr,size,k);
}