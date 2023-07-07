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

class LZW_Decompression{
    private:
        vector<vector<int>>numberList;
    public:
    map<int,string>dict;

    LZW_Decompression(vector<vector<int>>list){
        this->numberList=list;
        init();
    }
    void init(){
        for(int ascii=0;ascii<255;ascii++){
            char ch = char(ascii);
            string s;
            s+=ch;
            //printf("%c %d\n",ch,ascii);
            dict[ascii]=s;
        }
        // for(auto it:dict){
        //     cout<<it.first<<' '<<it.second<<endl;
        // }
    }
    
    void decode(){
        int newVal = 256;
        string s;
        // cout<<numberList.size()<<endl;
        for(int i=0;i<numberList.size();i++){
            vector<int>vec=numberList[i];
            for(auto k: vec){
                string entry;
                entry=dict[k];
                if(entry.size()==0){
                    cout<<".........HI......."<<endl;
                    entry=s+s[0];
                }
                cout<<entry;
                if(s.size()>0){
                    dict[newVal++]=s+entry[0];
                }
                s=entry;
            }
            printf("\n");
        }
    }
    
};

void solve()
{
    vector<int> line;
    vector<vector<int>>lines;
    int num;

    while(cin>>num){
        line.push_back(num);
        if(cin.peek()=='\n'){
            lines.push_back(line);
            line.clear();
        }
    }

    LZW_Decompression LZW_Decompression(lines);
    LZW_Decompression.decode();


    
}
int main()
{
    freopen("/home/kawsar/Desktop/Class_Resource/4th year 2nd Semester/Multimedia/Multimedia-Lab/Experiment2-LZW/file/encoded.txt","r",stdin);
    freopen("/home/kawsar/Desktop/Class_Resource/4th year 2nd Semester/Multimedia/Multimedia-Lab/Experiment2-LZW/file/decoded.txt","w",stdout);
    int t=1,ts=0; //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
