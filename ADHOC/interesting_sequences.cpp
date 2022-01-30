#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k,l;
	cin>>n>>k>>l;
	int arr[n];
	for(int i = 0;i < n;i++){
		cin>>arr[i];
	}	
	int min = *min_element(arr,arr+n);
	int max = *max_element(arr,arr+n);
	int inc = 0,dec = 0;
	int ans = INT_MAX;
	for(int i = min;i <= max;i++){
		for(int j = 0;j < n;j++){
			if(arr[j] < i){
				inc += (i - arr[j]);
			}else if(arr[j] > i){
				dec += (arr[j] - i);
			}
		}
		if(inc >= dec){
			int res = dec*k + (inc - dec)*l;
			if(ans > res){
				ans = res;
			}
			inc = 0;
			dec = 0;
		}else{
			inc = 0;
			dec = 0;
		}
	}
	cout<<ans<<endl;
}