class Solution {
public:
    int minMoves(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int inc=0,ans=0;
        for(int j=1;j<n;j++){
            nums[j]+=inc;
            ans+=(nums[j]-nums[i]);
            inc+=(nums[j]-nums[i]);
            i++;
        }
        // for(int i=0;i<n;i++)cout<<nums[i]<<endl;
        return ans;
    }
};