class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int tsum=0;
        int n=nums.size();
        for(auto a:nums)tsum+=a;
        if(tsum&1)return 0;
        tsum=tsum/2;
        bool dp[n+1][tsum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<tsum+1;j++){
                if(i==0)dp[i][j]=0;
                if(j==0)dp[i][j]=1;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<tsum+1;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][tsum];
    }
};