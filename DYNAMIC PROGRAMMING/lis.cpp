#include<bits/stdc++.h>
using namespace std;

int lis(int arr[],int n){
	int output[n];
	output[0] = 1;
	for(int i = 1;i < n;i++){
		output[i] = 1;
		for(int j = i-1;j >=0;j--){
			if(arr[j] > arr[i]){
				continue;
			}
			int possans = output[j] + 1;
			if(possans > output[i]){
				output[i] = possans;
			}
		}
	}
	int max = INT_MIN;
	for(int i = 0;i < n;i++){
		if(max < output[i]){
			max = output[i];
		}
	}
	return max;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i < n;i++){
		cin>>arr[i];
	}
	cout<<lis(arr,n)<<endl;
}