// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
  
    // bool help(int arr[], int n, int sum, vector<vector<int>>&dp){
    //     if(sum==0 && n==0)return 1;
    //     if(n==0)return 0;
    //     if(dp[n][sum]!=-1)return dp[n][sum];
    //     if(arr[n-1]<=sum)return dp[n][sum]=help(arr,n-1,sum-arr[n-1],dp) || help(arr,n-1,sum,dp);
    //     return dp[n][sum]=help(arr,n-1,sum,dp);
    // }
  
	int minDifference(int arr[], int n)  { 
	    int tot=0;
	    for(int i=0;i<n;i++)tot+=arr[i];
	    vector<vector<int>> dp(n+1,vector<int>(tot+1));
	    for(int i=0;i<n+1;i++){
	        dp[i][0]=1;
	    }
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<tot+1;j++){
	            if(arr[i-1]<=j)dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
	            else dp[i][j]=dp[i-1][j];
	        }
	    }
	    int ans=INT_MAX;
	    for(int i=tot/2;i>=0;i--){
	        if(dp[n][i])ans=min(tot-2*i,ans);
	    }
	    return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends