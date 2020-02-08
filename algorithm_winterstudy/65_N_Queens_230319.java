public Class N_Queens {
    private int N;
    private int [][] grid {};

    private static int final Placable = 0;
    private static int final Queen_Placed =1; 
    private static int final UnPlacable =2; //boolean

    public N_Queens(){};
    public Set_N(int n){ N = n;};
    
    
    
    
    public boolean Place_Queen (int x, int y){
        if(x>=N || y>=N || x<0 || y<0) //exception check
            return false;
        else if (grid[x][y] == UnPlacable){ // 이미 놓여서 직선 대각선 상에 못 놓는 경우
            return false; 
        }
        else if(grid[x][y] == Placable){
            grid[x][y] =1;
            if(){}//상하좌우 대각에 queen 이 있으면 Un     
            grid[x][y] = UnPlacable;
            return false;
        }
    }


 

}