#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define pb push_back

pair<ll,pair<ll,ll>> query[1000010];
vector<ll> gp[100010];
ll color[100010];
map<ll,map<ll,ll>> m;

ll n,q;

bool bipartite(ll src){
    color[src] = 1;
    queue<ll> q;
    q.push(src);

    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(ll v = 0;v < gp[u].size();++v){
            ll vv = gp[u][v];
            ll c = m[u][vv];
            //if not in any of the sets.
            if(color[vv] == -1){
                if(c == 0){
                    color[vv] = color[u];
                }
                else{
                    color[vv] = 1 - color[u];   
                }
                q.push(gp[u][v]);
            }else if(abs(color[gp[u][v]] - color[u]) != c){
            	//if it exists but in the same set.
                return false;   
            }
        }
    }
    return true;
}

bool isbipartite(){
    for(ll i = 0;i <= n;++i){
        color[i] = -1;
    }
    for(ll i = 1;i <= n;i++){
        if(color[i] == -1 && gp[i].size() >= 1){
            if(bipartite(i) == false){
                return false;      
            }
        }   
    }
    return true;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll i = 0;
        m.clear();
        bool ans = true;
        cin>>n>>q;

        for(ll j = 0;j <= n;j++){
            gp[j].clear();
        }

        while(i < q){
            ll a,b,c;
            cin>>a>>b>>c;

            query[i].first = a;
            query[i].second.first = b;
            query[i].second.second = c;
            
            gp[a].pb(b);
            gp[b].pb(a);
            if(m.find(a) != m.end() && m[a].find(b) != m[a].end()){
                ll tt = m[a][b];
                if(tt != c){
                    ans = false;      
                }
                // break;
            }else if(m.find(b) != m.end() && m[b].find(a) != m[b].end()){
                ll tt = m[b][a];
                if(tt != c){
                    ans = false;
                }

                // break;
            }else{
                m[a][b] = m[b][a] = c;
            }
            i++;
        }

        if(ans == false){
            cout<<"no\n";
            continue;
        }
        ans = isbipartite();
        if(ans == false){
            cout<<"no\n";
        }else{
            cout<<"yes\n";
        }
    }
}