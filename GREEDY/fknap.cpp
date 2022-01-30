#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

struct Item{
	int value , weight;
};

bool compare(struct Item a,struct Item b){
	double v1 = ((double)a.value/a.weight);
	double v2 = ((double)b.value/b.weight);

	return v1 > v2;
}

double fknap(Item arr[],int w,int n){
	sort(arr,arr+n,compare);
	for(int i = 0;i < n;i++){
		cout<<arr[i].value<<" "<<arr[i].weight<<endl;
	}
	int currw = 0;
	double fval = 0;

	for(int i = 0;i < n;i++){
		if(currw + arr[i].weight <= w){
			currw += arr[i].weight;  
			fval += arr[i].value;
		}else{
			int rweight = w - currw;
			fval += arr[i].value*((double)rweight/arr[i].weight);
		}
	}
	return fval;
}

// int fknap()

int main(){
	int W = 70;
	struct Item arr[] = {{60,20},{70,15},{80,40}};
	cout<<fknap(arr,W,3)<<endl;
}