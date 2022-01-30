#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

void buildz(int* z,string str){
	int l = 0,r = 0;
	int n = str.length();

	for(int i = 1;i < n;i++){
		if(i > r){
			//z does not exist.
			l = i;
			r = i;
			while(r < n && str[r - l] == str[r]){
				r++;
			}
			z[i] = r - l;
			r--;
		}else{
			int k = i - l;
			if(z[k] <= r-i){
				//exist already.
				z[i] = z[k];
			}else{
				l = i;
				while(r < n && str[r-l] == str[r]){
					r++;
				}
				z[i] = r - l;
				r--;
			}
		}
	}
}

void stringsearch(string text,string pattern){
	string str = pattern + "$" + text;

	int n = str.length();
	int*z = new int[n]();
	buildz(z,str);
	for(int i = 0;i < n;i++){
		if(z[i] == pattern.length()){
			cout<<i-pattern.length()-1<<endl;
		}
	}
}

int main(){
	string text ,pattern;
	cin>>text>>pattern;

	stringsearch(text,pattern);
}
