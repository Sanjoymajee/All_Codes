class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({s[i],1});
            }
            else if(st.top().first == s[i]){
                int inc=st.top().second+1;
                st.push({s[i],inc});
                if(inc==k){
                    while(inc--)st.pop();
                }
            }
            else{
                st.push({s[i],1});
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};