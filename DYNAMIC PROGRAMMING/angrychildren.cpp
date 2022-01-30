#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
	ll n,k;
	cin>>n;
	cin>>k;
	ll arr[n];
	for(int i = 0;i < n;i++){
		cin>>arr[i];
	}	
	sort(arr,arr + n);
	ll target = 0,sum = arr[0],ans = LLONG_MAX;
	for(ll i = 1;i < k;i++){
		sum += arr[i];
		target += ((ll)(i+1))*arr[i] - sum;
	}
	if(ans > target){
		ans = target;
	}
 ll temp = sum - arr[0];
	ll old_cost = target;
	ll new_cost = 0;
	
	for(ll i = 2;i <= (n-k+1);i++){
		ll x = arr[i+k-2];
		ll y = arr[i-2];
       
        ll two=2;
		new_cost = old_cost - two*(sum - y) + ((ll)(k-1))*x + ((ll)(k-1))*y;
		if(ans > new_cost){
			ans = new_cost;
			old_cost = new_cost;
			new_cost = 0;
		}else{
			old_cost = new_cost;
			new_cost = 0;
		}
        sum+=arr[i+k-2]-arr[i-2];
	}
	cout<<ans<<endl;
}