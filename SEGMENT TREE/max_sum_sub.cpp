#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

struct node{
	long int sum;
	long int maxsum;
	long int bps;
	long int bss;
};

void buildtree(int* arr,node* tree,int tn,int s,int e){
	if(s == e){
		tree[tn].sum = arr[s];
		tree[tn].maxsum = arr[s];
		tree[tn].bps = arr[s];
		tree[tn].bss = arr[s];
		return;
	}
	int mid = (s + e)/2;
	buildtree(arr,tree,2*tn,s,mid);
	buildtree(arr,tree,2*tn + 1,mid + 1,e);
	node left = tree[2*tn];
	node right = tree[2*tn + 1];

	long int a = max(left.maxsum,right.maxsum);
	long int b = max(left.sum + right.bps,right.sum + left.bss);
	long int c = left.bss + right.bps;
	tree[tn].maxsum = max(a,max(b,c));
	tree[tn].sum = left.sum + right.sum;
	tree[tn].bps = max(left.sum + right.bps,left.bps);
	tree[tn].bss = max(right.bss , right.sum + left.bss);
}

node query(node* tree,int s,int e,int tn,int l,int r){
	//completely Outside
	if(s>r || e<l){
		node ans;
		ans.sum = INT_MIN;
		ans.maxsum = INT_MIN;
		ans.bps = INT_MIN;
		ans.bss = INT_MIN;
		return ans;
	}
    //completely Inside
	if(s>=l && e<=r){
		return tree[tn];
	}
    //partially in partially out
	else{
		int mid = (s + e)/2;
		node left = query(tree,s,mid,2*tn,l,r);
		node right = query(tree,mid+1,e,2*tn+1,l,r);
		node ans;
		long int a = max(left.maxsum,right.maxsum);
		long int b = max(left.sum + right.bps,right.sum + left.bss);
		long int c = left.bss + right.bps;
		ans.sum = left.sum + right.sum;
		ans.maxsum = max(a,c);
		ans.bps = max(left.sum + right.bps,left.bps);
		ans.bss = max(right.bss , right.sum + left.bss);
		return ans;
	}
}

int main(){
	int n;
	cin>>n;
	int* arr = new int[n];
	for(int i = 0;i < n;i++){
		cin>>arr[i];
	}	
	node* tree = new node[4*n];
	buildtree(arr,tree,1,0,n-1);
	int m;
	cin>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		node ans = query(tree,0,n-1,1,x-1,y-1);
		cout<<ans.maxsum<<endl;
	}
}