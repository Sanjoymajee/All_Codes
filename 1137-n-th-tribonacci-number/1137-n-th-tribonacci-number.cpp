class Solution {
public:
    vector<vector<int>> Mutliply(vector<vector<int> >& mA, vector<vector<int>>&mB) {
        int n=mA.size();
        int m=mA[0].size();
        int r=mB[0].size();
        vector<vector<int> >Nm(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < r; j++){
                Nm[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    Nm[i][j] += (mA[i][k] * mB[k][j]);
                }
            }
        }
        return Nm;
    }
 
    vector<vector<int>> power(vector<vector<int>> M,int y,int n){
        vector<vector<int>> ans(n,vector<int>(n,0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(i==j)ans[i][j]=1;
            }
        }
        while(y){
            if(y%2){
                ans=Mutliply(ans,M);
                y--;
            }
            else{
                M=Mutliply(M,M);
                y/=2;
            }
        }
        return ans;
    }
    
    int tribonacci(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        if(n==2)return 1;
        vector<vector<int>> M={{0,0,1},{1,0,1},{0,1,1}};
        vector<vector<int>> Pm=power(M,n-2,3);
        vector<vector<int>> P={{0,1,1}};
        Pm=Mutliply(P,Pm);
        // for(auto a:Pm){
        //     for(auto b:a)cout<<b<<" ";
        // }
        return Pm[0][2];
    }
};