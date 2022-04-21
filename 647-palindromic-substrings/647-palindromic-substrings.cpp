class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n));
        int i=0,j=0;
        while(i<n && j<n){
            int k=i,l=j;
            while(i<n && j<n){
                if(i==j)dp[i][j]=1;
                else{
                    if(s[i]==s[j]){
                        if(j-i==1)dp[i][j]=1;
                        else dp[i][j]=dp[i+1][j-1];
                    }
                }
                i++;
                j++;
            }
            i=k,j=l;
            j++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j])ans++;
            }
        }
        return ans;
    }
};