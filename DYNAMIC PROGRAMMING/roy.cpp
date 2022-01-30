#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main(){
	int n,m;
	cin>>n;
	cin>>m;
	int s[n+1] ;
	int e[n+1] ;
    for(int i=0;i<n+1;i++)
    {
        s[i] = 0;
        e[i] = 0;
    }
	for(int i = 0;i < m;i++){
		int l,r;
		cin>>l>>r;
		s[l]++;
		e[r]++;
	}
	int dp[n+1];
    dp[0] = 0;
//	dp[1] = 1;
	for(int i = 1;i <= n;i++){
		dp[i] = dp[i-1] + (s[i] - e[i-1]);
	}
	int exact[n+1] ;
    for(int i=0;i<n+1;i++)exact[i]=0;
    
	for(int i = 0;i <= n;i++){
		exact[dp[i]]++;
	}
    
	// int atleast[n+1] = {0};
	// atleast[n] = exact[n];
	// atleast[0] = n;
	for(int i = n-1;i >= 1;i--){
		exact[i] = (exact[i] + exact[i+1]);
	}
    
	int q;
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		int res = exact[x];
		cout<<res<<endl;
	}
}