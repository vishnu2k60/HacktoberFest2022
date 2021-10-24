// Maximum area histogram problem

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve_stack(int a[],int n)
{
    vector<int> v1,v2;
    stack<pair<int,int>> s1,s2;
    int i,j;
    // Nearest smallest to left
    for(i=0;i<n;++i)
    {
        if(s1.size()==0)
            v1.push_back(-1);
        else if(a[i]>s1.top().first)
            v1.push_back(s1.top().second);
        else{
            while(s1.size()!=0 && s1.top().first>a[i])
                 s1.pop();
                 if(s1.size()==0)
                    v1.push_back(-1);
                else
                    v1.push_back(s1.top().second);
            }
        s1.push(make_pair(a[i],i));
    }

    // Nearest smallest to right
     for(i=n-1;i>=0;--i)
    {
        if(s2.size()==0)
            v2.push_back(n);
        else if(a[i]>s2.top().first)
            v2.push_back(s2.top().second);
        else{
            while(s2.size()!=0 && s2.top().first>=a[i])
                 s2.pop();
                 if(s2.size()==0)
                    v2.push_back(n);
                else
                    v2.push_back(s2.top().second);
            }
        s2.push(make_pair(a[i],i));
    }

    reverse(v2.begin(),v2.end());

    int t[n];
    for(i=0;i<n;++i){
        t[i]=a[i]*(v2[i]-v1[i]-1);
    }
    sort(t,t+n);
    cout<<t[n-1];

}

int main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;++i)
        cin>>a[i];
    solve_stack(a,n);
    return 0;

}
