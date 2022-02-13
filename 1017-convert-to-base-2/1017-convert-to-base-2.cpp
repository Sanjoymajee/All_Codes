class Solution {
public:
    string baseNeg2(int n) {
        if(n==0)return "0";
        int b=-2;
        string ans="";
        int c;
        while(n){
            c=n%b;
            n/=b;
            if(c<0){
                c+=2;
                n++;
            }
            ans+=c+'0';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};