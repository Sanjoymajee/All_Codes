class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push({s[i],i});
            }
            else{
                if(!st.empty()){
                    s[i]='#';
                    s[st.top().second]='#';
                    st.pop();
                }
            }
        }
        // cout<<s;
        int ans=0;
        for(int i=0;i<s.size();i++)if(s[i]!='#')ans++;
        return ans;
    }
};