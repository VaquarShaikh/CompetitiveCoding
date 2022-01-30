#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

class trienode{
public:
	trienode* left;
	trienode* right;
};

void insert(int n,trienode* head){
	trienode* curr = head;
	for(int i = 31;i >= 0;i--){
		int b = (n>>i)&1;

		if(b == 0){
			if(!curr->left){
				curr->left = new trienode();
			}
			curr = curr->left;
		}else{
			if(!curr->right){
				curr->right = new trienode();
			}
			curr = curr->right;
		}
	}
}

int findmaxXorPair(trienode* head,int* arr,int n){
	int max_xor = INT_MIN;
	for(int i = 0;i < n;i++){
		trienode* curr = head;
		int value = arr[i];
		int curr_xor = 0;

		for(int j = 31;j >= 0;j--){
			int b = (value>>j)&1;

			if(b == 0){
				if(curr->right){
					curr_xor += pow(2,j);
					curr = curr->right;
				}else{
					curr = curr->left;
				}
			}else{
				if(curr->left){
					curr_xor += pow(2,j);
					curr = curr->left;
				}else{
					curr = curr->right;
				}
			}
		}
		if(curr_xor > max_xor){
			max_xor = curr_xor;
		}
	}
	return max_xor;
}

int main(){
	int n;
	cin>>n;
	int* arr = new int[n];
	int* ans = new int[n];

	rep(i,0,n){
		cin>>arr[i];
	}

	int txor = arr[0];
	trienode* head = new trienode();

	ans[0] = txor;
	insert(txor,head);

	int k = 1;
	rep(i,1,n){
		txor ^= arr[i];
		ans[k++] = txor;
		insert(txor,head);
	}

	cout<<findmaxXorPair(head,ans,n)<<endl;
}