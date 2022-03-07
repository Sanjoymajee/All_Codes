// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector<int> leftSmaller(int arr[], int n){
        stack<int>s;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }
    
    vector<int> rightSmaller(int arr[], int n){
        stack<int>s;
        vector<int>ans(n,n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }
    
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int>left=leftSmaller(arr,n);
        vector<int>right=rightSmaller(arr,n);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int l=right[i]-left[i]-2;
            ans[l]=max(ans[l],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            ans[i]=max(ans[i],ans[i+1]);
        }
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
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends