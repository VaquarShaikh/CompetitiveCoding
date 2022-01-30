#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int editDistance_recursive(string s1,string s2){
	if(s1.empty() || s2.empty()){
		if(s1.empty()){
			return s2.length();
		}if(s2.empty()){
			return s1.length();
		}
	}
	if(s1[0] == s2[0]){
		return editDistance(s1.substr(1),s2.substr(1));
	}else{
		int op1 = 1 + editDistance(s1.substr(1),s2);
		int op2 = 1 + editDistance(s1.substr(1),s2.substr(1));
		int op3 = 1 + editDistance(s1,s2.substr(1));
		return min(op1,min(op2,op3));
	}
}

int editDistance2helper(string s1,string s2,int m,int n,int** output){
	if(s1.empty() || s2.empty()){
		if(s1.empty()){
			return s2.length();
		}if(s2.empty()){
			return s1.length();
		}
	}
	if(output[m][n] > -1){
		return output[m][n];
	}int ans;
	if(s1[0] == s2[0]){
		ans = editDistance2helper(s1.substr(1),s2.substr(1),m-1,n-1,output);
	}else{
		int op1 = 1 + editDistance2helper(s1.substr(1),s2,m-1,n,output);
		int op2 = 1 + editDistance2helper(s1.substr(1),s2.substr(1),m-1,n-1,output);
		int op3 = 1 + editDistance2helper(s1,s2.substr(1),m,n-1,output);
		ans = min(op1,min(op2,op3));
	}
	output[m][n] = ans;
	return ans;
}

int editDistance2(string s1,string s2){
	int m = s1.length();
	int n = s2.length();
	int** output = new int*[m+1];
	for(int i = 0;i <= m;i++){
		output[i] = new int[n+1];
		for(int j = 0;j <= n;j++){
			output[i][j] = -1;
		}
	}
	return editDistance2helper(s1,s2,m,n,output);
}

int editDistance(string s1,string s2){
	int m = s1.length();
	int n = s2.length();
	int output[m+1][n+1];
	for(int i = 0;i <= m;i++){
		output[i][0] = i;
	}
	for(int j = 0;j <= n;j++){
		output[0][j] = j;
	}
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++){
			if(s1[m-i] == s2[n-j]){
				output[i][j] = output[i-1][j-1];
			}else{
				int op1 = output[i-1][j] + 1;
				int op2 = output[i][j-1] + 1;
				int op3 = output[i-1][j-1] + 1;
				output[i][j] = min(op1,min(op2,op3));
			}
		}
	}
	return output[m][n];
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<editDistance(s1,s2)<<endl;	
}