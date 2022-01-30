#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n,x,y;
	cin>>n>>x>>y;
	string s;
	cin>>s;
	int count = 0;
	if(s[0] == '0'){
		count++;
	}
	for(int i = 0;i < n;i++){
		if(s[i+1] == '0' && s[i] == '1'){
			count++;
		}
	}
    if(count == 0){
        cout<<0<<endl;
    }else{
        cout<<((count-1)*min(x,y) + y)<<endl;
    }
}