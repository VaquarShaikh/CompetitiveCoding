#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

#define MAXN 2000005

int lpd[MAXN];
bool marked[MAXN];
vector<int> v;

int main(){
	int n;
	cin>>n;

	memset(marked,false,sizeof(marked));
	for(int i = 1;i <= n;i++){
		lpd[i] = i;
	}

	for(int i = 2;i <= n;i++){
		if(lpd[i] == i){
			for(int j = 2*i;j <= n;j += i){
				lpd[j] = i;
			}
		}
	}
	int d;
	for(int i = n;i >= 1;i--){
		if(marked[i] == true){
			continue;
		}
		int x = n;
		while(x != 1 || x != 0){
			d = lpd[x];
			marked[x] = true;
			v.pb(x);
			x = x - d;
		}

		int temp = n/x;
		for(int i = x;i*i <= temp;i++){
			if(temp%i == 0){
				temp = temp/x;
			}else{
				break;
			}
		}
		d = temp;
	}
}	