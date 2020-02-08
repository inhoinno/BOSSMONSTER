/* 
미로찾기 알고리즘, ->recursion 보다 간단한 풀이법이 없습니다.
 logic  
    1. 현재 위치가 출구이거나
    2. 현재위치에서 이웃한 셀 들중에 현재위치를 지나지 않고(= 중복 안하고?) 출구까지 가는 경로가 있을때

    sudo
        boolean findPath(x,y){
            if(grid[x][y] = exit) return true;
            else if (x , y = wall or outside of the grid ) return false;
            else 
                mark grid[x][y] = visited cell
                for each nieghboring cells , if x' , y' is (not visited && on the pathway)
                    if(findpath(x',y'))
                        return true;
            else finished
            return false;

        }
*/

public class Maze {
	    private static int N =8;    //size of grid
	    private static int [][] maze = { //grid
	        {0,0,0,0,0,0,0,1},
	        {0,1,1,0,1,1,0,1},
	        {0,0,0,1,0,0,0,1},
	        {0,1,0,0,1,1,0,0},
	        {0,1,1,1,0,0,1,1},
	        {0,1,0,0,0,1,0,1},
	        {0,0,0,1,0,0,0,1},
	        {0,1,1,1,0,1,0,0}
	    };
	    private static final int Path_Way_Color =0; // 갈 수 있는 길
	    private static final int Wall_Color =1; // 벽 
	    private static final int Blocked_Color =2; // visted
	    private static final int Path_Color =3; // 출구로 가는 길
	    public Maze(){};
	    public void printMaze(){
	        for(int i=0; i<N; i++){
	        	for(int j=0; j<N; j++)
	            System.out.printf("%d ",maze[i][j]);
	        System.out.println("");
	        }
	    };
        //메인 알고리즘
	    public static boolean findMazePath(int x, int y){
	        if(x<0||y<0|| x>=N||y>=N) //exception check
	            return false;
	        else if(maze[x][y] != Path_Way_Color)
	            return false;
	        else if (x==N-1 && y == N-1){ //exit
	            maze[x][y] =Path_Color;
	            return true;
	        }
	        else{   
	            maze[x][y]=  Path_Color;
	            if(findMazePath(x,y+1) || findMazePath(x,y-1) ||findMazePath(x+1, y) || findMazePath(x-1, y)){
                    //상하좌우중에 갈 수 있는길이 있으면 그곳으로 dfs 진행.
	                return true;
	                
	            }
	            maze[x][y] = Blocked_Color;
	            return false;
	        }
	    }
}