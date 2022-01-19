// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
	bool binarySearch(int A[], int n, int target){
	    int l=0,r=n-1;
	    while(l<=r){
	        int mid=l+(r-l)/2;
	        if(A[mid]==target)return true;
	        if(A[mid]<target)l=mid+1;
	        else r=mid-1;
	    }
	    return false;
	}
	
	int findPair(int A[], int n, int B[], int m, int sum1, int sum2){
	    if(sum1<sum2)return findPair(B,m,A,n,sum2,sum1);
	    int diff=(sum1-sum2);
	    if(diff%2)return -1;
	    for(int i=0;i<m;i++){
	        int search=diff/2+B[i];
	        if(binarySearch(A,n,search))return 1;
	    }
	    return -1;
	}
	
	int findSwapValues(int A[], int n, int B[], int m)
	{
        sort(A,A+n);sort(B,B+m);
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++)sum1+=A[i];
        for(int i=0;i<m;i++)sum2+=B[i];
        return findPair(A,n,B,m,sum1,sum2);
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends