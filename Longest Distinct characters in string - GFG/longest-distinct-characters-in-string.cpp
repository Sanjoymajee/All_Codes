// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


bool unique(vector<int>&cnt){
    for(auto a:cnt){
        if(a>1)return false;
    }
    return true;
}

void show(vector<int>cnt){
    for(auto a:cnt)cout<<a<<" ";
    cout<<endl;
}

int longestSubstrDistinctChars (string S)
{
    vector<int>cnt(26,0);
    int ans=0,cn=0;
    int j=0;
    for(int i=0;i<S.size();i++){
        cnt[S[i]-'a']++;
        // show(cnt);
        if(unique(cnt)){
            ans=max(ans,i-j+1);
        }
        else{
            while(!unique(cnt)){
                cnt[S[j]-'a']--;
                j++;
            }
            
        }
    }
    return ans;
}