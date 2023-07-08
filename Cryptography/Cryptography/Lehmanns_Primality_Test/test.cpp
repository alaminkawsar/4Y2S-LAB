#include<bits/stdc++.h>

using namespace std;
#define ll long long
int main(){
    ll n = (int) 1e9;
    vector<ll>v;
    for(ll i=n;i<=n+100;i++){
        bool flag=true;
        for(ll j=2;j*j<=i;j++){
            if(i%j==0){
                flag=false;
                break;
            }
        }
        if(flag) v.push_back(i);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
}