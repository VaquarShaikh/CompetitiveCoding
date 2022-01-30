#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

void update(int index,int val,int* BIT,int n){

	for(;index <= n;index += index&(-index)){
		BIT[index] += val;
	}
}

int query(int index,int* BIT){
	int sum = 0;
	for(;index > 0;index -= index&(-index)){
		sum += BIT[index];
	}
	return sum;
}

int main(){
	int n;
	cin>>n;

	int* arr = new int[n+1]();
	int* BIT = new int[n+1]();

	for(int i = 1;i <= n;i++){
		cin>>arr[i];
		update(i,arr[i],BIT,n);
	}

	cout<<"sum of 5 elements is : "<<query(5,BIT)<<endl;
	cout<<"sum of elements from 2 to 5 is : "<<query(5,BIT) - query(1,BIT)<<endl;
}