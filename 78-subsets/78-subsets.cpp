class Solution {
public:
    vector<vector<int>>A;
    void help(vector<int>&nums,vector<int>&s,int i){
        A.push_back(s);
        for(int j=i;j<nums.size();j++){
            s.push_back(nums[j]);
            help(nums,s,j+1);
            s.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>s;
        help(nums,s,0);
        return A;
    }
};