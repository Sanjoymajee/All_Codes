// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        map<char,int>m;
        m['I']= 1;
        m['V']= 5;
        m['X']= 10;
        m['L']= 50;
        m['C']= 100;
        m['D']= 500;
        m['M']= 1000;
        stack<char>s;
        for(auto c:str){
            s.push(c);
        }
        int sum=0;
        int ref=INT_MIN;
        while(!s.empty()){
            if(ref<=m[s.top()]){
                sum+=m[s.top()];
            }
            else{
                sum-=m[s.top()];
            }
            // cout<<sum<<endl;
            ref=m[s.top()];
            s.pop();
        }
        return sum;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends