#include <bits/stdc++.h>
using namespace std;
typedef long long l;
l lcs(char*s1,char*s2,int ***dp,int m,int n,int k)
{
    if(m==0||n==0)
    {
        return 0;

    }
    if(k==0)
    {
        return 0;
    }
    if(dp[m][n][k]!=-1)
        return dp[m][n][k];
    l ans;
    if(s1[0]==s2[0])
    {
        l a=s1[0]+lcs(s1+1,s2+1,dp,m-1,n-1,k-1); 
        l b=lcs(s1+1,s2,dp,m-1,n,k);
        l c=lcs(s1,s2+1,dp,m,n-1,k);
        if(a==s1[0]&&k!=1){
            a=0;
        }
        ans=max(a,max(b,c));


    }
    else{
        l x=lcs(s1+1,s2,dp,m-1,n,k);
        l y=lcs(s1,s2+1,dp,m,n-1,k);
        ans=max(x,y);
    }
    dp[m][n][k]=ans;
    return ans;
}
int main()
{
    int  t;
    cin>>t;
    while(t--)
    {
        char ch1[100];
        char ch2[100];
        cin>>ch1>>ch2;
        int k;
        cin>>k;
        int  m=strlen(ch1);
        int n=strlen(ch2);
        int ***dp=new int **[m+1];

        for(int i=0;i<=m;i++){
            dp[i]=new int*[n+1];
            for(int j=0;j<=n;j++)
                dp[i][j] = new int [k+1];
        }


        for(int h=0;h<=m;h++){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=k;j++){
                    dp[h][i][j] = -1;
                }
            }
        }
        cout<<lcs(ch1,ch2,dp,m,n,k)<<"\n";   
    }
    return 0;
}