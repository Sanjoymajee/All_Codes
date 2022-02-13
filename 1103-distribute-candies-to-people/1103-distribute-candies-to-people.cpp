class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int>ans(n);
        int i=1;
        while(candies>=i){
            // cout<<candies<<","<<i<<endl;
            ans[(i-1)%n]+=i;
            
            candies-=i;
            i++;
        }
        ans[(i-1)%n]+=candies;
        return ans;
    }
};