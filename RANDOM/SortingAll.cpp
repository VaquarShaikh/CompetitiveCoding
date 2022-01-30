#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second


void bubbleSort(vector<int>& v){
	for(int i = 0;i < v.size();i++){
		for(int j = i+1;j < v.size();j++){
			if(v[j] < v[i]){
				swap(v[i] , v[j]);
			}
		}
	}
}

void selectionSort(vector<int>& v){
	for(int i = 0;i < v.size() - 1;i++){
		int minIn = i;
		for(int j = i+1;j < v.size();j++){
			if(v[j] < v[minIn]){
				minIn = j;
			}
		}
		swap(v[i],v[minIn]);
	}
}

void insertionSort(vector<int>& v){
	int j;
	for(int i = 0;i < v.size();i++){
		int key = v[i];
		j = i - 1;
		while(j >= 0 && v[j] > key){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = key;
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> v;
	rep(i,0,n){
		int temp;
		cin>>temp;
		v.pb(temp);
	}

	// bubbleSort(v);
	// selectionSort(v);
	insertionSort(v);

	rep(i,0,v.size())
	cout<<v[i]<<" ";
}