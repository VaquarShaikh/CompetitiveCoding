#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double X[n];
    double Y[n];
    double F[n];
    for(int i=0;i<n;i++)
    {
        cin>>X[i]>>Y[i]>>F[i];
    }
    double dp[n];
    dp[0] = F[0];
    for(int i=1;i<n;i++)
    {
        double temp=-999999999.000;
        for(int j=0;j<i;j++)
        {
            temp = max(dp[j]+F[i] - (sqrt((X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j])))  ,  temp);
        }
        dp[i]  =  temp;
    }
    double ans=dp[n-1];
    cout<<fixed<<setprecision(6)<<ans;
    return 0;
}