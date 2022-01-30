#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

typedef long long ll;
#define MAXN 1000006
ll phi[MAXN];

int main(){
	for(ll i = 1;i < MAXN;i++){
		phi[i] = i;
	}

	for(ll i = 2;i < MAXN;i++){
		if(phi[i] == i){
			phi[i] = i - 1;
			for(ll j = 2*i;j < MAXN;j += i){
				phi[j] = (phi[j]*(i-1))/i;
			}
		}
	}
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		cout<<phi[n]<<endl;
	}
}