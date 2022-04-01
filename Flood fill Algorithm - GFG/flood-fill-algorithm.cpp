// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void help(vector<vector<int>>&im,int n,int m,int r,int c,int nc,vector<vector<int>>&vis,int pc){
        if(r==-1 || r==n || c==-1 || c==m || im[r][c]!=pc || vis[r][c])return;
        vis[r][c]=1;
        im[r][c]=nc;
        help(im,n,m,r+1,c,nc,vis,pc);
        help(im,n,m,r,c+1,nc,vis,pc);
        help(im,n,m,r-1,c,nc,vis,pc);
        help(im,n,m,r,c-1,nc,vis,pc);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        help(image,n,m,sr,sc,newColor,vis,image[sr][sc]);
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends