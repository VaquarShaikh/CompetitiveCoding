#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

class job{
public:
	int start;
	int end;
	int profit;
};

bool compare(job a,job b){
	return a.end < b.end;
}

int main(){
	int n;
	cin>>n;
	job* arr = new job[n];

	for(int i = 0;i < n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		arr[i].start = a;
		arr[i].end = b;
		arr[i].profit = c; 
	}

	sort(arr,arr + n,compare);
	int* dp = new int[n];
	dp[0] = arr[0].profit;

	for(int i = 1;i < n;i++){
		// dp[i] = dp[i-1];
		int l = 0,r = i+1,ans = -1,res = arr[i].profit;
        int num = arr[i].start;
		while(l <= r){
			int mid = (r + l)/2;
			if(arr[mid].end <= num)
            {
				ans = mid;
				l = mid + 1;
			}
            else{
				r = mid - 1;
			}
		}
        if(ans!=-1)
            res += dp[ans];
		dp[i] = max(dp[i - 1] , res);

	}
	cout<<dp[n-1]<<endl;
	delete [] dp;
	delete [] arr;
}