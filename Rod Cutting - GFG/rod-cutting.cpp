// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int help(int arr[],int len[],int n,int maxlen,vector<vector<int>>&dp){
        if(n==0 || maxlen==0)return 0;
        if(dp[n][maxlen]!=-1)return dp[n][maxlen];
        if(len[n-1]<=maxlen)return dp[n][maxlen]=max(arr[n-1]+help(arr,len,n,maxlen-len[n-1],dp),help(arr,len,n-1,maxlen,dp));
        return dp[n][maxlen]=help(arr,len,n-1,maxlen,dp);
    }
  
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int len[n];
        for(int i=0;i<n;i++)len[i]=i+1;
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=n;j++){
        //         if(i==0 || j==0)dp[i][j]=0;
        //     }
        // }
        // for(int i=1;i<n+1;i++){
        //     for(int j=1;j<n+1;j++){
        //         if(i-1<=j)dp[i][j]=max(price[i-1]+dp[i][j-i+1],dp[i-1][j]);
        //         else dp[i][j]=dp[i-1][j];            
                
        //     }
            
        // }
        return help(price,len,n,n,dp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends