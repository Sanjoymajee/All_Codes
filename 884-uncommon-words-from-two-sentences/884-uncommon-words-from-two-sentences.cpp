class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>m1;
        string s="";
        for(auto c:s1){
            if(c==' '){
                m1[s]++;
                s="";
                continue;
            }
            s+=c;
        }
        m1[s]++;
        s="";
        for(auto c:s2){
            if(c==' '){
                m1[s]++;
                s="";
                continue;
            }
            s+=c;
        }
        m1[s]++;
        vector<string>ans;
        for(auto a:m1)if(a.second==1)ans.push_back(a.first);
        return ans;
    }
};