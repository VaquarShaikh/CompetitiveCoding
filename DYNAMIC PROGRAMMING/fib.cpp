#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;

// int fib(int n){
// 	if(n == 1 || n == 0){
// 		return n;
// 	}
// 	return fib(n-1) + fib(n-2);  
// }

// int fib2helper(int arr[],int n){
// 	if(n == 1 || n == 0){
// 		return n;
// 	}
// 	if(arr[n] != -1){
// 		return arr[n];
// 	}
// 	int output = fib2helper(arr,n-1) + fib2helper(arr,n-2);
// 	arr[n] = output;
// 	return output;
// }

// int fib2(int n){
// 	int arr[n+1];
// 	memset(arr,-1,(n+1)*sizeof(int));
// 	return fib2helper(arr,n);
// }

int fib3(int n){
	int arr[n+1];
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2;i <= n;i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	return arr[n];
}

int main(){
	int n;
	cin>>n;
	// cout<<fib(n)<<endl;
	// cout<<fib2(n)<<endl;
	cout<<fib3(n)<<endl;
}