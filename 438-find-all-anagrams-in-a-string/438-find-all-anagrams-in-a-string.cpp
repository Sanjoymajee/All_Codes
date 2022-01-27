class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>m1(26,0),m2(26,0),ans;
        int l=0;
        for(auto c:p)m1[c-'a']++;
        int n=s.size();
        for(int r=0;r<n;r++){
            m2[s[r]-'a']++;
            if(r-l+1<p.size())continue;
            if(r-l+1==p.size()){
                // cout<<l<<" "<<r<<endl;
                if(m1==m2)ans.push_back(l);
                m2[s[l]-'a']--;
                l++;
            }
        }
        return ans;
    }
};