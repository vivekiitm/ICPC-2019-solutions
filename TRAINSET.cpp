#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
#define debug(x) cout<<#x<<'='<<(x)<<endl
#define pb push_back
using namespace std;
int t,n,ans,temp1,temp2,temp,i,j,tem;
string str;
int main()
{
    cin>>t;
    while(t--)
    {
        vector<string> str0;
        vector<string> str1;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>str>>temp;
            if(temp==0)
                str0.pb(str);
            else
                str1.pb(str);
        }
        sort(str0.begin(),str0.end());
        sort(str1.begin(),str1.end());
        temp1=str0.size();
        temp2=str1.size();
        i=0;
        j=0;
        ans=0;
        while(i<temp1&&j<temp2)
        {
            if(str0[i]==str1[j]){
            tem=1;
            temp=1;
            i++;
            j++;
            while(str0[i]==str0[i-1])
            {
                i++;
                tem++;
                if(i>=temp1)
                    break;
            }
            while(str1[j]==str1[j-1])
            {
                j++;
                temp++;
                if(j>=temp2)
                    break;
            }
            ans=ans+max(tem,temp);}
            else if(str0[i]<str1[j])
            {
                temp=1;
                i++;
                while(str0[i]==str0[i-1])
                {
                    i++;
                    temp++;
                    if(i<temp1)
                        break;
                }
                ans=ans+temp;
            }
            else if(str0[i]>str1[j])
            {
                temp=1;
                j++;
                while(str1[j]==str1[j-1])
                {
                    j++;
                    temp++;
                    if(j<temp2)
                        break;
                }
                ans=ans+temp;
            }
        }
        ans=ans+temp1-i+temp2-j;
        cout<<ans<<endl;
    }
}
