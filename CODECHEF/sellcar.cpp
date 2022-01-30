#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,price[100000],res = 0;
		cin>>n;
		for(ll i=0;i<n;i++)
		{
			cin>>price[i];
		}
		sort(price,price+n,greater<int>());
		int mod = pow(10,9)+7;
		for(int i=0;i<n;)
		{
			price[i]=price[i]-i;
			if(price[i]<0)
				break;
			else{                    
				res += price[i];
				i++;
			}
		}
		cout<<res%mod<<endl;            

	}

}