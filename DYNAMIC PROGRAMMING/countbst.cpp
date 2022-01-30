#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

long int countBST(int n) 
{ 
    long int dp[n+1]; 
    dp[0] = dp[1] = 1; 
    for (long int i=2; i<=n; i++) 
    { 
        dp[i] = 0; 
        for (long int j=0; j<i; j++) 
            dp[i] = (dp[i]%mod + (dp[j]*dp[i-j-1])%mod)%mod; 
    } 
    return dp[n]%mod; 
} 

int main(){
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;	
}