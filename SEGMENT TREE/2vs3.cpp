#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

typedef long long ll;

void buildtree(ll* arr,ll* tree,ll* power,ll s,ll e,ll tn){
	if(s == e){
		tree[tn] = arr[s]%3;
		return;
	}

	int mid = (s + e)/2;
	buildtree(arr,tree,power,s,mid,2*tn);
	buildtree(arr,tree,power,mid+1,e,2*tn+1);

	ll p = e - mid;

	ll val = power[p];

	tree[tn] = ((tree[2*tn]*val%3) + tree[2*tn + 1])%3;

}

void updatetree(ll* tree,ll* arr,ll* power,ll s,ll e,ll idx,ll tn){
	if(s == e){
		if(tree[idx] == 0){
			tree[idx] = 1;
			arr[idx] = 1;
		}
		return;
	}

	int mid = (s + e)/2;
	if(idx > mid){
		updatetree(tree,arr,power,s,mid,idx,2*tn);
	}else{
		updatetree(tree,arr,power,s,mid,idx,2*tn + 1);
	}
	ll p = e - mid;

	ll val = power[p];
	tree[tn] = ((tree[2*tn]*val%3) + tree[2*tn + 1])%3;	
}

ll query(ll* tree,ll s,ll e,ll l,ll r,ll tn){
	if(s > r || e < l){
		return 0;
	}

	if(s >= l && e <= r){
		return tree[tn];
	}

	int mid = (s + e)/2;

	int a1 = query(tree,s,mid,l,r,2*tn);
	int a2 = query(tree,mid + 1,e,l,r,2*tn + 1);
	return (a1 + a2)%3;
}

int main(){
	ll n,k = 0;
	cin>>n;
	ll* arr = new ll[n];
	string a;
	cin>>a;
	for(ll i = 0;i < n;i++){
		arr[k++] = a[i] - '0';
	}	
	ll* power = new ll[n];
	power[0] = 1;
	for(int i = 1;i < n;i++){
		power[i] = (power[i-1]*2)%3;
	}
	// for(int i = 0;i < n;i++){
	// 	cout<<arr[i]<<" ";
	// }
	ll* tree = new ll[4*n]();
	buildtree(arr,tree,power,0,n-1,1);
	ll q;
	cin>>q;
	while(q--){
		ll type,x,y;
		cin>>type;		//type 0 for query , 1 for update.

		if(type == 0){
			cin>>x>>y;
			cout<<query(tree,0,n-1,x-1,y-1,1);
		}else{
			cin>>x;
			updatetree(tree,arr,power,0,n-1,x-1,1);
		}

	}
}