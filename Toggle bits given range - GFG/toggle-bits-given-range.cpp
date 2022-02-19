// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int toggleBits(int N , int L , int R) {
        for(int i=L-1;i<R;i++)N=(N^(1<<i));
        return N;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        
        cin>>N>>L>>R;

        Solution ob;
        cout << ob.toggleBits(N,L,R) << endl;
    }
    return 0;
}  // } Driver Code Ends