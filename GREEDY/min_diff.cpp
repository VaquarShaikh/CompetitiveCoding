#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main(){
	int n;
	cin>>n;
	int* arr = new int[n];
	for(int i = 0;i < n;i++){
		cin>>arr[i];
	}	
	sort(arr,arr+n);
	int res = INT_MAX;
	for(int i = 1;i < n;i++){
		int diff = abs(arr[i] - arr[i-1]);
		if(res > diff){
			res = diff;
		}
	}
	cout<<res<<endl;
	delete [] arr;
}