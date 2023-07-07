#include<bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define mp make_pair
#define pii pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define read(a) scanf("%d",&a)
#define p1(a) cout<<"Check "<<a<<endl;
#define p2(a,b) cout<<"Check "<<a<<' '<<b<<endl;
#define fo(i,n) for (i=0;i<n;i++)
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define MOD 1000000007

using namespace std;
int const sz=(int)2e5+5;

struct encode
{
    /* data */
    char ch;
    double prob;
    double high;
    double low;
}data[sz];


void solve()
{
    // Taking input
    char ch;
    double prob,prev=0;
    int index=0;
    map<char,int>has;
    int newVal=0;
    while(cin>>ch>>prob){
        if(has.count(ch)==0) has[ch]=newVal++;
        data[has[ch]].ch = ch;
        data[has[ch]].prob=prob;
        data[has[ch]].low = prev;
        data[has[ch]].high= prev+prob;
        prev=prob+prev;
    }
    cout<<newVal<<endl;
    printf("Data Table:\n");
    printf("Symbols \tProbability \tHigh_Range \tLow_Range\n");
    for(int i=0;i<newVal;i++){
        printf("%c \t\t%.2lf \t\t%.2lf \t\t%.2lf\n",data[i].ch,data[i].prob,data[i].low,data[i].high);
    }

    // Encoding and produce code
    double low = 0.0, high = 1.0, range = 1.0;
    for(int i = 0;i<newVal;i++){
        char ch = data[i].ch;
        high = low + range*data[i].high;
        low = low + range*data[i].low;
        range = high-low;
        // printf("%0.2lf %0.2lf %0.2lf\n",low,high,range);
        // cout<<high<<' '<<low<<' '<<range<<endl;

    }
}
int main()
{
    freopen("table.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,ts=0; //cin>>t;
    while(t--){
        
        solve();
    }
    return 0;
}
