
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m1,m2;
        int n=arr.size();
        for(auto a:arr)m1[a]++;
        for(auto a:m1){
            m2[a.second]++;
        }
        if(m1.size()==m2.size())return true;
        return false;
    }
};