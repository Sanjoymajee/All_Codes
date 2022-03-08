class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        stack<int>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                ans+=s[i];
                st.push(i);
            }
            else if(s[i]==')'){
                ans+=s[i];
                reverse(ans.begin()+st.top(),ans.begin()+i);
                st.pop();
            }
            else{
                ans+=s[i];
            }
        }
        s=ans;
        ans="";
        for(auto c:s){
            if(c=='(' || c==')')continue;
            ans+=c;
        }
        return ans;
    }
};