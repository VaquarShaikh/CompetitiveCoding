#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

class Triplet{
public:
	int x,y,gcd;
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

int main(){
	int a,b;
	cin>>a>>b;
	Triplet ans = extendedEuclid(a,b);
	cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;
}