#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("one.txt","r",stdin);
    FILE *fptr;

    string KEY = "ABC123abc";
    string message = "ABxyZ 5";

    fptr = fopen("key.txt","r");
    if(fptr == NULL){
        printf("Error!");
        exit(1);
    }
    cin>>KEY;
    fclose(fptr);

    fptr = fopen("value.txt","r");
    if(fptr == NULL){
        printf("Error!");
        exit(1);
    }
    cin>>message;
    fclose(fptr);


    string ENCRYPTED;
    string decrypted;

    int sz = message.size();
    for(int i=0;i<sz;i++){

        ENCRYPTED+=(message[i]+KEY[i])%256;
        //cout<<(message[i]+KEY[i])%256<<endl;
    }
    
    cout<<"Encryption Message: "<<ENCRYPTED<<endl;

    for(int i=0;i<sz;i++){
        decrypted+=(ENCRYPTED[i]-KEY[i]+256)%256;
        //cout<<(ENCRYPTED[i]-KEY[i]+256)%256<<endl;
    }
    cout<<"Decrypted Message: "<<decrypted<<endl;
    cout<<endl;
}