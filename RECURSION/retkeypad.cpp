#include<bits/stdc++.h>
using namespace std;

int keypad(int num,string output[]){
	if(num == 0){
		output[0] = "";
		return 1;
	}
	string smalloutput[5000];
	string options[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	int small = num/10;
	string a = options[num%10];
	int len = a.length();
	int smallsize = keypad(small,smalloutput);
	int m = 0;
	for(int i = 0;i < len;i++){
		for(int j = 0;j < smallsize;j++){
			output[m++] = smalloutput[j] + a[i];
		}
	}
	return m;
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
