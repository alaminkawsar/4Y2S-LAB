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

map<string,string>encry_dict,decry_dict;

void solve()
{
    // input string
    string input = "STWXYZMNO";
    string encrypted, decrypted;

    ifstream dict("dictionary.txt");
    ofstream output;

    // making dictionary
    string line,key,val;
    while (getline(dict,line))
    {
        //cout << line << '\n';
        key = line.substr(0,3);
        val = line.substr(4,line.length());
        // cout<<key<<' '<<val<<endl;
        
        encry_dict[key]=val;
        decry_dict[val]=key;
    }

    // checking the dictionary
    // for(auto it: encry_dict){
    //     cout<<it.first<<' '<<it.second<<endl;
    // }

    //encryption
    for(int i=0;i<input.length();i+=3){
        encrypted+=encry_dict[input.substr(i,3)];
    }

    //decryption
    for(int i=0;i<input.length();i+=3){
        decrypted+=decry_dict[encrypted.substr(i,3)];
    }

    printf("\nInput Message: ");
    cout<<input<<endl;

    printf("Encryption Message: ");
    cout<<encrypted<<endl;

    printf("Output Message: ");
    cout<<decrypted<<endl;

    
    
    
}
int main()
{
    // take the dictionary
    //freopen("dictionary.txt","r",stdin);

    //freopen("output.txt","w",stdout);
    int t=1,ts=0; //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
