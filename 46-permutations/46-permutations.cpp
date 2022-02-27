class Solution {
public:
    vector<vector<int>>ans;
    void help(vector<int>&nums,vector<int>&s,int n,vector<int>&vis,int i){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }
        for(int j=0;j<n;j++){
            if(vis[j]==1)continue;
            vis[j]=1;
            s.push_back(nums[j]);
            help(nums,s,n,vis,j+1);
            s.pop_back();
            vis[j]=0;
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>s;
        vector<int>vis(nums.size(),0);
        help(nums,s,nums.size(),vis,0);
        return ans;
    }
};