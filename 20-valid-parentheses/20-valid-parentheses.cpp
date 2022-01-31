class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char,char>m;
        m['(']=')';
        m['{']='}';
        m['[']=']';
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty())return false;
                if(m[st.top()]==s[i])st.pop();
                else return false;
            }
        }
        if(st.empty())return true;
        return false;
    }
};