#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

typedef long long ll;

int retNum(vector<int>* v , int startv ,vector<int>& dp){
	// visited[startv] = true;
	int ans = 1;
	if(dp[startv] != -1){
		return dp[startv];
	}
	for(int i = 0;i < v[startv].size() ; i++){
		ans = (ans + retNum(v , v[startv][i] , dp))%mod;
	}
	return dp[startv] = ans;
}

int main(){
	int V, E, S;
    cin >> V >> E >> S;
	vector<int>* v = new vector<int>[V + 1];
	for(int i = 0;i < E;i++){
		int startp , endP;
		cin>>startp>>endP;
		v[startp].pb(endP);
	}

	vector<int> dp(V+1 , -1);
	// cout<<sizeof(dp);
	int ans = retNum(v , S , dp);
	cout<<ans<<endl;
}
// 4 4 1
// 1 2
// 2 3
// 1 3
// 3 4


// 5 6 2 
// 1 2
// 2 3
// 3 4
// 4 5
// 3 5
// 1 5


// 4 4 1 3
// 1 2
// 2 3
// 1 4
// 4 3