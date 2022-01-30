#include<bits/stdc++.h>
using namespace std;

int min_health_req(int** health,int r,int c){
	int output[r][c];
	output[r-1][c-1] = 1;
	output[r-2][c-1] = 1;
	output[r-1][c-2] = 1;
	for(int i = r-3;i >= 0;i--){
        
		int val = (output[i+1][c-1] - health[i+1][c-1]);
        if(val<=0)
            output[i][c-1]=1;
        else{
            output[i][c-1]=val;
        }
	}
	for(int j = c-3;j >= 0;j--){
		int val = (output[r-1][j+1] - health[r-1][j+1]);
        if(val<=0)
            output[r-1][j]=1;
        else
            output[r-1][j]=val;
	}
    
	for(int i = r-2;i >= 0;i--){
		for(int j = c-2;j >= 0;j--){
           int val=min(output[i+1][j]-health[i+1][j],output[i][j+1]-health[i][j+1]);
                  if(val<=0)
                     output[i][j]=1;
                  else
                    output[i][j]=val;
		}
	}
	return output[0][0];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int r,c;
		cin>>r>>c;
		int** health = new int*[r];
		for(int i = 0;i < r;i++){
			health[i] = new int[c];
			for(int j = 0;j < c;j++){
				cin>>health[i][j];
			}
		}
		cout<<min_health_req(health,r,c)<<endl;
	}
}