class Solution {
public:
    int help(vector<int>&cost,int i,int n,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int fs=help(cost,i+1,n,dp)+cost[i];
        int ss=help(cost,i+2,n,dp)+cost[i];
        return dp[i]=min(fs,ss);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(help(cost,0,n,dp),help(cost,1,n,dp));
    }
};