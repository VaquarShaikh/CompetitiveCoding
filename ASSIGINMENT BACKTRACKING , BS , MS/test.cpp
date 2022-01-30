#include<bits/stdc++.h>
using namespace std;

bool check(int arr[],int n){
	return is_sorted(arr,arr+n);
}
int main(){
	int arr[] = {1,2,3,4,5,6};
	int arr1[] = {6,4,5,2,1};
	cout<<check(arr,6)<<endl;
	cout<<check(arr1,5)<<endl;
}