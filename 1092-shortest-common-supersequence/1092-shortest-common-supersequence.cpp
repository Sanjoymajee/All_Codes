class Solution {
public:
    string shortestCommonSupersequence(string X, string Y) {
        int n=X.size();
        int m=Y.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(X[i-1]==Y[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string ans;
        int i=n,j=m;
        while(i>=1 && j>=1){
            if(X[i-1]==Y[j-1]){
                ans.push_back(X[i-1]);
                i--;j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans.push_back(X[i-1]);
            i--;
                }
                else {
                    ans.push_back(Y[j-1]);
                    j--;
                }
            }
        }
        while(i>=1){
            ans.push_back(X[i-1]);
            i--;
        }
        while(j>=1){
            ans.push_back(Y[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};