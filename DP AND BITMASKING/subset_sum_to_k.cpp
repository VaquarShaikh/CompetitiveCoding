#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

int subset_sum_k(int* arr,int n,int k){
	int count = 0;
	for(int mask = 0;mask <= (1<<n) - 1;mask++){
		int sum = 0;
		for(int j = 0;j < n;j++){
			//check ith bit is set or no.
			if(mask&(1<<j)){
				sum += arr[j];
			}
		}
		// cout<<sum<<" "<<mask<<endl;
		if(sum == k){
			count++;
		}
	}
	return count;
}

int main(){
	int n,k;
	cin>>n>>k;

	int* arr = new int[n];
	rep(i,0,n){
		cin>>arr[i];
	}

	cout<<subset_sum_k(arr,n,k)<<endl;
}