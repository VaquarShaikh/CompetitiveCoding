#include <bits/stdc++.h>
using namespace std;

int main()
{
    while(1)
    {
        int W,n;
        cin>>W>>n;
        if(W == 0 && n == 0)
            break;
        int weight[n],value[n];
        for(int i=0;i<n;i++)
        {
            cin >>weight[i]>>value[i];
        }

        int dp[W+1]={0};
        for(int i=0;i<n;i++){
            for(int j=W;j>=weight[i];j--){       
                dp[j]=max(dp[j],value[i]+dp[j-weight[i]]);
            }
        }
        int ans = dp[W];
        int index = lower_bound(dp,dp+W,ans) - dp;
        cout<<index<<" "<<ans<<endl;

    }
}