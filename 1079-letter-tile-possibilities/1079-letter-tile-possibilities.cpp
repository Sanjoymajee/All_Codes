class Solution {
public:
    set<string>res;
    int fact[8];
    
    int permute(string &s){
        vector<int>cnt(26,0);
        for(auto c:s)cnt[c-'A']++;
        int ans=fact[s.size()];
        for(auto a:cnt)ans/=fact[a];
        return ans;
    }
    
    int help(string &tiles,string s,int n,int i){
        if(i>=n){
            return res.insert(s).second ? permute(s):0;
        }
        return help(tiles,s,n,i+1)+help(tiles,s+tiles[i],n,i+1);
    }
    
    int numTilePossibilities(string tiles) {
        fact[0]=1;
        for(int i=1;i<8;i++){
            fact[i]=i*fact[i-1];
        }
        sort(tiles.begin(),tiles.end());
        int n=tiles.size();
        return help(tiles,"",n,0)-1;
    }
};