// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int N){
        if(N<=6)return N;
        vector<long long>ans(N);
        for(int i=1;i<=6;i++)ans[i-1]=i;
        for(int i=7;i<=N;i++){
            ans[i-1]=max({2*ans[i-4],3*ans[i-5],4*ans[i-6]});
        }
        return ans[N-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends