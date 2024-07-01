#include<iostream>
using namespace std;
#include<queue>
#include<string>
int main()
{
    cout<<"Enter the size of the string ";
    string a;
    cout<<endl<<"Enter the string "<<endl;
    cin>>a;
    queue<char>q;
    //make string store non repeating character of stream
    string s="";
    //make array to store the count of all alphabate
    int arr[26]={0};
    for(int i=0;i<a.size();i++)
    {
        //find index of alphabet in array the increment its value
        arr[a[i]-'a']++;
        //push the element in the queue
        q.push(a[i]);
        //check queue if the count of the first element of the queue is greater than 1 then pop from the queue else store that front element in the string
        while(!q.empty())
        {
            if(arr[q.front()-'a']>1)
            {
                q.pop();
            }
            else
            {
                s.push_back(q.front());
                break;
            }
            //if frequency of all the elements of the queue is greater than 1 then store #
            if(q.empty())
            {
                s.push_back('#');
            }
        }
    }
    //print non repeating character of the stream
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i];
    }
}