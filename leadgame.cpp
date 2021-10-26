// Leadgame
#include<bits/stdc++.h>

using namespace std;

class lead
{
    int n, a, b;
    public:
        void getdata();
};

void lead :: getdata()
{
    int l=0, m, x=0, y=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        x = x + a;
        y = y + b;
        a = x - y;
        if(a < 0)
        {
            if(l < -(a))
            {
                l = -(a);
                m = 2;
            }
        }
        else
        {
            if(l < a)
            {
                l = a;
                m = 1;
            }
        }
    }
    cout<<m<<"\t"<<l<<endl;
}

int main()
{
    lead l1;
    l1.getdata();
    return 0;
}