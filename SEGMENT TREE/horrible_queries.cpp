#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

typedef long long ll;

void buildTree(ll* arr,ll* tree,ll s,ll e,ll tn){
	if(s == e){
		tree[tn] = arr[s];
		return;
	}

	ll mid = (s + e)/2;
	buildTree(arr,tree,s,mid,2*tn);
	buildTree(arr,tree,mid+1,e,2*tn+1);

	tree[tn] = tree[2*tn] + tree[2*tn+1];
}

void updatetree(ll* tree,ll* lazy,ll s,ll e,ll l,ll r,ll inc,ll tn){
	if(s > e){
		return;
	}
	if(lazy[tn] != 0){
		tree[tn] += lazy[tn]*(e-s+1);
		if(s != e){
			lazy[2*tn] += lazy[tn];
			lazy[2*tn + 1] += lazy[tn];
		}
		lazy[tn] = 0;
	}

	if(l > e || r < s){
		return;
	}
	if(s >= l && e <= r){
		tree[tn] += inc*(e-s+1);
		if(s != e){
			lazy[2*tn] += inc;
			lazy[2*tn+1] += inc; 
		}
		return;
	}

	ll mid = (s + e)/2;
	updatetree(tree,lazy,s,mid,l,r,inc,2*tn);
	updatetree(tree,lazy,mid+1,e,l,r,inc,2*tn+1);

	tree[tn] = tree[2*tn] + tree[2*tn + 1];
}

ll query(ll* tree,ll* lazy,ll s,ll e,ll l,ll r,ll tn){
	if(s > e){
		return 0;
	}
	if(lazy[tn] != 0){
		tree[tn] += lazy[tn]*(e-s+1);
		if(s != e){
			lazy[2*tn] += lazy[tn];
			lazy[2*tn + 1] += lazy[tn];
		}
		lazy[tn] = 0;
	}

	if(l > e || r < s){
		return 0;
	}
	if(s >= l && e <= r){
		return tree[tn];
	}

	ll mid = (s+e)/2;

	ll a1 = query(tree,lazy,s,mid,l,r,2*tn);
	ll a2 = query(tree,lazy,mid+1,e,l,r,2*tn+1);

	return a1 + a2;
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,c;
		cin>>n>>c;
		ll arr[n] = {0};
		ll* tree = new ll[4*n]();
		buildTree(arr,tree,0,n-1,1);
		ll* lazy = new ll[4*n]();
		while(c--){
			ll type;
			cin>>type;
			if(type == 0){
				ll x,y;
				ll inc;
				cin>>x>>y>>inc;
				updatetree(tree,lazy,0,n-1,x-1,y-1,inc,1);
			}else if(type == 1){
				ll x,y;
				cin>>x>>y;
				cout<<query(tree,lazy,0,n-1,x-1,y-1,1)<<endl;
			}
		}
	}	
}