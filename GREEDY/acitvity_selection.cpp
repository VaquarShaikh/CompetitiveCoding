#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

typedef long long ll;

bool compare(pair<ll,ll> a,pair<ll,ll> b){
	return a.second <= b.second;
}

int main(){
	int n;
	cin>>n;
	pair<ll,ll> arr[n];			//first = start , second = end;

	for(int i = 0;i < n;i++){
		cin>>arr[i].first>>arr[i].second;
	}

	int i = 0,count = 1;

	sort(arr,arr+n,compare);

	for(int j = 1;j < n;j++){
		if(arr[j].first >= arr[i].second){
			count++;
			i = j;
		}
	}
	cout<<count<<endl;
}