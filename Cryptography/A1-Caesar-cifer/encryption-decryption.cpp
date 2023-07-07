#include<bits/stdc++.h>
#define MAX 100005

using namespace std;
int const sz=(int)2e5+5;

void solve()
{
    string s="ABCabcZz"; //cin>>s;
    string encrypted,decrypted;
    
    int siz = s.size();

    // Encryption process
    char ch='a';
    for(int i=0;i<siz;i++){
        if(s[i]>='a') ch='a';
        else ch = 'A';
        encrypted+=(s[i]-ch+3)%26+ch;
    }

    // Decryptiong Process
    for(int i=0;i<siz;i++){
        if(encrypted[i]>='a') ch='a';
        else ch='A';
        decrypted+=(encrypted[i]-ch-3+26)%26+ch;
    }

    // Showing output
    printf("Main Message: ");
    cout<<s<<endl;

    printf("Encrypted Message: ");
    cout<<encrypted<<endl;

    printf("Decrypted Message: ");
    cout<<decrypted<<endl;




    
    
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,ts=0; //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
