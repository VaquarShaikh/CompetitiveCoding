#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define MAXN 750010

int ans[MAXN];

int main(){
	int t;
	cin>>t;
	while(t--){
		int sum = 0;
		memset(ans,0,MAXN);
		int n;
		cin>>n;
		rep(i,0,n){
			int temp;
			cin>>temp;
			ans[temp] = 1;
		}
		for(int i = 1;i < MAXN;i++){
			if(ans[i] > 0){
				for(int j = 2*i;j < MAXN;j += i){
					if(ans[j] > 0){
						ans[j] = (ans[j]%mod + ans[i]%mod)%mod;						
					}
				}
			}
		}
		for(int i = 1;i < MAXN;i++){
			if(ans[i] > 0){
				sum = (sum%mod + ans[i]%mod)%mod;
			}
		}
		cout<<sum<<endl;
	}
}