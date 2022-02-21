class Solution {
public:
    char findTheDifference(string s, string t) {
        int z=0;
        for(auto c:s)z^=(c-'a');
        for(auto c:t)z^=(c-'a');
        return z+'a';
    }
};