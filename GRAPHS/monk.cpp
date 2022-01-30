#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

#define pb push_back


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		
		vector<int>* gp = new vector<int>[n];

		bool* visited = new bool[n];
		for(int i = 0;i < n;i++){
			visited[i] = false;
		}

		int* level = new int[n];
		while(m--){
			int x,y;
			cin>>x>>y;
			gp[x-1].pb(y-1);
			gp[y-1].pb(x-1);
		}

		queue<int> q;
		visited[0] = true;
		level[0] = 0;
		q.push(0);

		while(!q.empty()){
			int top = q.front();
			q.pop();
			for(int i = 0;i < gp[top].size();i++){
				int adj = gp[top][i];
				if(visited[adj] == false){
					level[adj] = level[top] + 1;
					q.push(adj);
					visited[adj] = true;
				}
			}
		}
		cout<<level[n-1]<<endl;
	}	
}