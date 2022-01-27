class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>m;
        for(auto c:s)m[c]++;
        int ans=0;
        int mx=0;
        bool ok=false;
        for(auto a:m){
            if(a.second%2==0){
                ans = ans + a.second;
            }
            else if(a.second%2==1){
                ans = ans + a.second - 1;
                ok=true;
            }
        }
        if(ok)ans++;
        return ans;
    }
};