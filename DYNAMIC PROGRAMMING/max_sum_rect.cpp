#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[],int n){
	int current_sum = 0,best_sum = INT_MIN;
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

int max_sum_rect(int** input,int r,int c){
	int ans = INT_MIN;
	for(int count = 0;count < c;count++){
		int sum[r] = {0};
		for(int i = count;i < c;i++){
			int k = 0;
			for(int j = 0;j < r;j++){
				sum[k++] += input[j][i];
			}
			int res = kadane(sum,r);
			if(ans < res){
				ans = res;
			}
		}
	}
	return ans;
}

int main(){
	int n,m;
	cin>>n>>m;
	int** input = new int*[n];
	for(int i = 0;i < n;i++){
		input[i] = new int[m];
		for(int j = 0;j < m;j++){
			cin>>input[i][j];
		}
	}	
	cout<<max_sum_rect(input,n,m)<<endl;
	for(int i = 0;i < n;i++){
		delete [] input[i];
	}
	delete [] input;
}