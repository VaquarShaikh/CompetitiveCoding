#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string,pair<int,int>> p1,pair<string,pair<int,int>> p2){
    if(p1.second.second == p2.second.second){
        return p1.second.first < p2.second.first;
    }else{
        return p1.second.second > p2.second.second;
    }
}


int main(){
    multimap<string,pair<int,int>> mapp;
    int n;
    cin>>n;
    for(int i = 0;i < n;i++){
        string s;
        int m1,m2,m3;
        cin>>s>>m1>>m2>>m3;
        int sum = 0;
        sum = m1 + m2 + m3;
        pair<int,int> p(i,sum);
        mapp.insert(make_pair(s,p));
    }
    vector<pair<string,pair<int,int>>> v;
    multimap<string,pair<int,int>>::iterator it;
    for(it = mapp.begin();it != mapp.end();it++){
        v.push_back(make_pair(it->first,it->second));
    }
    sort(v.begin(),v.end(),compare);
    for(int i = 0;i < v.size();i++){
        cout<<i+1<<" "<<v[i].first<<endl;
    }
}
