// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<int,int>m;
	    int sum=0,len=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	        int rem=sum%k;
	        if(rem<0)rem+=k;
	        if(rem==0)len=i+1;
	        if(m.find(rem)!=m.end()){
	            if(len<i-m[rem])len=i-m[rem];
	        }
	        else m[rem]=i;
	    }
	    return len;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends