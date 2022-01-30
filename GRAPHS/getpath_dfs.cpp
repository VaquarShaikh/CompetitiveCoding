#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

vector<int>* getpath(int** edges,int n,int sv,int ev,bool* visited){
	if(sv == ev){
		vector<int>* ans = new vector<int>();
		ans->push_back(sv);
		return ans;
	}

	visited[sv] = true;

	for(int i = 0;i < n;i++){
		if(edges[sv][i] == 1 && !visited[i]){
			vector<int>* s = getpath(edges,n,i,ev,visited);
			if(s != NULL){
				s->push_back(sv);
				return s;
			}
			delete [] s;

		}
	}
	return NULL;
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

	vector<int>* res = getpath(edges,n,sv,ev,visited);

	if(res != NULL){
		for(int i = 0;i < res->size();i++){
			cout<<res->at(i)<<" ";
		}cout<<endl;
	}
}