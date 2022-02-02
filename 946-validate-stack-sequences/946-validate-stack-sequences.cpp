class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        int j=0,i=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(pushed[i]);
            if(st.top()!=popped[j])continue;
            while(st.top()==popped[j] && j<n){
                st.pop();
                j++;
                if(st.empty())break;
            }
        }
        if(st.empty())return true;
        return false;
    }
};