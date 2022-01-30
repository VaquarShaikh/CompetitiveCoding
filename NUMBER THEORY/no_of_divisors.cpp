#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

#define MAX 500001

typedef long long ll;

vector<int>* sieve(){
	bool isprime[MAX];
    
    vector<int>* primes = new vector<int>();
	for(int i = 2;i <= MAX;i++){
		isprime[i] = true;
	}
	
	for(int i = 2;i*i <= MAX;i++){
		if(isprime[i]){
			for(int j = i*i;j <= MAX;j += i){
				isprime[j] = false;
			}
		}
	}

	primes->pb(2);
	for(int i = 3;i <= MAX;i += 2){
		if(isprime[i]){
			primes->pb(i);
		}
	}

	return primes;
}

ll noOfDivisors(int n,vector<int>*& primes){
	ll res = 1;
	for(int i = 0;primes->at(i) <= n;i++){
		int k = primes->at(i);
		ll count = 0;
		while((n/k) != 0){
			count = (count + (n/k))%mod;
			k = k*primes->at(i);
		}
		res = (res*((count + 1)%mod))%mod;
	}
	return res;
}

int main(){
    vector<int>* primes = sieve();
	int t;
	cin>>t;
	while(t--){
		int n;
        cin>>n;
		cout<<noOfDivisors(n,primes)<<endl;
	}
}