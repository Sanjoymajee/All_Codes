class Solution {
public:  
    int help(int n,int k,int l){
        if(n==1)return 0;
        if(k>(l/2))return !help(n-1,k-l/2,l/2);
        else return help(n-1,k,l/2);
    }
    
    int kthGrammar(int n, int k) {
        int l=(1<<(n-1));
        return help(n,k,l);
    }
};