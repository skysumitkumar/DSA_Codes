 //incomplete questiion
 #include<iostream>
 using namespace std;
 #include<queue>
 int main()
 {
    queue<int>gas;
    cout<<"Enter the no of petrolpump ";
    int n,v;
    cin>>n;
    cout<<endl<<"Enter the gas ";
    for(int i=0;i<n;i++)
    {
      cin>>v;
      gas.push(v);
    }
    queue<int>cost;
    cout<<endl<<"Enter the cost ";
    for(int i=0;i<n;i++)
    {
      cin>>v;
      cost.push(v);
    }
    int lack=0,rem=0,newindex,i,su=0;
    for(i=0;i<n;i++)
    {
      int l=gas.front();
      int c=cost.front();
      int su=su+l-c;
      if(su<0)
      {
         lack=lack+(su);
         gas.pop();
         cost.pop();
         newindex=i;
      }
      else
      {
         rem=rem+su;
         gas.pop();
         cost.pop();
      }
    }
    if(-(lack)==rem)
    {
      cout<<"The petrol pump that you start is ";
      cout<<endl<<newindex+1;
    }
 }