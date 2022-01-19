// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    
    bool same(map<char,int>m){
        auto it=m.begin();
        int s=(*it).second;
        it++;
        for(it;it!=m.end();it++){
            if((*it).second!=s && (*it).second>0)return false;
        }
        return true;
    }
    
    void print(map<char,int>m){
        for(auto a:m)cout<<a.second<<" ";
        cout<<endl;
    }
    
	bool sameFreq(string s)
	{
	    int n=s.size();
	    map<char,int>m;
	    for(auto a:s){
	        m[a]++;
	    }
	    if(same(m))return true;
	    for(auto a:m){
	        m[a.first]--;
	        if(same(m))return true;
	        m[a.first]++;
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}


  // } Driver Code Ends