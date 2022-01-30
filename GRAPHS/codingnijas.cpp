#include<bits/stdc++.h>
using namespace std;
#define MAXN 102
#define mod 1000000007

int a[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
char pattern[11] = {'C','O','D','I','N','G','N','I','N','J','A'};

int used[MAXN][MAXN];

int validpoint(int x,int y,int N,int M){
	return (x >= 0 && x < N && y >= 0 && y < M);
}

int DFS(char G[][MAXN],int x,int y,int index,int N,int M){
	if(index == 11){
		return 1;
	}
	used[x][y] = 1;

	int i,newx,newy,found = 0;

	for(int i = 0;i < 8;i++){
		newx = x + a[i][0];
		newy = y + a[i][1];
		if(validpoint(newx,newy,N,M) && G[newx][newy] == pattern[index] && !used[newx][newy]){
			found = found | DFS(G,newx,newy,index + 1,N,M);
		}
	}
	used[x][y] = 0;
	return found;
}

int solve(char Graph[][MAXN],int N, int M)
{
	int i , j ,found;
	for(i = 0;i < N;i++){
		for(j = 0,found = 0;j < M;j++){
			if(Graph[i][j] == 'C'){
				found = DFS(Graph,i,j,1,N,M);
				if(found)
					break;
			}
		}
		if(found)
			break;
	}
	return found;
}

int main()
{
	int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
}