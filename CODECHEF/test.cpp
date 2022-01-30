#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[] = {6,7,8,9,10};
	sort(arr,arr+5,greater<int>());
	for(int i = 0;i < 5;i++){
		cout<<arr[i]<<" ";
	}
}