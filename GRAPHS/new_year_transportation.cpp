#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

bool haspath(int** edges,int n,int sv,int ev,bool* visited){
	if(edges[sv][ev] == 1){
		return true;
	}
	visited[sv] = true;
	bool res = false;

	for(int i = 1;i < n;i++){
		if(edges[sv][i] == 1 && !visited[i]){
			res = haspath(edges,n,i,ev,visited);
			if(res == true){
				return res;
			}
		}
	}
	return res;
}

int main(){
	int n,t;
	cin>>n>>t;

	int* arr = new int[n]();

	for(int i = 1;i < n;i++){
		cin>>arr[i];
	}	

	int** edges = new int*[n + 1];
    for(int i = 0;i <= n;i++){
        edges[i] = new int[n+1];
        for(int j = 0;j <= n;j++){
            edges[i][j] = 0;
        }
    }

	for(int i = 1;i < n;i++){
		int a = i;
		int b = (i + arr[i]);
		edges[a][b] = 1;

	}

	bool* visited = new bool[n];

	for(int i = 0;i < n ;i++){
		visited[i] = false;
	}

	bool res = haspath(edges,n,1,t,visited);
	if(res == true){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
    for(int i= 0;i < n;i++){
		delete [] edges[i];
	}
    delete [] edges;
    delete [] visited;
}