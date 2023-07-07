#include<bits/stdc++.h>
#define MAX 100005

using namespace std;
int const sz=(int)2e5+5;

char mat[200][200];

string Encryption(string s,int w){

    string encrypted;
    int len = s.length();
    int row=0,col=0;

    for(int i=0;i<len;i++){
        mat[row][col++]=s[i];
        if(col>=w){
            row++;
            col=0;
        }
    }
    // for(int i=0;i<=row;i++){
    //     for(int j=0;j<w;j++){
    //         printf("%c",mat[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int i=0;i<w;i++){
        for(int j=0;j<=row;j++){
            if(mat[j][i]==0) continue;
            encrypted+=mat[j][i];
        }
    }
    return encrypted;
}

string Decryption(string s,int w){
    string decrypted;
    int len = s.length();
    int row = len+(len%w>0);
    int k=0;

    for(int i=0;i<w;i++){
        for(int j=0;j<row;j++){
            if(mat[j][i]==0) continue;
            mat[j][i]=s[k++];
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<w;j++){
            //printf("%c",mat[i][j]);
            decrypted+=mat[i][j];
        }
        //printf("\n");
    }

    return decrypted;
}

void solve()
{
    cout<<endl;
    string s; getline(cin,s);
    string encrypted, decrypted;
    int width = 4; // cin>>width;
    int Iteration=5; //cin>>Iteration

    // taking input
    cout<<s<<endl;

    memset(mat,0,sizeof(mat));

    // Encryption Process number of Iteration times
    encrypted=s;
    for(int i=0;i<Iteration;i++){
        encrypted = Encryption(encrypted,width);
    }

    // Decryption Process number of Iteration time
    decrypted=encrypted;
    for(int i=0;i<Iteration;i++){
        decrypted = Decryption(decrypted, width);

    }

    printf("\nMain Message: ");
    cout<<s<<endl;

    printf("\nEncrypted Message: ");
    cout<<encrypted<<endl;

    printf("\nDecrypted Messge: ");
    cout<<decrypted<<endl;


    
}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,ts=0; //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
