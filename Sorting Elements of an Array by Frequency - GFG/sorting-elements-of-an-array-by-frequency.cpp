#include <bits/stdc++.h>
using namespace std;

map<int,int>m;

bool comp(int a,int b){
    if(m[a]==m[b])return a<b;
    return m[a]>m[b];
}

void solve(){
    int n;
    cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++)cin>>A[i];
    m.clear();
    for(auto a:A)m[a]++;
    sort(A.begin(),A.end(),comp);
    for(auto a:A)cout<<a<<" ";
    cout<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}