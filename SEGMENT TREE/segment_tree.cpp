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
	tree[tn] = tree[2*tn] + tree[2*tn + 1];
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
	tree[tn] = tree[2*tn] + tree[2*tn + 1];
}

int query(int* tree,int s,int e,int tn,int l,int r){
	
	//completely outside
	if(s > r || e < l){
		return 0;
	}

	//completely inside
	if(s >= l && e <= r){
		return tree[tn];
	}

	//partially in , partially out

	int mid = (s + e)/2;
	int a1 = query(tree,s,mid,2*tn,l,r);
	int a2 = query(tree,mid+1,e,2*tn+1,l,r);
	return a1 + a2;
}

int main(){
	int arr[] = {1,2,3,4,5};
	int* tree = new int[10];

	buildtree(arr,tree,0,4,1);
	int ans = query(tree,0,4,1,2,4);
	cout<<ans<<endl;
	updatetree(arr,tree,0,4,1,2,10);
	// for(int i =1 ;i < 10;i++){
	// 	cout<<tree[i]<<endl;
	// }	
	cout<<endl;
	int anss = query(tree,0,4,1,2,4);
	cout<<anss<<endl;
}