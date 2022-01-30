#include<bits/stdc++.h>
using namespace std;

bool check(int arr[],int n){
	for(int i = 0;i < n;i++){
		for(int j = i + 1;j < n;j++){
			if(arr[i] == 1 && arr[j] == 1){
				if(abs(j - i) < 6){
					return false;
				}
			}
		}
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int diff[n];
		for(int i = 0;i < n;i++){
			cin>>arr[i];
		}
		if(check(arr,n)){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
}