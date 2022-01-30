#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i < n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	ll sum = 0;
	for(int i = 0;i < n;i++){
		ll prod = arr[n-i-1]*(ll)pow(2,i);
		sum += prod;
	}
	cout<<sum<<endl;
}