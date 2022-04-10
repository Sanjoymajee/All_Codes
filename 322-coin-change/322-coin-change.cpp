class Solution {
public:
    // int help(vector<int>&A,int n,int amt,vector<vector<int>>&dp){
    //     if(amt==0)return 0;
    //     if(n==0)return INT_MAX-1;
    //     if(dp[n][amt]!=-1)return dp[n][amt];
    //     if(A[n-1]<=amt)return dp[n][amt]=min(1+help(A,n,amt-A[n-1],dp),help(A,n-1,amt,dp));
    //     else return dp[n][amt]=help(A,n-1,amt,dp);
    // }
    
    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amt+1));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<amt+1;j++){
                if(i==0)dp[i][j]=INT_MAX-1;
                if(j==0)dp[i][j]=0;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amt+1;j++){
                if(coins[i-1]<=j)dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                else dp[i][j]=dp[i-1][j];
            }
        }
        int ans=dp[n][amt];
        if(ans!=INT_MAX-1)return ans;
        return -1;
    }
};