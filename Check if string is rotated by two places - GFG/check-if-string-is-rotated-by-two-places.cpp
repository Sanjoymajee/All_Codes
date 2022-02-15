// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    void leftrotate(string &s, int d)
    {
        reverse(s.begin(), s.begin()+d);
        reverse(s.begin()+d, s.end());
        reverse(s.begin(), s.end());
    }
    
    void rightrotate(string &s, int d)
    {
       leftrotate(s, s.length()-d);
    }
    
    bool isRotated(string str1, string str2)
    {
        leftrotate(str1,2);
        if(str1==str2)return true;
        rightrotate(str1,4);
        if(str1==str2)return true;
        return false;
    }

};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends