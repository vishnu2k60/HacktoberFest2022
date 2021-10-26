#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // dynamic programming
    long long int permutation(int n, int r){
        if(r > n){
            return 0;
        }
        if( r == 0){
            return 1;
        }
        long long int t[r+1][n+1];

        for(int i=0; i<r+1; i++){
            for(int j=0; j<n+1; j++){
                if( i == 0){
                    t[i][j] = 1;
                }
                else if(i == 1 && j > 0){
                    t[i][j] = j;
                }else{
                    t[i][j] = 0;
                }
            }
        }

        for(int i=2; i<r+1; i++){
            for(int j=1; j<n+1; j++){
                if(t[i][j] == 0 && i <= j){
                    if( i == j){
                        t[i][j] = t[i-1][j];
                    }else{
                        t[i][j] = t[i-1][j] * (j-i+1);
                    }
                }
            }
        }

        return t[r][n];
    }

};


int main() {
    Solution obj;
    int n, r;
    // N and r are more than or equal to zero.
    cout<<"N: ";
    cin>>n;
    cout<<endl<<"r: ";
    cin>>r;
    cout<<endl;
    long long int ans_1 = obj.permutation(n,r);
    cout<<"Answer of "<<n<<"P"<<r<<" is: "<<ans_1<<endl;

    return 0;
}
