#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("cifar.txt","r",stdin);

    //Make Capital Letter Small Letter and Digit
    string capLetter,smallLetter,digit;

    // Encrypted, Message , Decrypeted
    string message,encrypted;
    int shift;
    string decrypted;


    for(int i=0;i<26;i++){
        capLetter+=i+'A';
        smallLetter+=i+'a';
    }
    for(int i=0;i<10;i++){
        digit+=i+'0';
    }
    
    printf("Input Message:\n");
    getline(cin,message);

    printf("Input Shift:\n");
    cin>>shift;
    
    // Message Encryption
    int n = message.size();
    for(int i=0;i<n;i++){
        int key;
        if(message[i]>='a' and message[i]<='z'){
            key=message[i]-'a';
            encrypted+=smallLetter[(key+shift)%26];
        }
        else if(message[i]>='A' and message[i]<='Z'){
            key=message[i]-'A';
            encrypted+=capLetter[(key+shift)%26];
        }
        else if(message[i]>='0' and message[i]<='9'){
            key=message[i]-'0';
            encrypted+=digit[(key+shift+10)%10];

        }
        else encrypted+=message[i];
    }
    cout<<endl;
    printf("Encrypted Message:\n");
    cout<<encrypted<<endl;
    cout<<endl;

    // Message Decryption
    for(int i=0;i<n;i++){
        int key;
        if(encrypted[i]>='a' and encrypted[i]<='z'){
            key=encrypted[i]-'a';
            decrypted+=smallLetter[(key-shift+26)%26];
        }
        else if(message[i]>='A' and message[i]<='Z'){
            key = encrypted[i]-'A';
            decrypted+=capLetter[(key-shift+26)%26];
        }
        else if(message[i]>='0' and message[i]<='9'){
            key = encrypted[i]-'0';
            decrypted+=digit[(key-shift+10)%10];
        }else decrypted+=encrypted[i];
    }
    printf("Decrypted Message:\n");
    cout<<decrypted<<endl;
    cout<<endl;

}
