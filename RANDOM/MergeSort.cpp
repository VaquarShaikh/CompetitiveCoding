#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

void mergeSort(vector<int>& v,int l = 0,){
	int mid = (l+r)/2;
	if(l < r){
		mergeSort(v)
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> v;
	for(int i = 0;i < n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}	

	mergeSort(v);
	for(int i = 0;i < v.size();i++){
		cout<<v[i]<<" ";
	}cout<<endl;
}
