#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#include<string>
#include<bits/stdc++.h>


char A[55],B[55],C[55];
int dp[55][55][55],mod=1000000007;
int solver(int x,int y,int z)
{
	if(z==0)
		return 1;
	if(x<=0&&y<=0)
		return 0;
	if(dp[x][y][z]!=-1)
		return dp[x][y][z];
	int ways=0;    
	
	for(int i=x-1;i>=0;i--)
	{
		if(A[i]==C[z-1])
		{
			ways=(ways+solver(i,y,z-1))%mod;
		}
	}
	for(int i=y-1;i>=0;i--)
	{
		if(B[i]==C[z-1])
		{
			ways=(ways+solver(x,i,z-1))%mod;
		}
	}
	
	return dp[x][y][z]=ways;
}





int solve(string a,string b,string c)
{
	// Write your code here .
	for(int i=0;i<55;i++)
		for(int j=0;j<55;j++)
			for(int k=0;k<55;k++)
				
				
				dp[i][j][k]=-1;
			for(int i=0;a[i];i++)
				A[i]=a[i];
			for(int i=0;b[i];i++)
				B[i]=b[i];
			for(int i=0;c[i];i++)
				C[i]=c[i];
			
	return solver(a.length(),b.length(),c.length());
			
}



int main()
{
	string a,b,c;
	cin>>a>>b>>c;
	cout<<solve(a,b,c)<<endl;
}