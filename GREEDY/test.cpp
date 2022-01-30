#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

struct abc{
	int a,b;
};

bool compare(abc x,abc y){
	return x.b < y.b;
}

int main(){
	int n;
	cin>>n;
	abc a[n];
	for(int i = 0;i < n;i++){
		cin>>a[i].a>>a[i].b;
	}
	sort(a,a+n,compare);

	for(int i = 0;i < n;i++){
		cout<<a[i].a<<" "<<a[i].b<<endl;
	}
	int x = lower_bound(a,a+n,4) - a;
	cout<<x<<endl;
}