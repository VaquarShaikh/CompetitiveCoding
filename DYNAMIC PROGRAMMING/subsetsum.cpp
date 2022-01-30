#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

bool subset_sum(int n,int* arr,int k){
	int dp[k+1] = {0};	
	for(int i = 0;i <= n;i++){
		for(int j = k;j >= arr[i];j--){
			dp[j] = max(dp[j],(arr[i] + dp[j - arr[i]]));
		}
	}
    int ans = dp[k];
    if(ans != k){
        return false;
    }else{
        return true;
    }
}

int main(){
	int n;
	cin>>n;
	int* arr = new int[n];
	for(int i = 0;i < n;i++){
		cin>>arr[i];
	}	
	int k;
	cin>>k;
	if(subset_sum(n,arr,k)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
    delete [] arr;
}