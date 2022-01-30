#include<bits/stdc++.h>
using namespace std;

string options[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void printKeypad(int num,string output = ""){
	if(num == 0){
		cout<<output<<endl;
		return;
	}
	string last = options[num%10];
	for(int i = 0;i < last.length();i++){
		printKeypad(num/10,last[i] + output);
	}
}

int main(){
	int n;
	cin>>n;
	printKeypad(n);
}