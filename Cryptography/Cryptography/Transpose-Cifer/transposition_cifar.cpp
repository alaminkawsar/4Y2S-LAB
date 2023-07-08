#include<bits/stdc++.h>
using namespace std;

void PRINT(string s,int width){
    for(int i=0;i<s.size();i++){
        if(i%width==0) printf("\n");
        printf("%c ",s[i]);
    }
    cout<<endl;
    cout<<endl;
}
string get_transpose(string s,int widht){
    string ans;
    vector<int>vis(s.size(),false);
    for(int i=0;i<widht;i++){
        for(int j=i;j<s.size();j+=widht){
            ans+=s[j];
        }
    }
    return ans;
}
int main(){
    freopen("transpose.txt","r",stdin);
    vector<string>vec;
    string s;
    getline(cin,s);
    printf("Real Message:\n");
    cout<<s<<endl;
  
    int width = 6;
    PRINT(s,width);

    // Ecryption Prcess
    printf("\n\nTranspose Matrix:");
    string cifer = get_transpose(s,width);
    PRINT(cifer,width);

    printf("\nTranspose Cifer Message:\n");
    cout<<cifer<<endl;
    printf("\n");

    // Decryption Process
    width=s.size()/width+(s.size()%width>0);
    string decrypted = get_transpose(cifer,width);
    PRINT(decrypted,width);
    printf("Decrypted Message: \n");
    cout<<decrypted<<endl;

    return 0;
}