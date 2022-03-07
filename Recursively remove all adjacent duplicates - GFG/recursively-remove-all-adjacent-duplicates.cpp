// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    // map<char,int>m;
    string remove(string s){
        string ans;
        int n=s.size();
        int i=0,j=1;
        while(j<n){
            if(s[i]==s[j]){
                j++;
                if(j==n){
                    while(i<j){
                        s[i]='#';
                        i++;
                    }
                }
            }
            else{
                if(i+1==j){
                    i++;
                    j++;
                }
                else{
                    while(i<j){
                        s[i]='#';
                        i++;
                    }
                    j++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]!='#')
            ans.push_back(s[i]);
        }
        // cout<<ans<<","<<s<<","<<n<<endl;
        if(s==ans)return ans;
        return remove(ans);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends