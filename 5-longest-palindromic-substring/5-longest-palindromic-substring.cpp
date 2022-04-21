class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        pair<int,int>cord;
        int len=0;
        for(int i=0;i<n;){
            int l=i;
            int r=i;
            while(r<n-1 && s[r]==s[r+1])r++;
            i=r+1;
            while(l>0 && r<n && s[l-1]==s[r+1])l--,r++;
            int temp=r-l+1;
            if(temp>=len){
                len=temp;
                cord={l,r};
            }
        }
        return s.substr(cord.first,len);
    }
};