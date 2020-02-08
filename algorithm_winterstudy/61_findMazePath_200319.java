package mazemaze;

public class Maze {
	    private static int N =8;
	    private static int [][] maze = {
	        {0,0,0,0,0,0,0,1},
	        {0,1,1,0,1,1,0,1},
	        {0,0,0,1,0,0,0,1},
	        {0,1,0,0,1,1,0,0},
	        {0,1,1,1,0,0,1,1},
	        {0,1,0,0,0,1,0,1},
	        {0,0,0,1,0,0,0,1},
	        {0,1,1,1,0,1,0,0}
	    };
	    private static final int Path_Way_Color =0; // white
	    private static final int Wall_Color =1; //blue
	    private static final int Blocked_Color =2; // red
	    private static final int Path_Color =3; //green
	    public Maze(){};
	    public void printMaze(){
	        for(int i=0; i<N; i++){
	        	for(int j=0; j<N; j++)
	            System.out.printf("%d ",maze[i][j]);
	        System.out.println("");
	        }
	    };



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
	                return true;
	                
	            }
	            maze[x][y] = Blocked_Color;
	            return false;
	        }
	    }
}
public static void main(String[] args){
    Maze M = new Maze();
    M.printMaze();
    M.findMazePath(0,0);
    M.printMaze();
}