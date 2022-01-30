#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll staircase(int n){
	ll output[n+1];
	output[0] = 1;
	output[1] = 1;
	output[2] = 2;
	for(int i = 3;i <= n;i++){
		output[i] = output[i-1] + output[i-2] + output[i-3];
	}
	return output[n];
}

int main(){
	int n; 
	cin >> n ;
	cout << staircase(n) << endl;
}