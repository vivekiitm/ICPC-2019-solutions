#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int temp1;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int a[10]={0};
        int index=0;
        int temp=n;
        while(temp>0)
        {
            a[index]=temp%10;
            temp=temp/10;
            index++;
        }
        int num[10]={0};
        temp=n/10;
        int temp1;
        int cond;
        for(int j=0;j<10;j++)
        {
            temp1=0;
            cond=0;
            for(int k=0;k<10;k++)
            {
                if(j!=k)
                    temp1=temp1+a[k]*(int)(pow(10,k-cond)+0.5);
                if(j==k)
                    cond=1;
            }
            num[j]=temp1;
            if(temp>temp1)
                temp=temp1;
        }
        cout<<temp<<endl;
    }
}
