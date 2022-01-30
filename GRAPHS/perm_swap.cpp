#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

void dfs(vector<int>* edges,int start,unordered_set<int>* component,bool* visited){
	visited[start] = true;
	component->insert(start);

	for(int i = 0;i < edges[start].size();i++){
		int next = edges[start][i];
		if(!visited[next]){
			dfs(edges,next,component,visited);
		}
	}
	// delete [] visited;
}

unordered_set<unordered_set<int>*>* getcomponents(vector<int>* edges,int n){
	bool* visited = new bool[n];
	for(int i = 0;i < n;i++){
		visited[i] = false;
	}
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	for(int i = 0;i < n;i++){
		if(!visited[i]){
			unordered_set<int>* component = new unordered_set<int>();
			dfs(edges,i,component,visited);
			output->insert(component);
		}
	}
	delete [] visited;
	return output;
}

bool check(unordered_set<int> pv,unordered_set<int> pi,int* q,int n){
	unordered_set<int>::iterator it1;
	for(it1 = pi.begin();it1 != pi.end();it1++){
		int xi = *it1;
		int vq = q[xi];
		if(pv.find(vq) == pv.end()){
			return false;
		}
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int* p = new int[n];
		int* q = new int[n];

		for(int i = 0;i < n;i++){
			cin>>p[i];
		}
		for(int i = 0;i < n;i++){
			cin>>q[i];
		}
		vector<int>* edges = new vector<int>[n];
		for(int i = 0;i < m;i++){
			int j,k;
			cin>>j>>k;

			edges[j-1].push_back(k-1);
			edges[k-1].push_back(j-1);
		}
		bool res = true;
		unordered_set<unordered_set<int>*>* components = getcomponents(edges,n);
		unordered_set<unordered_set<int>*>::iterator it1 = components->begin();
		while(it1 != components->end()){
			unordered_set<int>* component = *it1;
			unordered_set<int>::iterator it2 = component->begin();
			unordered_set<int> pv,pi;
			while(it2 != component->end()){
				int index = *it2;
				pi.insert(index);
				pv.insert(p[index]);
				it2++;
			}
			if(!check(pv,pi,q,n)){
				res = false;
				break;
			}
		// cout<<endl;
			delete component;
			it1++;
		}
		if(res){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
		delete components;
		delete [] edges;
	}
}	
/*
6
5
1 2
1 3
2 4
4 3
5 6
*/