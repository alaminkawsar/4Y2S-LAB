#include<bits/stdc++.h>
using namespace std;


string decode(string encoded){
    string res;
    if(encoded.size()==1) return "";
    for(int i=0;i<encoded.size();i++){
        if(i%2==0){
            res+=encoded[i];
            continue;
        }
        for(int j=1;j<encoded[i];j++){
            res+=encoded[i-1];
        }
    }
    return res;
}


// Decode
string encode(string digit){
    string result;
    //printf("%c",digit[0]);
    if(digit.size()==0){
        result+=digit.size();
        return result;
    }
    int cnt=1;
    result+=digit[0];

    for(int i=1;i<digit.size();i++){
        if(digit[i]==digit[i-1]){
            cnt++;
        }else{
            result+=cnt;
            result+=digit[i];
            cnt=1;
        }
    }
    result+=cnt;

    return result;
}

int main(){

    freopen("input.txt","r",stdin);
    //freopen("encoded.txt","w",stdout);
    freopen("decoded.txt","w,",stdout);
    string s;
    vector<string>vec;

    while(getline(cin,s)){
        vec.push_back(s);
    }
    vector<string>encoded;
    vector<string>decoded;

    // Encode
    for(int i=0;i<vec.size();i++){
        string res = encode(vec[i]);
        encoded.push_back(res);
        decoded.push_back(decode(res));
    }
    for(int i=0;i<encoded.size();i++){
        //cout<<encoded[i]<<endl;
    }
    for(int i=0;i<decoded.size();i++){
        cout<<decoded[i]<<endl;
    }
    
    
    return 0;
}