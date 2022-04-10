class Solution {
public:
//     int help(vector<int>&A,int n,int amt,vector<vector<int>>&dp){
//         if(amt==0)return 1;
//         if(amt<0 || n<=0)return 0;
//         if(dp[n][amt]!=-1)return dp[n][amt];
//         if(amt>=A[n-1])return dp[n][amt]=help(A,n,amt-A[n-1],dp)+help(A,n-1,amt,dp);
//         else return dp[n][amt]=help(A,n-1,amt,dp);
//     }
    
    int change(int amount, vector<int>& A) {
        int n=A.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1));
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(j>=A[i-1])dp[i][j]=dp[i][j-A[i-1]]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][amount];
    }
};