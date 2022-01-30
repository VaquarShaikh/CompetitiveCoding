#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main(){
	int n,k,x;
	cin>>n>>k>>x;
	int freq[1024] = {0};
	for(int i = 0;i < n;i++){
		int val;
		cin>>val;
		freq[val]++;
	}
	
	int ans[1024] = {0}; 
	int count = 0;
	for(int i = 0;i < k;i++){
		for(int j = 0;j <= 1023;j++){
		
				if(freq[j] > 0){
					int tres = j ^ x;
					if(freq[j]%2 == 0){
						int amt = freq[j]/2;
						ans[j] += (freq[j] - amt);
						ans[tres] += amt;
						count += freq[j];
					}else{
						int amt = 0;
						if(count%2 == 0){
							amt = freq[j]/2 + 1;
						}else{
							amt = freq[j]/2;
						}
						ans[j] += (freq[j] - amt);
						ans[tres] += amt;
						count += freq[j];
					}
				
			}
			
		}
      for(int i=0;i<=1023;i++){
        freq[i]=ans[i];	ans[i]=0;
          count = 0;
      }
	}
	int max = INT_MIN;
	int min = INT_MAX;
	for(int i = 0;i <= 1023;i++){
		if(freq[i] > 0){
			if(max < i){
				max =i;
			}
		}
	}
	for(int i = 0;i <= 1023;i++){
		if(freq[i] > 0){
			if(min > i){
				min = i;
			}
		}
	}
	
	cout<<max<<" "<<min<<endl;
}