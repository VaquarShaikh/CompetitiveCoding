#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main(){
	int n,m;
	cin>>n>>m;
	int arr[101][101];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin>>arr[i][j];
		}
	}	 
	int dp[101][101];
	for(int i = 0;i < m;i++){
		dp[0][i] = arr[0][i];
	}
	for(int i = 1;i < n;i++){
		for(int j = 0;j < m;j++){
			if(j - 1 < 0){
				dp[i][j] = arr[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
			}else if(j + 1 >= m){
				dp[i][j] = arr[i][j] + min(dp[i-1][j-1],dp[i-1][j]);
			}else{
				dp[i][j] = arr[i][j] + min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]));	
			}
			
		}
	}
	int min = INT_MAX;
	for(int i = 0;i < m;i++){
		if(min > dp[n-1][i]){
			min = dp[n-1][i];
		}
	}
	cout<<min<<endl;
}