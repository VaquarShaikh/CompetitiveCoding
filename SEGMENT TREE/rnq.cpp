#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

void buildtree(int* arr,int* tree,int s,int e,int tn){
	if(s == e){
		tree[tn] = arr[s];
		return;
	}
	int mid = (s + e)/2;
	buildtree(arr,tree,s,mid,2*tn);
	buildtree(arr,tree,mid+1,e,2*tn+1);
	tree[tn] = min(tree[2*tn],tree[2*tn + 1]);
}

int query(int* tree,int s,int e,int tn,int l,int r){
	
	//completely outside
	if(s > r || e < l){
		return INT_MAX;
	}

	//completely inside
	if(s >= l && e <= r){
		return tree[tn];
	}

	//partially in , partially out

	int mid = (s + e)/2;
	int a1 = query(tree,s,mid,2*tn,l,r);
	int a2 = query(tree,mid+1,e,2*tn+1,l,r);
	return min(a1,a2);
}

void updatetree(int* arr,int* tree,int s,int e,int tn,int idx,int val){
	if(s == e){
		arr[idx] = val;
		tree[tn] = val;
		return;
	}
	int mid = (s + e)/2;

	if(idx > mid){
		updatetree(arr,tree,mid + 1,e,2*tn + 1,idx,val);
	}else{
		updatetree(arr,tree,s,mid,2*tn,idx,val);
	}
	tree[tn] = min(tree[2*tn],tree[2*tn + 1]);
}

int main(){
	int n,q;
	cin>>n>>q;
	int* arr = new int[n];
	for(int i = 0;i < n;i++){
		cin>>arr[i];
	}	
	int* tree = new int[4*n];

	buildtree(arr,tree,0,n-1,1);
	// for(int i = 0;i < n;i++){
	// cout<<tree[i]<<endl;
	// }
	while(q--){
		char c;
		int x,y;
		cin>>c>>x>>y;
		if(c == 'q'){
			cout<<query(tree,0,n-1,1,x-1,y-1)<<endl;
		}else{
			updatetree(arr,tree,0,n-1,1,x-1,y);
		}
	}
}