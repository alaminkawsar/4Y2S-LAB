#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll getRandom(ll min, ll max) {
    return min + ((ll)rand() % (max - min + 1));
}

bool robinMillerTest(ll n){
    for(int i=0;i<5;i++)
        cout<<getRandom(1,100)<<endl;
    
    return true;
}

int main(){
    bool flag = robinMillerTest(97);
}