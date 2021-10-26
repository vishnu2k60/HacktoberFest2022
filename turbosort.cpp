// Sorting 
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int t, a;
    vector <int> v;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<t;i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}