#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll n,ll k){
	ll sum = 0;
	ll curr = n;
	while(curr > 0){
		sum = sum + min(curr,k);
		curr = curr - k;bhb
		curr = curr - (curr/10);
	}
	if(2*sum >= n){
		return true;
	}else{
		return false;
	}
}

int main(){
	ll n;
	cin>>n;
	ll l = 1,h = n;
	ll ans = 0;
	while(l <= h){
		ll mid = l + (h - l)/2;
		if(check(n,mid)){
			ans = mid;
			h = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	cout<<ans<<endl;
}