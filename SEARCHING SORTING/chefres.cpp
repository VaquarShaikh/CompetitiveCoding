
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.first < p2.first;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> v;
        for(int i = 0;i < n;i++){
            int temp1,temp2;
            cin>>temp1>>temp2;
            v.push_back(make_pair(temp1,temp2));
        }
        sort(v.begin(),v.end(),compare);
        while(m--){
            int curr_time;
            cin>>curr_time;
            int position = lower_bound(v.begin(),v.end(),make_pair(curr_time,0)) - v.begin();
            if(position == 0){
                int ans = v[0].first - curr_time;
                cout<<ans<<endl;
            }else{
                int ans = -1;
                if(v[position - 1].second > curr_time){
                    ans = 0;
                }else if(position < v.size()){
                    ans = v[position].first - curr_time;
                }
                cout<<ans<<endl;
            }
        }
    }
}
