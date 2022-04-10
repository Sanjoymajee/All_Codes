class Solution {
public:
    int help(vector<int>&A,int n,int amt,vector<vector<int>>&dp){
        if(amt==0)return 0;
        if(n==0)return INT_MAX-1;
        if(dp[n][amt]!=-1)return dp[n][amt];
        if(A[n-1]<=amt)return dp[n][amt]=min(1+help(A,n,amt-A[n-1],dp),help(A,n-1,amt,dp));
        else return dp[n][amt]=help(A,n-1,amt,dp);
    }
    
    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amt+1,-1));
        int ans=help(coins,n,amt,dp);
        if(ans!=INT_MAX-1)return ans;
        return -1;
    }
};