#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

typedef long long ll;

ll gcd(ll a,ll b){
	if(b == 0){
		return a;
	}

	return gcd(b,a%b);
}


int main(){
	int t;
	cin>>t;
	while(t--){
		ll a;
		cin>>a;
		string s;
		cin>>s;
		ll b = s[0] - '0';

		for(ll i = 1;i < s.length();i++){
			int current_digit = s[i] - '0';

			b = (b*10%a + current_digit)%a;
		}

		cout<<gcd(a,b)<<endl;
	}	
}