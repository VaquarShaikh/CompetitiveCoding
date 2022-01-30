#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

typedef long long ll;

int main(){
	int n,w;
	cin>>n>>w;

	pair<ll,ll>* arr = new pair<ll,ll>[n];

	for(int i = 0;i < n;i++){
		cin>>arr[i].f>>arr[i].s;
	}

	sort(arr,arr+n);

	ll*** dp = new ll**[2];

	for(int i = 0;i < 2;i++){
		dp[i] = new ll*[n+1];
		for(int j = 0;j <= n;j++){
			dp[i][j] = new ll[w+1];
			for(int k = 0;k <= w;k++){
				dp[i][j][k] = 0;
			}
		}
	}

	int primes[11] = {1,2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

	//base case , if no prime is included.

	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= w;j++){
			dp[0][i][j] = dp[0][i-1][j];
			if(j >= arr[i-1].s){
				dp[0][i][j] = max(dp[0][i][j],dp[0][i-1][j-arr[i-1].s] + arr[i-1].f);
			}
		}
	}

	for(int prime = 1;prime <= 10;prime++){
		int p = prime%2;

		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= w;j++){
				dp[p][i][j] = dp[p][i-1][j];
				if(j >= arr[i-1].s){
					dp[p][i][j] = max(dp[p][i][j],max(dp[p][i-1][j-arr[i-1].s]+arr[i-1].f,dp[p^1][i-1][j-arr[i-1].s] + arr[i-1].f*primes[prime]));
				}
			}
		}
	}

	cout<<dp[0][n][w]<<endl;

}