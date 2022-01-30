#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define MAXN 1000100
typedef long long ll;

ll cubes[MAXN];

int main(){
	memset(cubes,0,sizeof(cubes));
	ll k = 1;
	cubes[1] = 1;
	for(ll i = 2;i <= 100;i++){
		if(cubes[i] == 0){
			ll c = i*i*i;
			for(ll j = c; j < MAXN;j += c){
				cubes[j] = -1;
			}
		}
	}	
    for(ll i = 1;i < 1000100;i++){
        if(cubes[i] == 0){
            cubes[i] = k+1;
            k++;
        }
    }
	ll t;
	cin>>t;
	for(ll cc = 0;cc < t;cc++){
		ll temp;
		cin>>temp;
		if(cubes[temp] != -1){
			cout<<"Case "<<cc+1<<": "<<cubes[temp]<<endl;
		}else{
			cout<<"Case "<<cc+1<<": "<<"Not Cube Free"<<endl;
		}
	}
}