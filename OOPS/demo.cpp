#include<iostream>
using namespace std; 
#include<string.h>
//#include<stdio.h>
int main()
{
    string s[10];
    for(int i=0;i<10;i++)
    {
        cin>>s[i];
    }
    int size=s[1].length();
    cout<<size;
}