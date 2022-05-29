class Solution {
public:
    vector<int>ans;
    long long number(long long n){
        long long num=0;
        for(int i=1;i<=n;i++){
            num*=10;
            num+=i;
        }
        return num;
    }
    
    int sz(int n){
        int cnt=0;
        while(n){
            cnt++;
            n/=10;
        }
        return cnt;
    }
    
    void help(int n,int m,int low,int high){
        for(int i=n;i<=m;i++){
            // cout<<i<<",";
            long long num=number(i);
            // cout<<num<<endl;
            long long pos=0;
            int cnt=i;
            while(cnt--){
                pos*=10;
                pos+=1;
            }
            while(num%10>=n && num%10<=9){
                if(num>=low && num<=high)
                    ans.push_back(num);
                num+=pos;
            }
        }
    }
    
    vector<int> sequentialDigits(int low, int high) {
        int n=sz(low);
        int m=sz(high);
        help(n,m,low,high);
        return ans;
    }
};