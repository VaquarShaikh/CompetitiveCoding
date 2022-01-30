#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define MAXN 100006

typedef long long ll;

bool check(ll* vp,ll* vq){
	for(ll i = 2;i*i < MAXN;i++){
		if(vq[i]  > 0 && vq[i] < vp[i]){
			return false;
		}
	}
	return true;
}

void removeCon(ll element,ll* vq){
	for(ll i = 2;i*i <= MAXN;i++){
		if(element%i == 0){
			vq[i]--;
			element = element/i;
		}
	}

	//check if element is prime.
	if(element != 1){
		vq[element]--;
	}
}

int main(){
	ll n,k;
	cin>>n>>k;
	ll* arr = new ll[n];

	rep(i,0,n){
		cin>>arr[i];
	}

	ll* vp = new ll[MAXN]();		//array of prime factors of k.
	ll* vq = new ll[MAXN]();		// array copy.

	for(int i = 2;i*i <= k;i++){
		if(k%i == 0){
			vp[i]++;		//prime factors of k.
			k = k/i;
		}
	}
	//check if k is prime number.
	if(k != 1){
		vp[k]++;
	}
	ll i = 0,j = 0,count = 0;

	while(i < n && j < n){
		ll temp = arr[i];
		for(int j = 2;j*j <= n;j++){
			if(temp == 0){
				break;
			}
			if(temp%j == 0){
				vq[j]++;
				temp = temp/j;
			}
		}
		if(check(vp,vq)){
			count += (n-i);
			removeCon(arr[j],vq);
			j++;
		}
		i++;
	}
	cout<<count<<endl;
}