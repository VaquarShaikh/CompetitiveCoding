#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

void buildTree(int* arr,int* tree,int s,int e,int tn){
	if(s == e){
		tree[tn] = arr[s];
		return;
	}

	int mid = (s + e)/2;

	buildTree(arr,tree,s,mid,2*tn);
	buildTree(arr,tree,mid + 1, e,2*tn + 1);
	tree[tn] = min(tree[2*tn],tree[2*tn + 1]);
}

void updatelazy(int* tree,int* lazy,int low,int high,int startR,int endR,int currPos,int inc){
	if(low > high){
		return;
	}

	//update if any in lazy tree.
	if(lazy[currPos] != 0){
		tree[currPos] += lazy[currPos];
		if(low != high){
			lazy[2*currPos] += lazy[currPos];
			lazy[2*currPos + 1] += lazy[currPos];
		}
		lazy[currPos] = 0;
	}

	//now check with inc.

	//no overlap
	if(startR > high || endR < low){
		return;
	}
	//complete overlap.
	if(startR <= low && high <= endR){
		tree[currPos] += inc;
		if(low != high){
			lazy[2*currPos] += inc;
			lazy[2*currPos + 1] += inc;
		}
		return;
	}
	//partial overlap.

	int mid = (low + high)/2;
	updatelazy(tree,lazy,low,mid,startR,endR,2*currPos,inc);
	updatelazy(tree,lazy,mid+1,high,startR,endR,2*currPos + 1,inc);
	tree[currPos] = min(tree[2*currPos],tree[2*currPos + 1]);
}

int query(int* tree,int* lazy,int low,int high,int startR,int endR,int currPos){
	if(low > high){
		return INT_MAX;
	}
	if(lazy[currPos] != 0){
		tree[currPos] += lazy[currPos];
		if(low != high){
			lazy[2*currPos] += lazy[currPos];
			lazy[2*currPos + 1] += lazy[currPos];
		}
		lazy[currPos] = 0;
	}
	// out of range.
	if(startR > high || endR < low){
		return INT_MAX;
	}
	// complete overlap		//low  = s , high = e
	if(startR <= low && high <= endR){
		return tree[currPos];
	}
	int mid = (low + high)/2;
	int ans1 = query(tree,lazy,low,mid,startR,endR,2*currPos);
	int ans2 = query(tree,lazy,mid+1,high,startR,endR,2*currPos + 1);
	return min(ans1,ans2);
}

int main(){
	int arr[] = {1,3,-2,4};
	int* tree = new int[12]();
	buildTree(arr,tree,0,3,1);	

	int* lazy = new int[12]();
	updatelazy(tree,lazy,0,3,0,3,1,3);
	updatelazy(tree,lazy,0,3,0,1,1,2);

	cout<<"segment tree\n";

	for(int i = 1;i < 12;i++){
		cout<<tree[i]<<endl;
	}
	cout<<endl<<endl;
	cout<<"lazy tree \n";

	for(int i = 1;i < 12;i++){
		cout<<lazy[i]<<endl;
	}
	cout<<endl<<endl;
	cout<<"query in interval 1 to 2 : "<<query(tree,lazy,0,3,1,2,1)<<endl;
}