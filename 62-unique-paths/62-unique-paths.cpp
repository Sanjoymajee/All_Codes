class Solution {
public:
    
    int uniquePaths(int m, int n) {
        vector<int>prv(n+1,1);
        vector<int>temp(n+1);
        
        for(int i=2;i<m+1;i++){
            temp[1]=prv[1];
            for(int j=2;j<n+1;j++){
                temp[j]=prv[j]+temp[j-1];
            }
            prv=temp;
        }
        return prv[n];
    }
};