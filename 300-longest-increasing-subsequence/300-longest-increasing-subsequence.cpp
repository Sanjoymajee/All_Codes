class Solution {
public:
    int help(vector<int>&nums,int i,int prv,vector<vector<int>>&dp){
        if(i==nums.size())return 0;
        if(dp[i][prv+1]!=-1)return dp[i][prv+1];
        int notake=help(nums,i+1,prv,dp);
        int take=0;
        if(prv==-1 || nums[prv] < nums[i])take=help(nums,i+1,i,dp)+1;
        return dp[i][prv+1]=max(take,notake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return help(nums,0,-1,dp);
    }
};