#include<bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define mp make_pair
#define pii pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define read(a) scanf("%d",&a)
#define p1(a) cout<<"Check "<<a<<endl
#define p2(a,b) cout<<"Check "<<a<<' '<<b<<endl
#define fo(i,n) for (i=0;i<n;i++)
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define MOD 1000000007

using namespace std;
int const sz=(int)2e5+5;

class LZW_Compression{
    private:
        string input;
    public:
    map<string,int>dict;

    LZW_Compression(string list){
        this->input=list;
        init();
    }
    void init(){
        for(int ascii=0;ascii<255;ascii++){
            char ch = char(ascii);
            string s;
            s+=ch;
            //printf("%c %d\n",ch,ascii);
            dict[s]=ascii;
        }
        // for(auto it:dict){
        //     cout<<it.first<<' '<<it.second<<endl;
        // }
    }

    void encode(){
        int newVal = 256;
        string s;
        s+=input[0];
        for(int j=1;j<input.size();j++){
            char c = input[j];
            string str;
            str+=s;
            str+=c;
            if(dict.count(str)){
                s+=c;
            }else{
                cout<<dict[s]<<" ";
                dict[str]=newVal++;
                s=c;
            }
        }
        cout<<dict[s]<<endl;
    }
};

void solve()
{
    string line;
    string lines;

    while(getline(cin,line)){
        // cout<<line<<endl;
        if(lines.size()==0){
            lines=line;
            continue;
        }
        lines+="\n"+line;
        // cout<<line<<endl;
    }

    LZW_Compression LZW_Compression(lines);
    LZW_Compression.encode();


    
}
int main()
{
    freopen("/home/kawsar/Desktop/Class_Resource/4th year 2nd Semester/Multimedia/Multimedia-Lab/Experiment2-LZW/file/input.txt","r",stdin);
    freopen("/home/kawsar/Desktop/Class_Resource/4th year 2nd Semester/Multimedia/Multimedia-Lab/Experiment2-LZW/file/encoded.txt","w",stdout);
    int t=1,ts=0; //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
