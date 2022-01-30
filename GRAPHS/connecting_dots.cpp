#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
#define mod 1000000007

int visited[51][51];
int findCycle = 0;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void dfs(char board[][MAXN],int x,int y,int fromx,int fromy,int needcolor,int n,int m){
	if(x < 0 || x >= n || y < 0 || y >= m) return;

	if(board[x][y] != needcolor) return;
	if(visited[x][y]){
		findCycle = 1;
		return;
	}
	visited[x][y] = 1;
	int f;
	for(f = 0;f < 4;f++){
		int nextx = x + dx[f];
		int nexty = y + dy[f];
		if(nextx == fromx && nexty == fromy) continue;
		dfs(board,nextx,nexty,x,y,needcolor,n,m);
	}
}

int solve(char board[][MAXN],int n, int m)
{
	int i,j;
	memset(visited,0,sizeof(visited));
	for(i = 0;i < n;i++)
		for(j = 0;j < m;j++)
			if(!visited[i][j])
				dfs(board,i,j,-1,-1,board[i][j],n,m);

	return findCycle;
}

int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}