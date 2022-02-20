class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    set<int>s(nums.begin(),nums.end());
        map<int,int>m;
        int p=-1,q=-1;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto a:m){
            if(a.second==2){
                p=a.first;
                break;
            }
        }
        int i=1;
        for(auto a:s){
            if(a!=i){
                q=i;
                break;
            }
            i++;
        }
        if(q==-1)q=s.size()+1;
        return {p,q};
    }
};