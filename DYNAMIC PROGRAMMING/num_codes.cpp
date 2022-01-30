#include<bits/stdc++.h>
using namespace std;

int num_codes_i(int * input, int size) {
	int* output = new int[size + 1];
	output[0] = 1;
	output[1] = 1;

	for (int i = 2; i <= size; i++) {
		output[i] = output[i - 1];
		if (input[i-2] *10 + input[i - 1] <= 26) {
			output[i] += output[i - 2];
		}
	}
	int ans = output[size];
	delete [] output;
	return ans;
}


int main(){
	string s;
	cin>>s;
	int len = s.length();
	int k = 0;
	int arr[len];
	for(int i = 0;i < len;i++){
		arr[k++] = s[i] - '0';
	}
	for(int i = 0;i < len;i++){
		cout<<arr[i];
	}cout<<endl;
	cout<<num_codes_i(arr,len)<<endl;
}
