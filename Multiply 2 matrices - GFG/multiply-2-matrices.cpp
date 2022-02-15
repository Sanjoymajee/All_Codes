// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    void Mutliply(vector<vector<int> >& mA, vector<vector<int>>&mB) {
        int n=mA.size();
        vector<vector<int> >Nm(n,vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                Nm[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    Nm[i][j] += mA[i][k] * mB[k][j];
                }
                // cout<<Nm[i][j]<<" ";
            }
            // cout<<endl;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                mA[i][j]=Nm[i][j];
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
		vector<vector<int>> matrixA(n, vector<int>(n,0));
		vector<vector<int>> matrixB(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrixA[i][j];
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrixB[i][j];
			}
		}
		Solution ob;
		ob.Mutliply(matrixA, matrixB);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout << matrixA[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends