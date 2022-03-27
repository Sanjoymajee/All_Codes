class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        for(auto c:s)m[c]++;
        priority_queue<pair<int,char>>pq;
        for(auto a:m)pq.push({a.second,a.first});
        string ans="";
        
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            while(p.first--){
                ans+=p.second;
            }
        }
        return ans;
    }
};