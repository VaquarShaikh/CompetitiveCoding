#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef long long ll;



ll findpar(ll v,ll* parent){
    if(parent[v] == v){
        return v;
    }
    return findpar(parent[v] , parent);
}

bool compare(pair<ll,pair<ll,ll>> a,pair<ll,pair<ll,ll>> b){
    return a.second.second < b.second.second;
}

int main(){
    int t;
    cin>>t;
    for(int cc = 0;cc < t;cc++){

        ll n,m,air_cost;
        ll arr[100010];
        cin>>n>>m>>air_cost;
        pair<ll,pair<ll,ll>> p[10010];

        for(ll i = 0;i < m;i++){
            ll x,y,cost;
            cin>>x>>y>>cost;
            p[i].first = x;p[i].second.first = y;p[i].second.second = cost;
        }
        sort(p,p+m,compare);
        // for(int i = 0;i < n;i++){
        // cout<<p[i].first<<" "<<p[i].second.first<<" "<<p[i].second.second<<endl;
        // }cout<<endl<<endl;
        for(ll i = 0;i <= n;i++){
            arr[i] = i;
        }
        ll sum = 0;
        for(ll i = 0;i < m;i++){
            if(p[i].second.second < air_cost){
                ll a = findpar(p[i].first,arr);
                ll b = findpar(p[i].second.first,arr);

                if(a != b){
                    sum += p[i].second.second;
                    arr[a] = b;
                }
            }
            else if(p[i].second.second > air_cost){
                break;
            }
        }
        int count = 0;
        // sort(arr,arr+n);

        for(int i= 1; i<=n ; i++)
        {
            if(arr[i] == i)
            {
                count++;
            }
        }
        // for(ll i = 0;i < )
        // cout<<sum<<endl;	
        ll res = count*air_cost + sum;
        // // cout<<res<<endl;
        // cout<<res<<" "<<sum<<" "<<count<<endl;
        cout<<"Case #"<<cc+1<<": "<<res<<" "<<count;
        cout<<endl;
    }
}