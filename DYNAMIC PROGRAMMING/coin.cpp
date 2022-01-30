#include<bits/stdc++.h>
using namespace std;

/*int countWaysToMakeChangehelper(int d[], int numD, int n,int** output){
	if(n < 0){
		return 0;
	}
	if(n == 0){
		return 1;
	}	
	if(numD == 0){
		return 0;
	}
	if(output[n][numD] > -1){
		return output[n][numD];
	}
	int res = countWaysToMakeChangehelper(d,numD,n-d[0],output) + countWaysToMakeChangehelper(d + 1,numD - 1,n,output);
	output[n][numD] = res;
	return res;
}

int countWaysToMakeChange(int d[], int numD, int n){
	int** output = new int*[n+1];
	for(int i = 0;i <= n;i++){
		output[i] = new int[numD + 1];
		for(int j = 0;j <= numD;j++){
			output[i][j] = -1;
		}
	}
	return countWaysToMakeChangehelper(d,numD,n,output);
}
*/

int countWaysToMakeChange(int d[],int numD,int n){
	int output[n+1][numD+1];
	
}

int main(){
	int numD;
	cin >> numD;
	int* denominations = new int[numD];
	for(int i = 0; i < numD; i++){
		cin >> denominations[i];
	}
	int n;
	cin >> n;
	cout << countWaysToMakeChange(denominations, numD, n);
	/*int d[2] = {1,2};
	cout<<countWaysToMakeChange(d,2,4)<<endl;*/
}

