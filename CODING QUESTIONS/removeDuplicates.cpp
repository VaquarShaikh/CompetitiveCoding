#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

int removeDuplicates(vector<int> &arr, int n){
	int count = 0 , i = 0 , j = 1;
	while(i < n && j < n){
		if(arr.at(i) == arr.at(j)){
			count++;
			j++;
		}else{
			i = j;
			j++;
		}
	}	
	// cout<<arr.size()<<" "<<count<<endl;
	int res = arr.size() - count;
	return res;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> arr;
		for(int i = 0;i < n;i++){
			int temp;
			cin>>temp;
			arr.pb(temp);
		}
		cout<<removeDuplicates(arr , n);
	}	
}