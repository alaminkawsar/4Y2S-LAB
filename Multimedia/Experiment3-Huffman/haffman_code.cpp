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

vector<int>adj[sz];

void solve()
{
    string s = "HELLO";
    getline(cin,s);
    map<int,int>has;

    for(int i=0;i<s.size();i++) has[int(s[i])]++;
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    for(auto it:has){
        pq.push({it.second,it.first});
    }
    int node = 256;
    while(pq.size()!=1){
        auto u = pq.top(); pq.pop();
        //cout<<u.first<<' '<<u.second<<endl;
        auto v = pq.top(); pq.pop();
        adj[node].push_back(u.second);
        adj[node].push_back(v.second);
        pq.push({u.first+v.first,node});
        node++;
    }
    queue<int>q;
    q.push(node-1);

    map<int,string>code;

    while(!q.empty()){
        int u = q.front(); q.pop();
        //cout<<u<<": ";
        if(adj[u].size()>1){
            int left = adj[u][0];
            int right = adj[u][1];
            if(adj[right].size()>1){
                code[right]+=code[u]+"1";
                code[left]+=code[u]+"0";
            }else if(adj[left].size()>1){
                code[right]+=code[u]+"0";
                code[left]+=code[u]+"1";
            }else {
                code[right]+=code[u]+"1";
                code[left]+=code[u]+"0";
            }
            
            q.push(adj[u][0]);
            q.push(adj[u][1]);
        }
        //cout<<endl;
    }
    for(auto it: code){
        if(it.first>255) continue;
        //printf("%c=%s\n",it.first,it.second.c_str());
        string res;
        res+=it.first;
        res+=int(':');
        res+=it.second;
        cout<<res<<endl;
    }
    cout<<endl;

    // Hello er output
    for(int i=0;i<s.size();i++){
        string cd = code[int(s[i])];
        cout<<cd<<' ';
    }

    
}
int main()
{
    freopen("./input.txt","r",stdin);
    freopen("./encoded.txt","w",stdout);
    int t=1,ts=0; //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
