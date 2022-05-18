// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    const int INF=1000000000;
    
	void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size();
	    int dist[n][n];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]!=-1)
	                dist[i][j]=matrix[i][j];
                else dist[i][j]=INF;
	        }
	    }
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                if (dist[i][j] > (dist[i][k] + dist[k][j])
                        && (dist[k][j] != INF
                            && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(dist[i][j]!=INF)
	                matrix[i][j]=dist[i][j];
                else matrix[i][j]=-1;
	        }
	    }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends