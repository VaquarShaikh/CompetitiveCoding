#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

// int salary(int* as,int n,int x,int* cap){
// 	if(x == 0){
// 		return as[0] + salary(as + 1,n - 1,1,cap + 1);
// 	}
// 	if(x == n){
// 		return cap[0] + salary(as + 1,n - 1,x - 1,cap + 1);
// 	}else{
// 		int op1 = as[0] + salary(as + 1,n - 1,x + 1,cap + 1);
// 		int op2 = cap[0] + salary(as + 1,n - 1,x - 1,cap + 1);
// 		return min(op1,op2);
// 	}
// }

int salary(int* as,int n,int x,int* cap,int** output){
    if(n<0)
    {
        return 0;
    }
    if(n == 0){
        return 0;
    }
	
    if(x == 0){
		return as[0] + salary(as + 1,n - 1,1,cap + 1,output);
	}
    if(output[n][x] > 0){
		return output[n][x];
    
	}
    int ans;
	if(x == n){
		ans = cap[0] + salary(as + 1,n - 1,x - 1,cap + 1,output);
	}else{
		int op1 = as[0] + salary(as + 1,n - 1,x + 1,cap + 1,output);
		int op2 = cap[0] + salary(as + 1,n - 1,x - 1,cap + 1,output);
		ans = min(op1,op2);
	}
	output[n][x] = ans;
	return ans;
}

int main(){
	int n;
	cin>>n;
	int* as = new int[n];
	int* cap= new int[n];

	for(int i = 0;i < n;i++){
		cin>>cap[i]>>as[i];
	}	
	int** output = new int*[n+1];
	for(int i = 0;i <= n;i++){
		output[i] = new int[n + 1];
		for(int j = 0;j <= n;j++){
			output[i][j] = 0;
		}
	}
	cout<<salary(as,n,0,cap,output)<<endl;
}