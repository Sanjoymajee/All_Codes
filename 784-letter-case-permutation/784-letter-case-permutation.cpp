class Solution {
public:
    vector<string>ans;
    
    bool isDigit(char c){
        if(c>='0' && c<='9')return true;
        return false;
    }
    
    void help(string &s,int n,int i){
        ans.push_back(s);
        for(int j=i;j<n;j++){
            if(isDigit(s[j])){
                continue;
            }
            s[j]=toupper(s[j]);
            help(s , n, j+1 );
            s[j]=tolower(s[j]);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        for(int i=0;i<s.size();i++){
            if(isDigit(s[i]))continue;
            s[i]=tolower(s[i]);
        }
        help(s,s.size(),0);
        return ans;
    }
};