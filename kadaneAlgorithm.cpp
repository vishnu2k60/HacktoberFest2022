/***********************Hacktober Fest 2021******************/

/*****
	Solution by :- manishmotwani2002(Github Username)
	Question:- Kadane's Algorithm
	Explaination:- Kadane's algorithm is used to search for maximum sum contiguous subarray within a 1-D integer array.
	
	Input:- 
	9
	-2 1 -3 4 -1 2 1 -5 4
	
	Output:- 
	6
	
	Justification:- 
	[4,-1,2,1] has the largest sum = 6.
	
***********/

#include<bits/stdc++.h>
using namespace std;


int maxSubArray(vector<int>& nums) {		//function for kadane algorithm
	
    int sum=0;
    int maximum=nums[0];
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        maximum=max(sum,maximum);
        if(sum<0)
        {
            sum=0;
        }
    }
        return maximum;		//return the maximum sum
}
int main()
{
	int i,n,element;
	cin>>n;			//fetching total size of array
	
	vector<int> user_input;
	
	for(i=0;i<n;i++)
	{
		cin>>element;
		user_input.push_back(element);		//fetching user input of array values
	}

	int ans = maxSubArray(user_input);
	
	cout<<ans;			//providing maximum sum as outuput
}
