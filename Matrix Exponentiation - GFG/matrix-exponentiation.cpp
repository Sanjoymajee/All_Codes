// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

const long long MOD=1000000007;

class Solution {
public:
    vector<vector<long long>> Mutliply(vector<vector<long long> >& mA, vector<vector<long long>>&mB) {
        int n=mA.size();
        int m=mA[0].size();
        int r=mB[0].size();
        vector<vector<long long> >Nm(n,vector<long long>(r));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < r; j++){
                Nm[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    Nm[i][j] += (mA[i][k] * mB[k][j])%MOD;
                    Nm[i][j]%=MOD;
                }
            }
        }
        return Nm;
    }
 
    vector<vector<long long>> power(vector<vector<long long>> M,long long y,int n){
        vector<vector<long long>> ans(n,vector<long long>(n,0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(i==j)ans[i][j]=1;
            }
        }
        while(y){
            if(y%2){
                ans=Mutliply(ans,M);
                y--;
            }
            else{
                M=Mutliply(M,M);
                y/=2;
            }
        }
        return ans;
    }
    
    long long fib(long long n) {
        if(n==0)return 0;
        if(n==1)return 1;
        vector<vector<long long>> M={{0,1},{1,1}};
        vector<vector<long long>> Pm=power(M,n-1,2);
        vector<vector<long long>> P={{0,1}};
        // for(auto a:Pm){
        //     for(auto b:a)cout<<b<<" ";
        //     cout<<endl;
        // }
        Pm=Mutliply(P,Pm);
        // for(auto a:Pm){
        //     for(auto b:a)cout<<b<<" ";
        //     cout<<endl;
        // }
        return (long long)Pm[0][1]%1000000007;
        
    }
    
    int FindNthTerm(long long n) {
        return fib(n+1);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends