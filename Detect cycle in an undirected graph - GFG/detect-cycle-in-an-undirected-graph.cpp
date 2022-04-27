// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int V,vector<int>adj[],vector<int>&vis,int i,int p){
        vis[i]=1;
        for(auto el : adj[i]){
            if(!vis[el]){
                if(dfs(V,adj,vis,el,i))return 1;
            }
            else if(el!=p)return 1;
        }
        return 0;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(V,adj,vis,i,-1))return 1;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends