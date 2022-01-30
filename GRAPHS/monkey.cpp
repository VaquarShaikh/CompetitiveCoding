#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef long long ll;
#define pb push_back
#define mk make_pair

vector<ll> gp[10010];
unordered_map<ll,ll> mapp;

void dfs(vector<ll>* edges,ll start,unordered_set<ll>* component,bool* visited){
	visited[start] = true;
	component->insert(start);

	for(ll i = 0;i < edges[start].size();i++){
		ll next = edges[start][i];
		if(!visited[next]){
			dfs(edges,next,component,visited);
		}
	}
	// delete [] visited;
}

unordered_set<unordered_set<ll>*>* getcomponents(vector<ll>* edges,ll n){
	bool* visited = new bool[n];
	for(ll i = 0;i < n;i++){
		visited[i] = false;
	}
	unordered_set<unordered_set<ll>*>* output = new unordered_set<unordered_set<ll>*>();
	for(ll i = 0;i < n;i++){
		if(!visited[i]){
			unordered_set<ll>* component = new unordered_set<ll>();
			dfs(edges,i,component,visited);
			output->insert(component);
		}
	}
	delete [] visited;
	return output;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		mapp.clear();
		cin>>n>>m;
		for(int i = 0;i < n;i++){
			gp[i].clear();
			// array[i].clear();
		}

		while(m--){
			int x,y;
			cin>>x>>y;

			gp[x-1].pb(y-1);
			gp[y-1].pb(x-1);
		}


		for(ll i = 0;i < n;i++){
			ll temp;
			cin>>temp;

			mapp.insert(mk(i,temp));
		}
		unordered_set<unordered_set<ll>*>* components = getcomponents(gp,n);
		unordered_set<unordered_set<ll>*>::iterator it1 = components->begin();
		ll res = LLONG_MIN;
		while(it1 != components->end()){
			unordered_set<ll>* component = *it1;
			unordered_set<ll>::iterator it2 = component->begin();
			ll sum = 0;
			while(it2 != component->end()){
				ll element = *it2;
				ll x = mapp[element];

				sum += x;

				it2++;
			}

			if(sum > res){
				res = sum;
			}
			delete component;
			it1++;
		}
		cout<<res<<endl;
	}
}