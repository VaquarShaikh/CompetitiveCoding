#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	if(n & n-1){
		cout<<"not a power of 2"<<endl;
	}else{
		cout<<"power of 2"<<endl;
	}
}