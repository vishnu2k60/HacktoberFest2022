// Pooja withdrawl ATM

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int x;
    float y;
    cin>>x;
    cin>>y;
    if(((x%5) != 0) || (y<=(x+0.5)) || (x==0))
    {
        cout<<fixed;
        cout<<setprecision(2);
        cout<<y<<endl;
    }
    else
    {
        y = y-x-0.50;
        cout<<fixed;
        cout<<setprecision(2);
        cout<<y<<endl;
    }
    return 0;    
}