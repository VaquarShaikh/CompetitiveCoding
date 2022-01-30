#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

bool isMatch(string s,string p){
	int n = s.length();
	int m = p.length();

	for(int i = 0;i <= (n - m);i++){
		bool isFound = true;
		for(int j = 0;j < m;j++){
			if(s[i + j] != p[j]){
				isFound = false;
				break;
			}
		}
		if(isFound == true){
			return true;
		}
	}
	return false;
}

int main(){
	string s,p;
	cin>>s>>p;

	cout<<isMatch(s,p)<<endl;	
}