#include<iostream>
#include<bitset>
using namespace std;

int turnOffFirstSetBit(int n){
	return n^(n & (-1*n));	
}

int main() {
	int n;

	cin >> n;
	
	cout<< turnOffFirstSetBit(n) <<endl;
		
	return 0;
}
