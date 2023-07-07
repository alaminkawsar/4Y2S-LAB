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

class Encoder
{
private:
    vector<string> lines;
public:
    vector<string> encodedLine;
    Encoder(vector<string> lines){
        this->lines = lines;
    }
    vector<string> encode(){
        for(int i=0;i<lines.size();i++){
            int occur=1;
            string line = lines[i];
            string encoded;
            encoded+=line[0];
            for(int i=1;i<line.size();i++){
                if(line[i]==line[i-1]) occur++;
                else{
                    encoded+=occur;
                    occur=1;
                    encoded+=line[i];
                }
            }
            // don't make occurence if just only one character have
            encoded+=occur;
            encodedLine.push_back(encoded);
        }
        return this->encodedLine;
    }

};


int main()
{
    freopen("input.txt","r",stdin);
    freopen("encoded.txt","w",stdout);
    string line;
    vector<string>lines;
    while(getline(cin,line)){
        lines.push_back(line);
    }
    Encoder encoder(lines);
    
    vector<string>encodedText=encoder.encode();
    for(int i=0;i<encodedText.size();i++){
        cout<<encodedText[i]<<endl;
    }

    // print encoded text


    return 0;
}
