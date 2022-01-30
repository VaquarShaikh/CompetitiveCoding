#include<bits/stdc++.h>
using namespace std;
#define MAXN 16

typedef long long ll;

ll solveh(int like[][MAXN],int n,int s,int mask,int* dp)
{
	if(s >= n){
		return 1;
	}
	if(dp[mask] != INT_MAX){
		return dp[mask];
	}
	ll count = 0;

	for(int j = 0;j < n;j++){
		if(!(mask&(1<<j)) && (like[s][j] == 1)){
			ll ans = solveh(like,n,s+1,mask|(1<<j),dp);
			count += ans;
		}
	}
	dp[mask] = count;
	return count;
}

ll solve(int like[][MAXN],int N)
{
	int* dp = new int[1<<N];
	for(int i = 0;i < (1<<N);i++){
		dp[i] = INT_MAX;//
	}

	return solveh(like,N,0,0,dp);
}

long long solvei(int cost[][MAXN],int n)
{
    ll* dp = new ll[1<<n]();

    dp[0] = 1;
    for(ll mask = 0;mask < ((1<<n) - 1);mask++){
        ll temp = mask;
        //count number of set bits.
        ll k = 0;
        while(temp > 0){
            if(temp%2 == 1){
                k++;
            }
            temp = temp/2;
        }
        // cout<<k<<endl;
        for(ll j = 0;j < n;j++){
            if((!(mask&(1<<j))) && cost[k][j] == 1){
                dp[mask|(1<<j)] += dp[mask];
            }
        }
    }
    return dp[(1<<n) - 1];
}

int main()
{
	int n,like[MAXN][MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++){
			cin>>like[i][j];
		}
	}
	cout<<solve(like,n)<<endl;
}