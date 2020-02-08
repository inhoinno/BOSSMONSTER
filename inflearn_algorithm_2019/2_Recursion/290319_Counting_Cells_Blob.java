/* 
counting cells in a blob
그리드 안에 상하좌우, 대각으로 하여금 채워진 칸을 blob이라고 치고,
그 갯수를 구하는 문제가 되겠다.

//sudo 부분
 
 if the pixel(x,y) is outside of the grid
    result =0;
else if pixel(x,y) is not an image pixel or already counted // 무한루프 제외
    result =0;
else 
    pivot pixel -> visited // red color
    result +=1;
    recursion start //자식노드 방문
*/
private static int Background =0;
private static int Image_Color =1;
private static int visited =2; //already counted
//method
public static int countCells(int x, int y){
    if(x<0 || y<0 || x>=N || y>=N){
        return 0;
    }
    else if(grid[x][y] != Image_Color){
        return 0;
    }
    else{
        grid[x][y] = visited;
        return 1+ countCells(x+1, y) + countCells(x-1, y) + countCells(x, y+1) +countCells(x, y-1) + countCells(x-1, y+ 1)+ countCells(x+1, y+1) + countCells(x-1, y-1) + countCells(x+1, y-1);
    }
}