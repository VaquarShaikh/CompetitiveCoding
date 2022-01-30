#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[],int n){
	int current_sum = 0,best_sum = 0;
	for(int i  = 0;i < n;i++){
		current_sum += arr[i];
		if(best_sum < current_sum){
			best_sum = current_sum;
		}if(current_sum < 0){
			current_sum = 0;
		}
	}
	return best_sum;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i = 0;i < n;i++){
			cin>>arr[i];
		}
		int ssize = n*k;
		int arr1[ssize];
		int l = 0;
		for(int i = 0;i < ssize;i++){
			arr1[i] = arr[l++];
			if(l == n){
				l = 0;
			}
		}
		/*for(int i = 0;i < ssize;i++){
			cout<<arr1[i]<<" ";
		}cout<<endl;*/
		cout<<kadane(arr1,ssize)<<endl;
	}
}