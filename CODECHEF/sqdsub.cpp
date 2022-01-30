#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
			ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++)
			cin>>a[i];

		ll b[n];
		for(ll i=0;i<n;i++)
		{
			if(a[i]%4 == 0)
			    b[i] = 2;
			else if(a[i]%2 == 0)
			    b[i] = 1;
			else
			    b[i] = 0;
		}
		ll pre[n];
		pre[0] = b[0];
		for(ll i=1;i<n;i++)
			pre[i] = pre[i-1] + b[i];

		ll ans=0;
		for(ll i=0;i<n;i++)
		{
			if(b[i] == 0)
			{
			    ll idx=upper_bound(pre,pre+n,pre[i])-pre;
			    ans += idx-i;

			    idx=lower_bound(pre,pre+n,pre[i]+2)-pre;
			    ans += n-idx;
			}
			else if(b[i] == 1)
			{
			    ll idx=lower_bound(pre,pre+n,pre[i]+1)-pre;
			    ans += n-idx;
			}
			else
			{
			    ans += n-i;
			}
		}
	    	cout<<ans<<"\n";
	}
		return 