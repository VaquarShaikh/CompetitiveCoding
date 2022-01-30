#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

int gcd(int a,int b){
	if(b == 0){
		return a;
	}

	return gcd(b,a%b);
}

int main(){
	int a,b;
	cin>>a>>b;

	cout<<gcd(a,b)<<endl;	
}