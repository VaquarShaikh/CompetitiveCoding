#include<bits/stdc++.h>
using namespace std;

#define n 9

bool findemptyloc(int grid[][n],int& row,int& col){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(grid[i][j] == 0){
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}

bool issafeinrow(int grid[][n],int row,int num){
	for(int i = 0;i < n;i++){
		if(grid[row][i] == num){
			return false;
		}
	}
	return true;
}

bool issafeincol(int grid[][n],int col,int num){
	for(int i = 0;i < n;i++){
		if(grid[i][col] == num){
			return false;
		}
	}
	return true;
}

bool issafeingrid(int grid[][n],int row,int col,int num){
	int rowfactor = row - (row%3);
	int colfactor = col - (col%3);
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			if(grid[i + rowfactor][j + colfactor] == num){
				return false;
			}
		}
	}
	return true;
}

bool issafe(int grid[][n],int row,int col,int num){
	return issafeinrow(grid,row,num) && issafeincol(grid,col,num) && issafeingrid(grid,row,col,num);
}

bool solvesudoku(int grid[][n]){
	int row,col;
	if(!findemptyloc(grid,row,col)){
		return true;
	}
	for(int i = 1;i <= 9;i++){
		if(issafe(grid,row,col,i)){
			grid[row][col] = i;
			if(solvesudoku(grid)){
				return true;
			}
			grid[row][col] = 0;
		}
	}
	return false;
}

int main(){
	int grid[n][n];
	for(int i = 0;i < n;i++){
		string s;
		cin>>s;
		for(int j = 0;j < s.length();j++){
			grid[i][j] = s[j] - '0';
		}
	}
	bool res = solvesudoku(grid);
	if(res){
		cout<<"true\n";
	}else{
		cout<<"false\n";
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cout<<grid[i][j];
		}cout<<endl;
	}
}

