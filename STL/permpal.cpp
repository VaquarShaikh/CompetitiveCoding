#include<bits/stdc++.h>
using namespace std;

char getchar(int i){
    return (char)(i+97);
}

void printpal(string s){
    map<char,vector<int>> mapp;
    for(int i = 0;i < s.length();i++){
        mapp[s[i]].push_back(i);
    }
    int odd_freq_count = 0;
    for(int i = 0;i < 26;i++){
        char currchar = getchar(i);
        if((mapp[currchar].size() % 2) != 0){
            odd_freq_count++;
        }
    }
    if(odd_freq_count >= 2){
        cout<<"-1";
        return;
    }
    int ans[s.length()];
    int start = 0;
    int end = s.length() - 1;
    for(int i = 0;i < 26;i++){
        char currchar = getchar(i);
        for(int j = 0;j < mapp[currchar].size();j+=2){
            if((mapp[currchar].size() - j) == 1){
                ans[s.length()/2]  = mapp[getchar(i)][j];
                continue;
            }
            ans[start] = mapp[currchar][j];
            ans[end] = mapp[currchar][j+1];
            start++;
            end--;
        }
    }
    for(int i = 0;i < s.length();i++){
        cout<<ans[i]+1<<" ";
    }
    //cout<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        printpal(s);
        cout<<endl;
    }
}











