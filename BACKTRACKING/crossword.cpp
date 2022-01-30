#include<bits/stdc++.h>
using namespace std;

#define n 10

bool isvalidvertical(char grid[][n],string word,int row,int col){
	int count = 0;
	for(int i = row;i < row + word.length();i++){
		if(grid[i][col] == '-' || grid[i][col] == word[count + 1]){
			count++;
		}
		if(grid[i][col] == '+'){
			return false;
		}
	}
	if(count == word.length()){
		return true;
	}
}

void setvertical(char grid[][n],string word,bool helper[],int row,int col){
	int count = 0;
	int k = 0;
	for(int i = row;i < row + word.length();){
		grid[i][col] = word[k++];
		helper[count] = true;
		i++;
		count++;
		if(grid[i][col] == word[count + 1]){
			i++;
		}
	}
}

void resetvertical(char grid[][n],string word,bool helper[],int row,int col){
	int k = 0;
	for(int i = row;i < row + word.length();){
		if(helper[k++] == true){
			grid[i++][col] = '-';
		}else{
			i++;
		}
	}
}

bool isvalidhorizontal(char grid[][n],string word,int row,int col){
	int count = 0;
	for(int j = col;j < col + word.length();j++){
		if(grid[row][j] == '-' || grid[row][j] == word[count + 1]){
			count++;
		}if(grid[row][j] == '+'){
			return false;
		}
	}if(count == word.length()){
		return true;
	}
}

void sethorizontal(char grid[][n],string word,bool helper[],int row,int col){
	int count = 0;
	int k = 0;
	for(int j = col;j < col + word.length();){
		grid[row][j] = word[k++];
		helper[count] = true;
		j++;
		count++;
		if(grid[row][j] == word[count + 1]){
			j++;
		}
	}
}

void resethorizontal(char grid[][n],string word,bool helper[],int row,int col){
	int k = 0;
	for(int j = col;j < col + word.length();){
		if(helper[k++] == true){
			grid[row][j++] = '-';
		}else{
			j++;
		}
	}
}

int noofwords(string s){
	int count = 0;
	for(int i = 0;i < s.length();i++){
		if(s[i] == ';'){
			count++;
		}
	}
	return count + 1;
}

bool solvecrossword(char grid[][n],string options[],int index,int num){
	if(index == num){
		//print crossword
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				cout<<grid[i][j];
			}cout<<endl;
		}
	}

	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(grid[i][j] == '-' || grid[i][j] == options[index][0]){
				string word = options[index];
				if(isvalidvertical(grid,word,i,j)){			//check vertical
					int len = word.length();
					bool helper[len] = {false};
					setvertical(grid,word,helper,i,j);		
					if(solvecrossword(grid,options,index+1,num)){
						return true;
					}else{
						resetvertical(grid,word,helper,i,j);
					}
				}if(isvalidhorizontal(grid,word,i,j)){
					int len = word.length();
					bool helper[len] = {false};
					sethorizontal(grid,word,helper,i,j);
					if(solvecrossword(grid,options,index + 1,num)){
						return true;
					}else{
						resethorizontal(grid,word,helper,i,j);
					}
				}
			}
		}
	}
}

int main(){
	
	char grid[n][n];
	for (int i = 0; i < n; i++)
	{
		string s;
		cin>>s;
		for (int j = 0; j < s.length(); j++)
		{
			grid[i][j] = s[j];
		}
	}
	string options[1000];
	int k = 0;
	string s;
	cin>>s;
	int num = noofwords(s);
	for(int i = 0;s[i] != '\0';i++){
		if(s[i] == ';'){
			i++;
			k++;
		}
		options[k] += s[i];
	}

	bool res = solvecrossword(grid,options,0,num);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cout<<grid[i][j];
		}cout<<endl;
	}
}
/*
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
*/