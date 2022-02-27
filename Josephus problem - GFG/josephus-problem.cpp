// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    int help(vector<int>&v,int k,int cur){
        if(v.size()==1)return v[0]+1;
        int cand=(cur+k-1)%(v.size());
        v.erase(v.begin()+cand);
        return help(v,k,cand);
    }
    
    int josephus(int n, int k)
    {
        vector<int>v(n);
        for(int i=0;i<n;i++)v[i]=i;
        return help(v,k,0);
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends