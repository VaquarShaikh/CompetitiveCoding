#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

#define MAXN 1000004
int primes[MAXN];

int main(){
	memset(primes,0,sizeof(primes));
	
	for(int i = 2; i < MAXN;i++){
		if(primes[i] == 0){
			for(int j = i;j < MAXN;j += i){
				primes[j] = primes[j] + 1;
			}
		}
	}

	primes[2] = 1;

	for(int i = 3;i < MAXN;i += 2){
		if(primes[i] == 0){
			primes[i] = 1;
		}
	}

	int** nfactor = new int*[11];
	for(int i = 0;i <=  10;i++){
		nfactor[i] = new int[MAXN];
		for(int j = 0;j < MAXN;j++){
			nfactor[i][j] = 0;
		}
	}
	for(int i = 0;i <= 10;i++){
		for(int j = 1;j < MAXN;j++){
			if(primes[j] == i){
				nfactor[i][j] = nfactor[i][j-1] + 1;
			}else{
				nfactor[i][j] = nfactor[i][j-1];
			}
		}
	}

	int t;
	cin>>t;
	while(t--){
		int a,b,n;
		cin>>a>>b>>n;

		int ans = nfactor[n][b] - nfactor[n][a-1];
		cout<<ans<<endl;
	}
}