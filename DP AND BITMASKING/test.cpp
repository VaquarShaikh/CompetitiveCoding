#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second
typedef long long ll;

bool compare(pair<ll,ll> a,pair<ll,ll> b){
	return a.f > b.f;
}

int main(){
	int n,w;
	pair<ll,ll> queries[2008];	//first = profit , second = weight.
	cin>>n>>w;
	rep(i,0,n){
		cin>>queries[i].f>>queries[i].s;
	}

	sort(queries,queries + n,compare);
	for(int i = 0;i < n;i++){
		cout<<queries[i].f<<" "<<queries[i].s<<endl;
	}	cout<<endl;
}