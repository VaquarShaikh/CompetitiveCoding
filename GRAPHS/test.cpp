#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second


int main(){
	int n;
	cin>>n;
	vector<vector<int>> v;
	int count = 1;
	for(int i = 0;i < n;i++){
		vector<int> temp;
		rep(j,0,n)
		temp.pb(count++);
		v.pb(temp);
	}	
	rep(i,0,n){
		rep(j,0,n){
			cout<<v[i][j]<<" ";
		}cout<<endl;
	}
}