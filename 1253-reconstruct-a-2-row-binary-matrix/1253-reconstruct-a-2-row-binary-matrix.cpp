class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int sum=upper+lower;
        int n=colsum.size();
        // int msum=0;
        // for(int i=0;i<n;i++)msum+=colsum[i];
        // if(sum!=msum)return {{}};
        vector<vector<int>>ans(2,vector<int>(n));
        int upper_sum=0,lower_sum=0;
        for(int i=0;i<n;i++){
            if(colsum[i]==2){
                ans[0][i]=1;
                ans[1][i]=1;
                upper_sum++;
                lower_sum++;
                colsum[i]=0;
            }
        }
        for(int i=0;i<n;i++){
            if(colsum[i]==1){
                if(upper_sum<upper){
                    ans[0][i]=1;
                    upper_sum++;
                }
                else{
                    ans[1][i]=1;
                    lower_sum++;
                }
            }
        }
        if(lower_sum!=lower || upper_sum!=upper)return {};
        return ans;
    }
};