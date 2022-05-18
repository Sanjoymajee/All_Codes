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
	    int V=matrix.size();
	    int dist[V][V];
	    for(int i=0;i<V;i++){
	        for(int j=0;j<V;j++){
	            if(matrix[i][j]!=-1)
	                dist[i][j]=matrix[i][j];
                else dist[i][j]=INF;
	        }
	    }
	         // Pick all vertices as source one by one
        for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination for the
            // above picked source
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
	    for(int i=0;i<V;i++){
	        for(int j=0;j<V;j++){
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