// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        int n=s.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='+'){
                int temp1=st.top();
                st.pop();
                int temp2=st.top();
                st.pop();
                st.push(temp1+temp2);
            }
            else if(s[i]=='-'){
                int temp1=st.top();
                st.pop();
                int temp2=st.top();
                st.pop();
                st.push(temp2-temp1);
            }
            else if(s[i]=='*'){
                int temp1=st.top();
                st.pop();
                int temp2=st.top();
                st.pop();
                st.push(temp2*temp1);
            }
            else if(s[i]=='/'){
                int temp1=st.top();
                st.pop();
                int temp2=st.top();
                st.pop();
                st.push(temp2/temp1);
            }
            else st.push(s[i]-'0');
        }
        return st.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends