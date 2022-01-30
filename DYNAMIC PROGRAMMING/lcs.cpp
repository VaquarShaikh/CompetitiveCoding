#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

int lcs(string s1 , string s2){
	if(s1.size() == 0 || s2.size() == 0){
		return 0;
	}
	if(s1[0] == s2[0]){
		return 1 + lcs(s1.substr(1),s2.substr(1));
	}else{
		int option1 = lcs(s1,s2.substr(1));
		int option2 = lcs(s1.substr(1),s2);
		return max(option1,option2);
	}
}

int lcs_memo_helper(string s1 , string s2 , int m, int n,int** output){
	//base case 
	if(m == 0||n==0){
		return 0;
	}
	//memoization condition.
	if(output[m][n] != -1){
		return output[m][n];
	}
	//main code (another base case)
	int ans;
	if(s1[0] == s2[0]){
		return 1 + lcs_memo_helper(s1.substr(1) , s2.substr(1),m-1,n-1,output);
	}
	else{
		int option1 = lcs_memo_helper(s1.substr(1) , s2 , m-1,n,output);
		int option2 = lcs_memo_helper(s1 , s2.substr(1) , m,n-1,output);
		ans = max(option1 , option2);
	}
	return output[m][n] = ans;
}

int lcs_memo(string s1 , string s2){
	int m = s1.length();
	int n = s2.length();

	int** output = new int*[m+1];
	for(int i = 0;i <= m;i++){
		output[i] = new int[n+1];
		for(int j = 0;j <= n;j++){
			output[i][j] = -1;
		}
	}

	return lcs_memo_helper(s1,s2,m,n,output);
}

int lcs_dp(string s1 , string s2){
	int m = s1.length();
	int n = s2.length();
	int** output = new int* [m+1];
	for(int i = 0;i <= m;i++){
		output[i] = new int[n+1];
		for(int j = 0;j <= n;j++){
			output[i][j] = -1;
		}
	}

	for(int i = 0;i <= m;i++){
		output[i][0] = 0;
	}
	for(int i = 0;i <= n;i++){
		output[0][i] = 0;
	}

	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++){
			//first condition 	
			if(s1[i-1] == s2[j-1]){
				output[i][j] = 1 + output[i-1][j-1];
			}
			//second condition 
			else{
				output[i][j] = max(output[i-1][j],output[i][j - 1]);
			}
		}
	}
	int ans = output[m][n];
	for(int i = 0;i <= m ;i++){
		delete output[i];
	}
	delete [] output;
	return ans;
}

int main(){
	string s1 = "abcdef" , s2 = "acdefgh";
	string s3 = "xyz" ,  s4 = "dls";
	cout<<lcs(s1,s2)<<" "<<lcs_memo(s1,s2)<<" "<<lcs_dp(s1,s2)<<endl;
	cout<<lcs(s2,s3)<<" "<<lcs_memo(s2,s3)<<" "<<lcs_dp(s2,s3)<<endl;
}