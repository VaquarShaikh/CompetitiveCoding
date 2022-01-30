#include<bits/stdc++.h>
using namespace std;

bool check(int arr[],int n){
	for(int i = 0;i < n;i++){
		if(arr[i] > 2){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i < n;i++){
		cin>>arr[i];
	}
	int dist_arr[n+1];
	int k = 0,num1 = 0,num2 = 0;
	for(int i = 1;i <= n;i++){
		int diff = abs(i - arr[k]);
		dist_arr[k++] = diff;
	}
	if(!check(dist_arr,n)){
		cout<<"NO"<<endl;
	}else{
		for(int i = 0;i < n;i++){
			if(dist_arr[i] == 1){
				num1 += dist_arr[i];
			}else{
				num2 += dist_arr[i];
			}
		}
		cout<<"YES"<<endl<<(num1+num2)/2<<endl;
	}
	/*for(int i = 0;i < n;i++){
		cout<<dist_arr[i]<<" ";
	}*/
}