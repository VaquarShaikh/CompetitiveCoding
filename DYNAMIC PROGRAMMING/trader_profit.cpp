#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int max_prof1(int k,int n,int* arr,int ongoing){
	if(n == 0){
		return 0;
	}
	if(ongoing){
		int op1 = max_prof(k,n-1,arr+1,ongoing);
		int op2 = max_prof(k-1,n-1,arr+1,0) + arr[0];
		return max(op1,op2);
	}else{
		if(k > 0){
			int op1 = max_prof(k,n-1,arr+1,ongoing);
			int op2 = max_prof(k,n-1,arr+1,1) - arr[0];
			return max(op1,op2);
		}else{
			return max_prof(k,n-1,arr+1,ongoing);
		}
	}
}

int max_prof(int k,int n,int* arr,int ongoing,int output[][11][2]){
	if(n == 0){
		return 0;
	}
	if(output[n][k][ongoing] != -1){
		return output[n][k][ongoing];
	}int ans;
	if(ongoing){
		int op1 = max_prof(k,n-1,arr+1,ongoing,output);
		int op2 = max_prof(k-1,n-1,arr+1,0,output) + arr[0];
		ans =  max(op1,op2);
	}else{
		if(k > 0){
			int op1 = max_prof(k,n-1,arr+1,ongoing,output);
			int op2 = max_prof(k,n-1,arr+1,1,output) - arr[0];
			ans = max(op1,op2);
		}else{
			ans = max_prof(k,n-1,arr+1,ongoing,output);
		}
	}
	output[n][k][ongoing] = ans;
	return ans;
}

int main(){
	int q;
	cin>>q;
	while(q--){
		int n,k;
		cin>>k;
		cin>>n;
		int* arr = new int[n];
		for(int i = 0;i < n;i++){
			cin>>arr[i];
		}
		int output[31][11][2];
		for(int i = 0;i <= n;i++){
			for(int j = 0;j <= k;j++){
				for(int l = 0;l < 2;l++){
					output[i][j][l] = -1;
				}
			}
		}
		cout<<max_prof(k,n,arr,0,output)<<endl;
	}	
}