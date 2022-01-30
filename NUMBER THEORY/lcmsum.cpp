#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

#define MAXN 1000010
typedef long long ll;

ll phi[MAXN];
ll res[MAXN];

void precal(){
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
	for(int i = 1;i <= MAXN;i++){
		for(int j = i;j <= MAXN;j += i){
			res[j] += (i*phi[i]);
		}
	}
}

void func(long long n)
{
	precal();
	ll ans = res[n] + 1;
	ans *= n;
	ans /= 2;
	cout<<ans<<endl;
}


int main()
{ 
	long long n;
	scanf ( "%lld", &n );
	func(n);
	return 0;
}