#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

bool haspath(int** edges,int n,int sv,int ev,bool* visited){
	if(edges[sv][ev] == 1){
		return true;
	}
	visited[sv] = true;
	bool res = false;

	for(int i = 0;i < n;i++){
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
	int n,e;
	cin>>n>>e;

	int** edges = new int*[n];

	for(int i = 0;i < n;i++){
		edges[i] = new int[n];
		for(int j = 0;j < n;j++){
			edges[i][j] = 0;
		}
	}	

	for(int i = 0;i < e;i++){
		int f,s;
		cin>>f>>s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}

	bool* visited = new bool[n];

	for(int i = 0;i < n ;i++){
		visited[i] = false;
	}

	int sv,ev;
	cin>>sv>>ev;

	bool res = haspath(edges,n,sv,ev,visited);
	if(res == true){
		cout<<"true\n";
	}else{
		cout<<"false\n";
	}
	for(int i= 0;i < n;i++){
		delete [] edges[i];
	}
	delete [] edges;
	delete [] visited;
}