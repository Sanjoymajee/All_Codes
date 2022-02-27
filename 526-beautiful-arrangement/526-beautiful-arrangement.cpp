class Solution {
public:
    int ans=0;
    
    void help(vector<int>&v,vector<int>&s,vector<int>&vis,int n){
        if(s.size()==n){
            // for(auto a:s)cout<<a<<",";
            // cout<<endl;
            ans++;
            return;
        }
        for(int j=0;j<n;j++){
            if(vis[j])continue;
            // cout<<v[j]<<" "<<j+1<<endl;
            if((s.size()+1)%(j+1)==0 || (j+1)%(s.size()+1)==0){
                s.push_back(v[j]);
                vis[j]=1;
                help(v,s,vis,n);
                s.pop_back();
                vis[j]=0;
            }
        }
    }
    
    int countArrangement(int n) {
        vector<int>v(n);
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)v[i]=i+1;
        vector<int>s;
        help(v,s,vis,n);
        return ans;
    }
};