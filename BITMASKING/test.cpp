#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

class coder{
public:
	int x,y,index;
};

bool compare(coder a,coder b){
	if(a.x == b.x){
		return a.y < b.y;
	}
	return a.x < b.x;
}

void update(int y,int* BIT){
	for(;y <= 100000;y += (y&(-y))){
		BIT[y]++;
	}
}

int query(int y,int* BIT){
	int count = 0;
	for(;y > 0;y -= (y&(-y))){
		count += BIT[y];
	}
	return count;
}

int main(){
	int n;
	cin>>n;

	coder* arr = new coder[n];

	for(int i = 0;i < n;i++){
		cin>>arr[i].x>>arr[i].y;
		arr[i].index = i;
	}

	sort(arr,arr + n,compare);
	cout<<endl<<endl;
	cout<<"array in sorted order\n";
	for(int i = 0;i < n;i++){
		cout<<arr[i].x<<" "<<arr[i].y<<" "<<arr[i].index<<endl;
	}

	cout<<endl<<endl;

	int* BIT = new int[100001]();
	int* ans = new int[n]();

	for(int i = 0;i < n;){
		int ei = i;

		while(ei < n && arr[i].x == arr[ei].x && arr[i].y == arr[ei].y){
			ei++;
		}

		//query
		for(int j = i;j < ei;j++){
			ans[arr[j].index] = query(arr[j].y,BIT);
		}


		//update
		for(int j = i;j < ei;j++){
			update(arr[j].y,BIT);
		}

		i = ei;		
	}
	cout<<"bit array\n";
	for(int i = 1;i <= n;i++){
		cout<<BIT[i]<<" ";
	}

	cout<<endl<<endl;


	cout<<"answer array\n";
	for(int i = 0;i < n;i++){
		cout<<ans[i]<<endl;
	}

	cout<<endl<<endl;
}