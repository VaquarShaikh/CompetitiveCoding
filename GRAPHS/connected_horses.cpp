#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(long long int i=k;i<=n;++i)
#define endl '\n'
#define tezz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
ll fac(ll t) {
	ll ans=1;
	for(ll i=1;i<=t;i++)ans=(ans*i)%MOD;
		return ans;
}
int dfs(vector<int>* edges,bool* visited,int start,int q){
	visited[start] = true;
	int ans = 1;
	ll len = edges[start].size();
	for(ll i = 0;i<len;i++){
		ll adjv = edges[start][i];
		if(!visited[adjv]){
			ans+= dfs(edges,visited,adjv,q);
		}
	}

	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,q;
		cin>>n>>m>>q;
		vector<pair<int,int>> horses;
		fo(i,0,q-1) {
			int x,y;
			cin>>x>>y;
			horses.push_back(make_pair(x,y));
		}
		sort(horses.begin(),horses.end());
		// cout<<endl;
		// for(int i = 0;i < horses.size();i++){
		// 	cout<<horses[i].first<<" "<<horses[i].second<<endl;
		// }
		vector<int>* edges = new vector<int>[q];
		fo(i,0,q-2){
			fo(j,i+1,q-1){
				int difx,dify;
				difx = abs(horses[i].first-horses[j].first);
				dify = abs(horses[i].second-horses[j].second);
				if(difx>2) break;
				if((difx==1&&dify==2)||(difx==2&&dify==1)){
					edges[i].push_back(j);
					edges[j].push_back(i);
				}
			}
		}
		ll ans = 1;
		bool* visited = new bool[q];
		fo(i,0,q-1) visited[i] = false;
		fo(i,0,q-1){
			if(!visited[i]){
				ll c = dfs(edges,visited,i,q);
				ans = (ans*fac(c))%MOD;
			}
		}
		delete []visited;
		delete []edges;
		cout<<ans<<endl;
	}
	return 0;
}
/*2
4 4 4
3 1
1 1
1 2
3 2
4 4 4
1 1
1 2
3 1
4 4
*/