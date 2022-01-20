class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int x=0;
        int n=nums.size();
        while(x<n-2){
            int i=x+1,j=n-1;
            while(i<j){
                int sum=nums[x]+nums[i]+nums[j];
                if(sum==0){
                    ans.push_back({nums[x],nums[i],nums[j]});
                    int l=i,r=j;
                    while(i<j && nums[i]==nums[l])i++;
                    while(i<j && nums[j]==nums[r])j--;
                }
                else if(sum<0)i++;
                else j--;
            }
            int l=x;
            while(x<n-2 && nums[x]==nums[l])x++;
        }
        return ans;
    }
};