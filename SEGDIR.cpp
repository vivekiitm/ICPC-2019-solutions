#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
#define debug(x) cout<<#x<<'='<<(x)<<endl
#define pb push_back
using namespace std;
int temp1,temp2,temp3;


bool sortcol( const vector<int>& v1,
               const vector<int>& v2 ) {
 return v1[1] < v2[1];
}


int overlap(vector<pair<int, int> > v)
{
    int ans = 0;
    int count = 0;
    vector<pair<int, char> > data;
    for (int i = 0; i < v.size(); i++) {
        data.push_back({ v[i].first, 'x' });
        data.push_back({ v[i].second, 'y' });
    }
    sort(data.begin(), data.end());
    for (int i = 0; i < data.size(); i++) {
        if (data[i].second == 'x')
            count++;
        if (data[i].second == 'y')
            count--;
        ans = max(ans, count);
    }
    return ans;
}
int t,n,cond;
vector<int> temp;
vector< pair <int,int> > s;
vector<vector<int>> vec;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        vec.clear();
        for(int i=0;i<n;i++)
        {
            temp.clear();
            cin>>temp1>>temp2>>temp3;
            temp.pb(temp1);
            temp.pb(temp3);
            temp.pb(temp2);
            vec.push_back(temp);
        }
        sort(vec.begin(), vec.end(),sortcol);
        cond=1;
        int index=0;
        while(index<n)
        {
            s.clear();
            s.pb(make_pair(vec[index][0],vec[index][2]));
            index++;
            if(index<n-1){
            while(vec[index][1]==vec[index-1][1])
            {
                s.pb(make_pair(vec[index][0],vec[index][2]));
                index++;
                if(index>=n)
                    break;
            }}
            if(overlap(s)>=3)
                cond=0;
        }
        if(cond==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
