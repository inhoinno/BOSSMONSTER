/* 
말을 놓는데 상하좌우 대각에 놓인 말이 없이 각 열마다 말을 놓는 알고리즘
like스도쿠
 + 상태공간트리 개념의 이해 
 + BackTracking 개념의 이해

            start
            /   \  
    1열 (1,1)   (1,2) (1,3) (1,4) ... (1,8)
       / / \ \   
(2,1)(2,2)(2,3)(2,4) ... (2,8)
/    
(3,1) (3,2) .....

설명
    시작 후 1,1 자리에 말이 놓을 수 있는지 탐색을 실시한다
    놓을수 있는지는 자식노드를 방문하여 마찬가지로 여기에 놓는다면 
    그의 자식노드에 또 방문하여 여기도 놓을 수 있는지 판단한다

    모든 트리의 노드에 해가 존재하므로, (한가지의 경로 like (1,2) (2,3) (3,5) ...)
    트리 탐색을 체계적으로 할 수 있는 알고리즘을 구현하여야 하겠따.
    말을 못 놓네? 하면 부모노드로 돌아가는 backtracking 기술에 초점을 맞추어서 탐구해보자



    sudo ; backtracking procedure 1. recursion(granted) 2. stack
    designing :
        return_type Queens (arguments){
            if (non_promising) // 노드가 꽝인가?
                report failure and return
            else if sucess // 노드가 답인가?
                report answer and return
            else //노드가 꽝도 아니고 답도 아니라면, 자식노드를 방문하여 자식노드에서 다시 연산 수행(DFS)
                visit children nord reculsively

        }

    
*/
public class N_Queens{
    public static int N = 8;
    int cols[] = new int [N+1];

    boolean Queens(int level){
        if(!promising_level(level)){ //이 위치에 놓았을때 말들이 충돌 하는지에 대해 판단하는 부분
            return false;
        }
        else if (level == N){   // 마지막까지 말을 놓으면서 왔을 때 정답이라고 할 수 있겠죠
            return true;
        }
        for(int i =1; i<=N; i++){ // 자식노드 방문해야지 + backtracking
            cols[level +1] = i // level+1은 행을 나타내게 되고, (자식노드의 level) 값인 i 는 열의 정보(x는 level값 y는 몇번째 열인지 알려주는 값)를 나타내게 됨
            if(Queens(level +1)) // dfs탐색 + backtracking
                return true; 
        }
        return false;
    }
}