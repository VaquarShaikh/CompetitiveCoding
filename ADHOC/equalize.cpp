#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	string t;
	cin>>t;
	int count = 0;
	for(int i=0;i < n;){
		if(s[i] != t[i]){
			//either swap or flip
			if(i+1 < n && s[i] != s[i+1] && s[i+1] != t[i+1]){
				i += 2;
			}else{
				i++;
			}
			count++;
		}else{
			i++;
		}
	}
	cout<<count<<endl;
}