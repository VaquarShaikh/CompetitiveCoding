#include<bits/stdc++.h>
using namespace std;
#include "solution.h"

int main(){
    int n;
    cin>>n;
    int maze[20][20];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin>>maze[i][j];
        }
    }
    ratInAMaze(maze,n);
}
