#include<bits/stdc++.h>
using namespace std;

void conv(int arr[],int n){
	for(int i = 0;i < n;i++){
		if(arr[i+1] == arr[i] - 1){
			swap(arr[i],arr[i+1]);
		}
	}
	for(int i = 0;i < n;i++){
		cout<<arr[i]<< " ";
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i = 0;i < n;i++){
			cin>>arr[i];
		}
		conv(arr,n);
		if(is_sorted(arr,arr+n)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}

/*2
4
1 0 3 2
3
2 1 0*/