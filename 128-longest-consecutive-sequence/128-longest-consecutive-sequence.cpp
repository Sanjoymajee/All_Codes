class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(int a:nums){
            s.insert(a);
        }
        int ans=0;
        for(int a:nums){
            int l=1;
            if(s.find(a-1)==s.end()){
                int num=a;
                while(s.find(num+1)!=s.end()){
                    l++;num++;
                }
                ans=max(ans,l);
            }
        }
        return ans;
    }
};