#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main(){
	vector<int> arr;
	vector<int> arr1;
	while(1){
		int temp,temp1;
		cin>>temp>>temp1;
		arr.push_back(temp);
		arr1.push_back(temp1);
		if(temp == 0 && temp1 == 0){
			break;
		}
	}
	for(int i = 0,j = 0;i < arr.size() , j < arr1.size();i++,j++){
		cout<<arr[i]<<" "<<arr1[i]<<endl;
	}cout<<endl<<endl;
}