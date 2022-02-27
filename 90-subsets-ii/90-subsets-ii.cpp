class Solution {
public:
    set<vector<int>>ans;
    
    void help(vector<int>&nums,vector<int>&s,int n,int i){
        ans.insert(s);
        for(int j=i;j<n;j++){
            s.push_back(nums[j]);
            help(nums,s,n,j+1);
            s.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>s;
        help(nums,s,nums.size(),0);
        vector<vector<int>> res;
        for(auto a:ans){
            res.push_back(a);
        }
        return res;
    }
};