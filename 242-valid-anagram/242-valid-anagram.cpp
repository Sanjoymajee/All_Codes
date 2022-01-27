class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>cnt1(26,0),cnt2(26,0);
        for(auto c:s)cnt1[c-'a']++;
        for(auto c:t)cnt2[c-'a']++;
        if(cnt1==cnt2)return true;
        return false;
    }
};