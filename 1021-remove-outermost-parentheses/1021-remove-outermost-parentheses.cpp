class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(st.empty())s[i]='#';
                st.push(s[i]);
            }
            else{
                st.pop();
                if(st.empty())s[i]='#';
            }
        }
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]!='#')ans.push_back(s[i]);
        }
        return ans;
    }
};