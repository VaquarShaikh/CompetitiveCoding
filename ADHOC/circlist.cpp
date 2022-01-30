#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int i,p;
		cin>>i>>p;
		if((i + p) < 12){
			cout<<(i+p)<<endl;
		}else{
			cout<<(i + p - 12)<<endl;
		}
	}
}