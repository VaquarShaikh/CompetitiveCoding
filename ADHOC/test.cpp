#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll a,b;
	cin>>a>>b;
	int mod = (int)pow(10,9) + 7;
	int temp1 = (int)(((ll)a)%mod);
	int temp2 = (int)(((ll)b)%mod);
	int res = (int)(temp1*temp2)%mod;
	cout<<res<<endl;
}