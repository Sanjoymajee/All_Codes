class Solution {
public:
    // set<vector<int>>s;
    vector<vector<int>>ans;
    void help(vector<int>&cand,int j,int n,int tar,vector<int>v){
        if(tar==0){
            // sort(v.begin(),v.end());
            ans.push_back(v);
            return;
        }
        if(tar<0)return;
        for(int i=j;i<n;i++){
            if(cand[i]>tar)break;
            if(i>j && cand[i-1]==cand[i])continue;
            v.push_back(cand[i]);
            help(cand,i+1,n,tar-cand[i],v);
            v.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        int n=cand.size();
        sort(cand.begin(),cand.end());
        help(cand,0,n,target,{});
        // for(auto a:s)ans.push_back(a);
        return ans;
    }
};