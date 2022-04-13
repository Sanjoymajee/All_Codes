class Solution {
public:
    int isPal(string &s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j])return 0;
            i++,j--;
        }
        return 1;
    }
    
    int help(string &s,int i,int j,vector<vector<int>>&dp){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(isPal(s,i,j)){
            return dp[i][j]=0;
        }
         int ans=INT_MAX;
    
        for(int k=i;k<j;k++){
            if(isPal(s,i,k)){   
                int temp  = 1 + help(s,k+1,j,dp);
                ans = min(temp,ans);
            }
        }
        return dp[i][j]=ans;
    }
    
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return help(s,0,n-1,dp);
    }
};