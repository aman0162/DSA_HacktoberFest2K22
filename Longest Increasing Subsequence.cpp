
#include<bits/stdc++.h>
using namespace std;

    int solveTab(vector<int>&nums)
    {
        int n=nums.size();
        vector<vector<int> >dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int pre=curr-1;pre>=-1;pre--)
            {
                int include=0;
                if(pre==-1 or nums[pre]<nums[curr])
                    include=1+dp[curr+1][curr+1];
                int exclude=dp[curr+1][pre+1];
                dp[curr][pre+1]=max(include,exclude);
            }
            
        }
        return dp[0][0];
    }


    int lengthOfLIS(vector<int>& nums) {
        return solveTab(nums);
    }

int main()
{

    int n;
    cin >> n;
    vector<int> nums(n, 0);
    
    for(int i=0;i<n;i++)
        cin >> nums[i];
        
    int r = lengthOfLIS(nums);
    
    cout << r;

    return 0;
}
