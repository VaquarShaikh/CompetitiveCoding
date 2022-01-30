#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

vector<int>* getpathbfs(int** edges,int n,int sv,int ev,bool* visited){
	queue<int> bfs;
	
	map<int,int> mapp; 
	bfs.push(sv);
	visited[sv] = true;
	
	bool res = false;
	while(!bfs.empty()){
		int top = bfs.front();
		bfs.pop();
		for(int i = 0;i < n;i++){
			if(edges[top][i] == 1 && !visited[i]){
				bfs.push(i);
				mapp[i] = top;
				visited[i] = true;
				if(i == ev){
					res = true;
					break;
				}

			}
		}
	}
	if(!res){
		return NULL;
	}
	else{
		vector<int>* ans = new vector<int>();
		int curr= ev;
		ans->push_back(curr);
		while(curr != sv){
			curr = mapp[curr];
			ans->push_back(curr);
		}
		return ans;
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
	for(int i = 0;i < n;i++){
		visited[i] = false;
	}
	int sv,ev;
	cin>>sv>>ev;

	vector<int>* res = getpathbfs(edges,n,sv,ev,visited);

	if(res != NULL){
		for(int i = 0;i < res->size();i++){
			cout<<res->at(i)<<" ";
		}cout<<endl;
	}	
}