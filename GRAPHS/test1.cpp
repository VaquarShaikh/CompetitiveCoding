#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef long long ll;
pair<ll,pair<ll,ll>> p[100010];

bool compare(pair<ll,pair<ll,ll>> a,pair<ll,pair<ll,ll>> b){
	return a.second.second < b.second.second;
}

int main(){
	for(int i =0;i < 3;i++){
		int x,y,z;
		cin>>x>>y>>z;
		p[i].first = x;p[i].second.first = y;p[i].second.second = z;
	}
	sort(p,p+3,compare);

	for(int i = 0;i < 3;i++){
		cout<<p[i].first<<" "<<p[i].second.first<<" "<<p[i].second.second<<endl;
	}
}