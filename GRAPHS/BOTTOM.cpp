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

unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges,vector<int>* edgesT,int n){
    unordered_set<int> visited;

    stack<int> finishV;
    for(int i = 0;i < n;i++){
        if(visited.count(i) == 0){
            dfs(edges,i,visited,finishV);
        }
    }
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    visited.clear();
    while(!finishV.empty()){
        int element = finishV.top();
        finishV.pop();
        if(visited.count(element) != 0){
            continue;
        }
        unordered_set<int>* component = new unordered_set<int>();
        dfs2(edgesT,element,component,visited);
        output->insert(component);
    }
    return output;
}

bool check(unordered_set<int>* component,vector<int>* edges,int n){
    unordered_set<int>::iterator it = component->begin();

    while(it != component->end()){
        int v = *it;

        for(int i = 0;i < edges[v].size();i++){
            int x = edges[v][i];
            if(component->count(x) == 0){
                return false;
            }
        }
        it++;
    }
    return true;
}

int main(){
    while(1){
        int n,m;
        cin>>n>>m;

        if(n == 0){
            break;
        }

        vector<int>* edges = new vector<int>[n]();
        vector<int>* edgesT = new vector<int>[n]();

        for(int i = 0;i < m;i++){
            int j,k;
            cin>>j>>k;
            edges[j-1].push_back(k-1);
            edgesT[k-1].push_back(j-1);
        }
        vector<int> v;
        unordered_set<unordered_set<int>*>* components = getSCC(edges,edgesT,n);
        unordered_set<unordered_set<int>*>::iterator it1 = components->begin();
        while(it1 != components->end()){
            unordered_set<int>* component = *it1;

            if(check(component,edges,n)){
                //print the values.

                unordered_set<int>::iterator it2 = component->begin();
                while(it2 != component->end()){
                    v.push_back((*it2));
                    it2++;
                }


            }

            // cout<<endl;
            delete component;
            it1++;
        }
        sort(v.begin(),v.end());

        for(int i = 0;i < v.size();i++){
            cout<<v[i] + 1<<" ";
        }
        cout<<endl;

        delete components;
        delete [] edges;
        delete [] edgesT;

    }	
}