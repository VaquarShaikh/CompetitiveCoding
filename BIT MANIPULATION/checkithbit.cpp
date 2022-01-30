#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,i;
	cin>>n>>i;
	int z = n & (1 << i);
	(z==0)?cout<<"false":cout<<"true"<<endl;
}