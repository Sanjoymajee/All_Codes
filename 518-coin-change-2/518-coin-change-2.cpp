class Solution {
public:
    int help(vector<int>&A,int n,int amt,vector<vector<int>>&dp){
        if(amt==0)return 1;
        if(amt<0 || n<=0)return 0;
        if(dp[n][amt]!=-1)return dp[n][amt];
        if(amt>=A[n-1])return dp[n][amt]=help(A,n,amt-A[n-1],dp)+help(A,n-1,amt,dp);
        else return dp[n][amt]=help(A,n-1,amt,dp);
    }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return help(coins,n,amount,dp);
    }
};