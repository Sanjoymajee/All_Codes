class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row=0,col=0,cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<int>r(n);
        for(int i=0;i<n;i++){
            cnt=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)cnt++;
            }
            if(cnt>=2)row+=cnt,r[i]=1;
            cnt=0;
        }
        // cout<<row;
        int cnt2=0;
        for(int j=0;j<m;j++){
            cnt=0;
            cnt2=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==1){
                    cnt++;
                    if(r[i])cnt2++;
                }
            }
            if(cnt>=2)col+=cnt-cnt2;
            cnt=0;
        }
        // cout<<col;
        return row+col;
    }
};