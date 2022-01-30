//largest sum subarray using kadane's algorithm

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
	int arr[] = {-3,3,19,7};
	cout<<kadane(arr,4)<<endl;
}