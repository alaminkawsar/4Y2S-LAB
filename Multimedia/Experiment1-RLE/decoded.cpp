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

class Decoder
{
private:
    vector<string> lines;
public:
    vector<string> DecodedLine;
    Decoder(vector<string> lines){
        this->lines = lines;
    }
    vector<string> getDecodedText(){
        for(int i=0;i<lines.size();i++){
            string res;
            string encoded = lines[i];
            if(encoded.size()<=1){
                DecodedLine.push_back("\n");
                continue;
            }
            for(int i=0;i<encoded.size();i++){
                if(i%2==0){
                    res+=encoded[i];
                    continue;
                }
                for(int j=1;j<encoded[i];j++){
                    res+=encoded[i-1];
                }
            }
            DecodedLine.push_back(res);
        }
        return this->DecodedLine;
    }

};


int main()
{
    freopen("encoded.txt","r",stdin);
    freopen("decoded.txt","w",stdout);
    string line;
    vector<string>lines;
    while(getline(cin,line)){
        lines.push_back(line);
    }
    Decoder dec(lines);
    
    vector<string>DecoderdText=dec.getDecodedText();
    for(int i=0;i<DecoderdText.size();i++){
        cout<<DecoderdText[i]<<endl;
    }

    // print Decoderd text


    return 0;
}
