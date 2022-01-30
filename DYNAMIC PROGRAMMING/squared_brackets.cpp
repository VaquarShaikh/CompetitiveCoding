#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int no_expr(int o,int c,int n,bool arr[],int output[20][20]){
    if(o > n || c > n){
        return 0;
    }if(o == n && c == n){
        return 1;
    }
    if(output[o][c] != -1){
    	return output[o][c];
    }int ans;
    if(o == c || arr[o+c] == true){
        //opening
        ans = no_expr(o+1,c,n,arr,output);
    }
    else if(o == n){
        //closing
        ans = no_expr(o,c+1,n,arr,output);
    }else{
        int op1 = no_expr(o+1,c,n,arr,output);
        int op2 = no_expr(o,c+1,n,arr,output);
        ans = op1 + op2;
    }
    output[o][c] = ans;
    return ans;
}

int main(){
    int d;
    cin>>d;
    while(d--){
        int n,k;
        cin>>n>>k;
        bool arr[2*n];
        arr[0] = true;
        for(int i = 1;i <= 2*n;i++){
            arr[i] = false;
        }
        for(int i = 0;i < k;i++){
            int s;
            cin>>s;
            arr[s - 1] = true;
        }
        int output[20][20];
        for(int i = 0;i <= n/2;i++){
        	for(int j = 0;j <= n/2;j++){
        		output[i][j] = -1;
        	}
        }
        cout<<no_expr(0,0,n,arr,output)<<endl;
    }
}