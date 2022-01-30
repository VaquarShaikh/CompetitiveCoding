#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

typedef long long ll;

struct Tree
{
	ll A;
	ll B;
	ll index;
};

void buildtree(ll* a,ll* b,Tree* tree,ll s,ll e,ll tn){
	if(s == e){
		tree[tn].A = a[s];
		tree[tn].B = b[s];
		tree[tn].index = s;
		return;
	}

	int mid = (s + e)/2;
	buildtree(a,b,tree,s,mid,2*tn);
	buildtree(a,b,tree,mid+1,e,2*tn+1);

	Tree left = tree[2*tn];
	Tree right = tree[2*tn + 1];

	if(left.A > right.A){
		tree[tn].A = left.A;
		tree[tn].B = left.B;
		tree[tn].index = left.index;
	}else if(left.A < right.A){
		tree[tn].A = right.A;
		tree[tn].B = right.B;
		tree[tn].index = right.index;
	}else{
		if(left.B > right.B){
			tree[tn].A = right.A;
			tree[tn].B = right.B;
			tree[tn].index = right.index;	
		}else if(left.B < right.B){
			tree[tn].A = left.A;
			tree[tn].B = left.B;
			tree[tn].index = left.index;
		}else{
			if(left.index < right.index){
				tree[tn].A = left.A;
				tree[tn].B = left.B;
				tree[tn].index = left.index;
			}else{
				tree[tn].A = right.A;
				tree[tn].B = right.B;
				tree[tn].index = right.index;	
			}
		}
	}
}

Tree query(Tree* tree,ll s,ll e,ll l,ll r,ll tn){

	//out of range
	if(s > r || e < l){
		Tree ans;
		ans.A = INT_MIN;
		ans.B = INT_MAX;
		ans.index = INT_MIN;
		return ans;
	}

	//completely in range
	if(s >= l && e <= r){
		return tree[tn];
	}
	int mid = (s + e)/2;

	Tree left = query(tree,s,mid,l,r,2*tn);
	Tree right = query(tree,mid+1,e,l,r,2*tn+1);

	Tree ans;
	if(left.A > right.A){
		ans.A = left.A;
		ans.B = left.B;
		ans.index = left.index;
	}else if(left.A < right.A){
		ans.A = right.A;
		ans.B = right.B;
		ans.index = right.index;
	}else{
		if(left.B > right.B){
			ans.A = right.A;
			ans.B = right.B;
			ans.index = right.index;	
		}else if(left.B < right.B){
			ans.A = left.A;
			ans.B = left.B;
			ans.index = left.index;
		}else{
			if(left.index < right.index){
				ans.A = left.A;
				ans.B = left.B;
				ans.index = left.index;
			}else{
				ans.A = right.A;
				ans.B = right.B;
				ans.index = right.index;	
			}
		}
	}
	return ans;
}

int main(){
	ll n;
	cin>>n;
	ll* a = new ll[n];
	ll* b = new ll[n];

	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	for(int i = 0;i < n;i++){
		cin>>b[i];
	}

	Tree* tree = new Tree[4*n]();
	buildtree(a,b,tree,0,n-1,1);

	ll q;
	cin>>q;
	while(q--){
		ll x,y;
		cin>>x>>y;
		Tree ans = query(tree,0,n-1,x-1,y-1,1);
		cout<<(ans.index + 1)<<endl;
	}
	// for(int i = 1;i < 4*n;i++){
	// 	cout<<tree[i].A<<" "<<tree[i].B<<" "<<tree[i].index<<endl;
	// }

}