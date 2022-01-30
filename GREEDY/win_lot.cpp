#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

string fun(int m,int s){
	int res[m];

	s -= 1;
	for(int i = m - 1;i > 0;i--){
		if(s > 9){
			res[i] = 9;
			s -= 9;
		}else{
			res[i] = s;
			s = 0;
		}
	}
	res[0] = s + 1;
	string e = "";
	for(int i = 0;i < m;i++){
		e = e + char('0' + res[i]);
	}
	return e;
}

int main(){
	int s,m;
	cin>>s>>m;
	cout<<fun(m,s)<<endl;	
}