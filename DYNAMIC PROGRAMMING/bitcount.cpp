#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int bitcount(int n,int k,int first,int output[101][101][2]){
	if(n == 1){
		if(k == 0){
			return 1;
		}else{
			return 0;
		}
	}

	if(output[n][k][first] != -1){
		return output[n][k][first];
	}
	int res = 0;
	if(first == 1){
		res = (bitcount(n-1,k-1,1,output)%mod + bitcount(n-1,k,0,output)%mod)%mod;
	}else{
		res = (bitcount(n-1,k,0,output)%mod + bitcount(n-1,k,1,output)%mod)%mod;
	}
	output[n][k][first] = res;
	return res;
}
5
int main(){
	int t;
	cin>>t;
	while(t--){
		int i,n,k;
		cin>>i>>n>>k;
        int output[101][101][2];
		for(int i = 0;i <= n;i++){
			for(int j = 0;j <= k;j++){
				for(int l = 0;l < 2;l++){
					output[i][j][l] = -1;
				}
			}
		}
		int sum = (bitcount(n,k,0,output)%mod + bitcount(n,k,1,output)%mod)%mod;
		cout<<i<<" "<<sum<<endl;
	}	
}