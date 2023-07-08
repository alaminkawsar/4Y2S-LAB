#include<bits/stdc++.h>
#define ll long long

using namespace std;


ll power(long long x, unsigned int y, ll p)
{
    int res = 1;     
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
bool isPrime(ll n, ll iteration){
    ll e = (n-1)/2;
    for(int i=0;i<iteration;i++){
        ll a = 2+(ll)rand()%(n-2);
        ll x =(ll) power(a,e,n)%n;
        //cout<<a <<' '<<x<<endl;
        if(x==1 or x==n-1){
            continue;
        }
        return false;
    }
    return true;
}

int main(){
    ll n=10665,iteration=10; 
    printf("Input a number:\n");
    cin>>n;
    printf("Input number of iteration\n");
    cin>>iteration;

    if(n%2==0){
        printf("%lld must not be prime number\n",n);
        return 0;
    }

    bool flag = isPrime(n,iteration);
    if(flag){
        printf("%lld may be prime number\n",n);
    }else printf("%lld must not be prime number\n",n);

}