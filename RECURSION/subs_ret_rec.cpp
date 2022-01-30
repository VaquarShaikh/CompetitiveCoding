#include<iostream>
using namespace std;

int retsub(string input,string output[]){
	if(input.empty()){
		output[0] = "";
		return 1;
	}
	string small = input.substr(1);
	int small_size = retsub(small,output);
	for(int i = 0;i < small_size;i++){
		output[i+small_size] = input[0] + output[i];
	}
	return 2*small_size;
}

int main(){
	string s;
	cin>>s;
	string* output = new string[1000];
	int count = retsub(s,output);
	for(int i = 0;i < count;i++){
		cout<<output[i]<<endl;
	}
	delete [] output;
}