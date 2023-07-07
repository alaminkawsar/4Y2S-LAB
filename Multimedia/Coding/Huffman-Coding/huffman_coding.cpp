#include<bits/stdc++.h>
#define pi pair<int,int>

using namespace std;

 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



int main(){

    string str = "BCAADDDCCACACAC";
    int len = str.size();

    map<char,int>has;

    for(int i=0;i<len;i++){
        has[str[i]]++;
    }

    priority_queue<pi, vector<pi>, greater<pi> > pq;

    for(auto it: has){
        pq.push({it.second,it.first});
    }
    while(!pq.empty()){
        auto it = pq.top(); pq.pop();
        printf("%c %d\n",it.second,it.first);
    }
    

    return 0;
}