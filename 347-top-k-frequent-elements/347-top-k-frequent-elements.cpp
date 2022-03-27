class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(auto a:nums)m[a]++;
        priority_queue<pair<int,int>>pq;
        for(auto a:m)pq.push({a.second,a.first});
        vector<int>ans;
        while(!pq.empty() && k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};