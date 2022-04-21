class Solution {
public:
    int dp[301][301];
    int help(vector<int>&nums, int i, int j){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        for(int k=i; k<=j; k++){
            ans=max(ans, nums[i-1]*nums[k]*nums[j+1]+help(nums, i, k-1)+help(nums, k+1, j));
        }
        return dp[i][j]=ans;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return help(nums,1,n-2);
    }
};