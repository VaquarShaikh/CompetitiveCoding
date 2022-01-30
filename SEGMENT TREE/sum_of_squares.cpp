#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

typedef long long ll;

struct Tree{
	ll ss;
	ll s;
};

struct Lazy
{	
	ll set;
	ll update;
};

void buildTree(ll* arr,Tree* tree,int s,int e,int tn){
	if(s == e){
		tree[tn].ss = arr[s-1]*arr[s-1];
		tree[tn].s = arr[s-1];
		return;
	}
	ll mid = (s + e)/2;

	buildTree(arr,tree,s,mid,2*tn);
	buildTree(arr,tree,mid+1,e,2*tn+1);

	Tree left = tree[2*tn];
	Tree right = tree[2*tn + 1];

	tree[tn].ss = left.ss + right.ss;
	tree[tn].s = left.s + right.s;
}

void updatetree(int s,int e,int l,int r,ll v,int type,int tn,Tree* tree,Lazy* lazy){
	if(s > e) return;
	if(lazy[tn].set != 0){
		ll x = lazy[tn].set;
		tree[tn].ss = x*x*(e-s+1); 
		tree[tn].s = x*(e-s+1);
		if(s != e){
			lazy[2*tn].set = x;
			lazy[2*tn].update = 0;
			lazy[2*tn+1].set = x;
			lazy[2*tn+1].update = 0; 
		}
		lazy[tn].set = 0;
	}if(lazy[tn].update != 0){
		ll x = lazy[tn].update;
		tree[tn].ss += x*x*(e-s+1) + 2*x*(tree[tn].s);
		tree[tn].s += x*(e-s+1);
		if(s != e){
			lazy[2*tn].update += x;
			lazy[2*tn + 1].update += x;
		}
		lazy[tn].update = 0;
	}
	//completely out.
	if(s > r || e < l){
		return;
	}

	//completely in range.

	if(s >= l && e <= r){
		if(type == 0){
			tree[tn].ss = v*v*(e-s+1); 
			tree[tn].s = v*(e-s+1);
			if(s != e){
				lazy[2*tn].set = v;
				lazy[2*tn].update = 0;
				lazy[2*tn+1].set = v;
				lazy[2*tn+1].update = 0;
			}
		}else{
			tree[tn].ss += v*v*(e-s+1) + 2*v*(tree[tn].s); 
			tree[tn].s += v*(e-s+1);
			if(s != e){
				lazy[2*tn].update += v;
				lazy[2*tn + 1].update += v; 
			}
		}
		return;
	}

	int mid = (s+e)/2;
	updatetree(s,mid,l,r,v,type,2*tn,tree,lazy);
	updatetree(mid+1,e,l,r,v,type,2*tn+1,tree,lazy);
	tree[tn].ss = tree[2*tn].ss + tree[2*tn+1].ss; 
	tree[tn].s = tree[2*tn].s + tree[2*tn+1].s;
}

ll query(int s,int e,int l,int r,int tn,Tree* tree,Lazy* lazy){
	if(s > e){
		return 0;
	}
	if(lazy[tn].set != 0){
		ll x = lazy[tn].set;
		tree[tn].ss = x*x*(e-s+1); 
		tree[tn].s = x*(e-s+1);
		if(s != e){
			lazy[2*tn].set = x;
			lazy[2*tn].update = 0;
			lazy[2*tn+1].set = x;
			lazy[2*tn+1].update = 0; 
		}
		lazy[tn].set = 0;
	}if(lazy[tn].update != 0){
		ll x = lazy[tn].update;
		tree[tn].ss += x*x*(e-s+1) + 2*x*(tree[tn].s);
		tree[tn].s += x*(e-s+1);
		if(s != e){
			lazy[2*tn].update += x;
			lazy[2*tn + 1].update += x;
		}
		lazy[tn].update = 0;
	}

	//out of range.
	if(s > r || e < l){
		return 0;
	}

	//completely in range.

	if(s >= l && e <= r){
		return tree[tn].ss;
	}

	int mid = (s+e)/2;

	ll a1 = query(s,mid,l,r,2*tn,tree,lazy);
	ll a2 = query(mid+1,e,l,r,2*tn+1,tree,lazy);

	return a1+a2;

}

int main(){
	int t;
	cin>>t;
	for(int i = 0;i < t;i++){
		cout<<"Case "<<i+1<<":"<<endl;
		int n,q;
		cin>>n>>q;
		ll arr[n];
		for(int j = 0;j < n;j++){
			cin>>arr[j];
		}
		Tree tree[4*n];
		buildTree(arr,tree,0,n-1,1);
		// for(int i = 1;i < 4*n;i++){
		// 	cout<<tree[i].ss<<" "<<tree[i].s<<endl;
		// }
		Lazy lazy[4*n];
		for(int j = 0;j < 4*n;j++){
			lazy[j].set = 0;
			lazy[j].update = 0;
		}
		for(int j = 0;j < q;j++){
			int type;
			cin>>type;
			if(type == 0 || type == 1){
				int l,r;
				ll v;
				cin>>l>>r>>v;
				updatetree(1,n,l,r,v,type,1,tree,lazy);
			}else if(type == 2){
				int l,r;
				cin>>l>>r;
				cout<<query(1,n,l,r,1,tree,lazy)<<endl;
			}
		}
	}	
}