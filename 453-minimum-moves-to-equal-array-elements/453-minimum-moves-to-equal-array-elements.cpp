class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        int mn=*min_element(nums.begin(),nums.end());
        int ans=sum-mn*n;
        return ans;
    }
};