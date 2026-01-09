class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(int x:nums)totalsum+=x;
        if(totalsum%2!=0)return false;
        int desired=totalsum/2;
        vector<vector<int>>dp(n+1,vector<int>(desired+1,0));
        //base case
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=desired;j++)
            {
                int nontake=dp[i-1][j];
                int take=0;
                if(nums[i-1]<=j)take=dp[i-1][j-nums[i-1]];
                dp[i][j]=take||nontake;
            }
        }
        return dp[n][desired];
    }
};