#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

void merge(vector<int>& v1,vector<int>& v2,vector<int>& ans){
	int i = 0, j = 0;
	while(i < v1.size() && j < v2.size()){
		if(v1[i] < v2[j]){
			ans.push_back(v1[i++]);
		}else{
			ans.push_back(v2[j++]);
		}
	}
	while(i < v1.size()){
		ans.push_back(v1[i++]);
	}
	while(j < v2.size()){
		ans.push_back(v2[j++]);
	}
}

int main(){
	int size1,size2;
	cin>>size1;

	vector<int> v1;
	for(int i = 0;i < size1;i++){
		int temp;
		cin>>temp;
		v1.push_back(temp);
	}
	cin>>size2;
	vector<int> v2;
	for(int i = 0;i < size2;i++){
		int temp;
		cin>>temp;
		v2.push_back(temp);
	}
	int r = size2 + size1;
	vector<int> ans;
	merge(v1,v2,ans);
	for(int i = 0;i < r;i++){
		cout<<ans[i]<<" ";
	}cout<<endl;
}