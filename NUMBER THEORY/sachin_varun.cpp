#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

typedef long long ll;

class Triplet{
public:
	ll x,y,gcd;
};

Triplet extendedEuclid(int a,int b){
	if(b == 0){
		Triplet ans;
		ans.gcd = a;
		ans.x = 1;
		ans.y = 0;
		return ans;
	}

	Triplet smallAns = extendedEuclid(b,a%b);

	Triplet ans;
	ans.gcd = smallAns.gcd;
	ans.x = smallAns.y;
	ans.y = smallAns.x - (a/b)*smallAns.y;

	return ans;
}

ll modinverse(ll a,ll m){
	Triplet ans = extendedEuclid(a,m);
	ll res = ans.x;

	return(res%m + m)%m;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,b,d;
		cin>>a>>b>>d;

		ll g = __gcd(a,b);
		if(d%g){
			cout<<0<<endl;
			continue;
		}

		if(d == 0){
			cout<<1<<endl;
			continue;
		}

		a /= g;
		b /= g;
		d /= g;

		ll y1 = (d%a*modinverse(b,a))%a;

		ll firstVal = (d/b);
		if(d < y1*b){
			cout<<0<<endl;
			continue;
		}

		ll n = (firstVal - y1)/a;

		cout<<n+1<<endl;
	}
}