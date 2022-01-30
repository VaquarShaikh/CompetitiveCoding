#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

void printbfs(int** edges,int n,int sv,bool* visited){
	queue<int> q;
	q.push(sv);	
	visited[sv] = true;

	while(!q.empty()){
		int top = q.front();
		cout<<top<<" ";
		q.pop();
		for(int i = 0;i < n;i++){
			if(edges[top][i] == 1 && !visited[i]){
				q.push(i);
				visited[i] = true;
			}
		}
	}	
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

	printbfs(edges,n,0,visited);

	for(int i = 0;i < n;i++){
		if(visited[i] == false){
			printbfs(edges,n,i,visited);
		}
	}
}