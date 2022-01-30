
int sol[20][20];

void ratInAMazehelper(int maze[][20],int n,int row,int col){
    if(row== n-1 && col == n-1){
        //print solution and return
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                cout<<sol[i][j]<<" ";
            }
        }cout<<endl;
        return;
    }
    if(row < 0 ||row >= n || col < 0 || col >= n || maze[row][col] == 0 || sol[row][col] == 1){
        return;
    }
    sol[row][col] = 1;
    ratInAMazehelper(maze,n,row,col+1);
    ratInAMazehelper(maze,n,row+1,col);
    ratInAMazehelper(maze,n,row-1,col);
    ratInAMazehelper(maze,n,row,col-1);
    sol[row][col] = 0;
}

void ratInAMaze(int maze[][20],int n){
    memset(sol,0,20*20*sizeof(int));
    ratInAMazehelper(maze,n,0,0);
}
