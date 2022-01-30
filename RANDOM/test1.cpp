#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

void merge(int*a1,int size1,int* a2,int size2,int* ans){
	int i = 0,j = 0,k = 0;
	while(i < size1 && j < size2){
		if(a1[i] < a2[j]){
			ans[k++] = a1[i++];
		}else{
			ans[k++] = a2[j++];
		}
	}
	while(i < size1){
		ans[k++] = a1[i++];
	}
	while(j < size2){
		ans[k++] = a2[j++];
	}
}

int main(){
	int size1,size2;
	cin>>size1;
	int* a1 = new int[size1];
	for(int i = 0;i < size1;i++){
		cin>>a1[i];
	}	
	// int size2;
	cin>>size2;
	int* a2 = new int[size2];
	for(int i = 0;i < size2;i++){
		cin>>a2[i];
	}	
	int* ans = new int[size1 + size2];
	merge(a1,size1,a2,size2,ans);

	for(int i = 0;i < size1 + size2;i++){
		cout<<ans[i]<<" ";
	}
}