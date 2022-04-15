class Solution {
public:
    int help(vector<int>&nums,int i,int n,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=max(help(nums,i+2,n,dp)+nums[i],help(nums,i+1,n,dp));
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(n+1,-1),dp2(n+1,-1);
        return max(help(nums,0,n-1,dp1),help(nums,1,n,dp2));
    }
};