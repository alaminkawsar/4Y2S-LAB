#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;
void solve()
{
    string s="CAEECAEEECCCBBBDDDAAAEEEECCCB$";
    map<char,int>cnt;
    for(int i=0;i<s.length();i++){
        cnt[s[i]]++;
    }
    int n = s.length();
    ofstream out("out.txt");

    for(auto it: cnt){
        char ch = it.first;
        double prob = (1.00*it.second)/(1.00*n);
        out<<ch <<" "<<prob<<endl;
    }
    
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t=1,ts=0; // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
