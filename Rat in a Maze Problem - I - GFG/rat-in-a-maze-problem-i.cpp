// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    
    bool isOk(vector<vector<int>> &m,string &s,vector<vector<int>>&vis,int n ,int r,int c){
        if(r==-1 || r==n || c==-1 || c==n || vis[r][c] || m[r][c]==0)return false;
        return true;
    }
    
    void help(vector<vector<int>> &m,string &s,vector<vector<int>>&vis,int n ,int r,int c){
        if(r==-1 || r==n || c==-1 || c==n || m[r][c]==0 || vis[r][c])return;
        if(r==n-1 && c==n-1){
            ans.push_back(s);
            return;
        }
        vis[r][c]=1;
        if(isOk(m,s,vis,n,r+1,c)){
            s.push_back('D');
            help(m,s,vis,n,r+1,c);
            s.pop_back();
        }
        if(isOk(m,s,vis,n,r-1,c)){
            s.push_back('U');
            help(m,s,vis,n,r-1,c);
            s.pop_back();
        }
        if(isOk(m,s,vis,n,r,c+1)){
            s.push_back('R');
            help(m,s,vis,n,r,c+1);
            s.pop_back();
        }
        if(isOk(m,s,vis,n,r,c-1)){
            s.push_back('L');
            help(m,s,vis,n,r,c-1);
            s.pop_back();
        }
        vis[r][c]=0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string s;
        vector<vector<int>>vis(n,vector<int>(n,0));
        help(m,s,vis,n,0,0);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends