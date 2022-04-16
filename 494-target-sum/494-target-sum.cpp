class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int tot=0;
        for(auto a:nums)tot+=a;
        // vector<vector<int>>dp(n+1,vector<int>(tot+1));
        // for(int i=0;i<n+1;i++)dp[i][0]=1;
        // for(int i=1;i<n+1;i++){
        //     for(int j=0;j<tot+1;j++){
        //         if(nums[i-1]<=j)dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
        //         else dp[i][j]=dp[i-1][j];
        //     }
        // }
        if(abs(target)>tot)return 0;
        int sum=target+tot;
        if(sum&1)return 0;
        sum=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(tot+1,0));
        dp[0][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=(dp[i-1][j-nums[i-1]]+dp[i-1][j]);
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};