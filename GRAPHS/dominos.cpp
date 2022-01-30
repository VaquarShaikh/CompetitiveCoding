#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

void dfs(vector<int>* edges,int start,unordered_set<int>& visited,stack<int>& finishV){
	visited.insert(start);
	for(int i = 0;i < edges[start].size();i++){
		int adj = edges[start][i];

		if(visited.count(adj) == 0){
			dfs(edges,adj,visited,finishV);
		}
	}
	finishV.push(start);
}

void dfs2(vector<int>* edgesT,int start,unordered_set<int>* component,unordered_set<int>& visited){
	component->insert(start);

	visited.insert(start);
	for(int i = 0;i < edgesT[start].size();i++){
		int adj = edgesT[start][i];
		if(visited.count(adj) == 0){
			dfs2(edgesT,adj,component,visited);
		}
	}
}

int getSCC(vector<int>* edges,vector<int>* edgesT,int n){
	unordered_set<int> visited;

	stack<int> finishV;
	for(int i = 0;i < n;i++){
		if(visited.count(i) == 0){
			dfs(edges,i,visited,finishV);
		}
	}
	int output = 0;
	visited.clear();
	while(!finishV.empty()){
		int element = finishV.top();
		finishV.pop();
		if(visited.count(element) != 0){
			continue;
		}
		unordered_set<int>* component = new unordered_set<int>();
		dfs2(edgesT,element,component,visited);
		output++;
	}
	return output;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int,int>> input;

		int m;
		cin>>m;
		for(int i = 0;i < m;i++){
			int x,y;
			cin>>x>>y;
			input.push_back(make_pair(x,y));
		}	

		sort(input.begin(),input.end());
		vector<int>* edges = new vector<int>[n];
		vector<int>* edgesT = new vector<int>[n];
		for(int i = 0;i < m;i++){
			int a = input[i].first;
			int b = input[i].second;

			edges[a - 1].push_back(b - 1);
			edgesT[b - 1].push_back(a - 1);
		}

		int output = getSCC(edges,edgesT,n);

		cout<<output<<endl;

		// for(int i = 0;i < edges->size();i++){
		// 	cout<<edges->at(i)<<" ";
		// }cout<<endl;
		// for(int i = 0;i < input.size();i++){
		// 	cout<<input[i].first<<" "<<input[i].second<<endl;
		// }
	}
}