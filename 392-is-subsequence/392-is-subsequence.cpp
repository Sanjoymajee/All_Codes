class Solution {
public:
    int help(string &s,string &t,int n,int m,vector<vector<int>>&dp){
        if(n==0 || m==0)return 0;
        if(n==1 && s[n-1]==t[m-1])return 1;
        if(dp[n][m]!=-1)return dp[n][m];
        if(s[n-1]==t[m-1])return dp[n][m]=help(s,t,n-1,m-1,dp);
        else return dp[n][m]=help(s,t,n,m-1,dp);
    }
    
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n==0)return 1;
        else if(m==0)return 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return help(s,t,n,m,dp);
    }
};