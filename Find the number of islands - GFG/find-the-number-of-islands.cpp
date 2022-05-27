// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool isLand(vector<vector<char>>& grid,int row,int col,vector<vector<int>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        if(row>=0 && col>=0 && row<n && col<m && grid[row][col]=='1' && !vis[row][col])return true;
        return false;
    }
    
    void traverse(vector<vector<char>>& grid,int row,int col,vector<vector<int>>&vis){
        vis[row][col]=1;
        int nrow[] = {-1,-1,-1,1,1,1,0,0};
        int ncol[] = {-1,1,0,-1,0,1,-1,1};
        
        for(int i=0;i<8;i++){
            if(isLand(grid,row+nrow[i],col+ncol[i],vis)){
                traverse(grid,row+nrow[i],col+ncol[i],vis);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    traverse(grid,i,j,vis);
                    count++;
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends