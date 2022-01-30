#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

struct node{
	int max;
	int smax;
};

void buildtree(int* arr,node* tree,int tn,int s,int e){
	if(s == e){
		tree[tn].max = arr[s];
		tree[tn].smax = INT_MIN;
		return;
	}
	int mid = (s + e)/2;

	buildtree(arr,tree,2*tn,s,mid);
	buildtree(arr,tree,2*tn + 1,mid + 1,e);
	node left = tree[2*tn];
	node right = tree[2*tn + 1];
	tree[tn].max = max(left.max,right.max);
	tree[tn].smax = min(max(right.max,left.smax) , max(left.max,right.smax));
	// return (tree[tn].max + tree[tn].smax);
}

void updatetree(int* arr,node* tree,int s,int e,int tn,int idx,int val){
	if(s == e){
		arr[idx] = val;
		tree[tn].max = val;
		tree[tn].smax = INT_MIN;
		return;
	}
	int mid = (s + e)/2;

	if(idx > mid){
		updatetree(arr,tree,mid + 1,e,2*tn + 1,idx,val);
	}else{
		updatetree(arr,tree,s,mid,2*tn,idx,val);
	}
	node left = tree[2*tn];
	node right = tree[2*tn + 1];
	tree[tn].max = max(left.max,right.max);
	tree[tn].smax = min(max(right.max,left.smax) , max(left.max,right.smax));
	// return;
}

node query(node *tree,int start,int end,int treeNode,int left,int right){
    //completely Outside
    if(start>right || end<left){
        node ans;    ans.max=ans.smax=INT_MIN;
        return ans;
    }
    //completely Inside
    if(start>=left && end<=right){
      return tree[treeNode];
    }
    //partially in partially out
    else{
        int mid=(start+end)/2;
        node l=query(tree,start,mid,2*treeNode,left,right);
        node r=query(tree,mid+1,end,2*treeNode+1,left,right);
        node ans;
         ans.max=max(l.max,r.max);
        ans.smax=min((max(l.max,r.smax)),max(l.smax,r.max));       

        return  ans;
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

	int q;
	cin>>q;
	while(q--){
		char c;int x,y;
		cin>>c>>x>>y;
		if(c == 'Q'){
			node ans = query(tree,0,n-1,1,x-1,y-1);
            cout<<ans.max+ans.smax<<endl;
		}else{
			updatetree(arr,tree,0,n-1,1,x-1,y);
		}
	}
}