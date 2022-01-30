#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

typedef long long ll;

struct Tree
{
	ll odd=0;
	ll even=0;
};

void buildTree(ll* arr,Tree* tree,ll s,ll e,ll tn){
	if(s == e){
		if(arr[s]%2 != 0){
			tree[tn].odd = 1;
			tree[tn].even = 0;
		}else{
			tree[tn].odd = 0;
			tree[tn].even = 1;
		}
		return;
	}

	int mid = (s + e)/2;

	buildTree(arr,tree,s,mid,2*tn);
	buildTree(arr,tree,mid+1,e,2*tn + 1);

	tree[tn].odd = tree[2*tn].odd + tree[2*tn + 1].odd;
	tree[tn].even = tree[2*tn].even + tree[2*tn + 1].even;

}

void updatetree(ll* arr,Tree* tree,ll s,ll e,ll tn,ll idx,ll val){
	if(s == e){
        if(val %2==0)
        {
            if(arr[s]%2==0)
            {
                arr[s] = val;
            }
            else
            {
                arr[s] = val;
                tree[tn].odd--;
                tree[tn].even++;
            }
        }
        else
        {
            if(arr[s]%2!=0)
            {
                arr[s] = val;
            }
            else
            {
                arr[s] = val;
                tree[tn].odd++;
                tree[tn].even--;
            }
        }
        return;
	}

	int mid = (s + e)/2;

	if(idx > mid){
		updatetree(arr,tree,mid + 1,e,2*tn + 1,idx,val);
	}else{
		updatetree(arr,tree,s,mid,2*tn,idx,val);
	}
	tree[tn].odd = tree[2*tn].odd + tree[2*tn + 1].odd;
	tree[tn].even = tree[2*tn].even + tree[2*tn + 1].even;
}

Tree query(Tree* tree,ll s,ll e,ll l,ll r,ll tn,ll type){
	
	//out of range.
	if(s>r || e<l){
		Tree ans;
		ans.odd = 0;
		ans.even = 0;
		return ans;
	}

	//completely in range.
	if(s>=l && e<=r){
		return tree[tn];
	}

	int mid = (s + e)/2;

	Tree a1 = query(tree,s,mid,l,r,2*tn,type);
	Tree a2 = query(tree,mid+1,e,l,r,2*tn + 1,type);

	Tree ans;

	ans.even = a1.even + a2.even;
	ans.odd = a1.odd + a2.odd;
	return ans;
}

int main(){
	int n;
	cin>>n;
	ll arr[n];
	for(int i = 0;i < n;i++){
		cin>>arr[i];
	}
	Tree* tree = new Tree[4*n]();
	buildTree(arr,tree,0,n-1,1);

	ll q;
	cin>>q;
	while(q--){
		ll type;
		cin>>type;
		if(type == 1 || type == 2){
			ll x,y;
			cin>>x>>y;
			Tree ans = query(tree,0,n-1,x - 1,y - 1,1,type);
			if(type == 1){
				cout<<ans.even<<endl;
			}else{
				cout<<ans.odd<<endl;
			}
		}else if(type == 0){
			ll x,y;
			cin>>x>>y;
			updatetree(arr,tree,0,n-1,1,x-1,y);
		}
	}

	// for(int i = 1;i < 4*n;i++){
	// 	cout<<tree[i].odd<<" "<<tree[i].even<<endl;
	// }
}