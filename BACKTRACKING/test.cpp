#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int bitcount(int n,int k,int first = 0){
	if(n == 1){
		if(k == 0){
			return 1;
		}else{
			return 0;
		}
	}
	if(k < 0){
		return 0;
	}
	int option1 = bitcount(n-1,k,0) + bitcount(n-1,k,1);
	int option2 = bitcount(n-1,k-1,1) + bitcount(n-1,k,0);
	int ans = option1 + option2;
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int i,n,k;
		cin>>i>>n>>k;
		cout<<i<<" "<<bitcount(n,k)<<endl;
	}
}
