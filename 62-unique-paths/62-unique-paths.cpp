class Solution {
public:
    int dp[101][101];
    int help(int m,int n){
        if(m==1 && n==1)return dp[m][n]=1;
        if(m<=0 || n<=0)return dp[m][n]=0;
        if(dp[m][n]!=-1)return dp[m][n];
        int d=help(m-1,n);
        int l=help(m,n-1);
        return dp[m][n]=d+l;
    }
    
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return help(m,n);
    }
};