/*
back tracking -> 구현 방법.
1. recursion // 빠르고 쉬운 방법.
2. stack


sudo 부분

return_type Queens(int level) { "(괄호)안의 의미는, 이 노드에 도착했다!" 라는 의미가 되겠다.
    if(non-promising(level)){
        return false;
    }
    else if() {//도착한 노드가 답인가??
        return true;
    }
    else{ //노드에서 판단 해야하는경우. 답인지 꽝인지 모를때는 자식노드를 방문하게 한다.
        visit children recursively.
    }
}

boolean promising(int level){

    for(int i=0 ; i<level; i++){
        if(cols[level] == cols[i]) // 같은 행 열 에 있을때
            return false;
        else if(대각선에 놓여 있을때)
            return false;

        return true;
    }
}
*/

int cols[] = new int [N+1] //2차원 배열이 아닌 1차원 배열을 사용한다
// cols[level] -> 노드 부분에 cols[level] = value몇번쨰 칸에 말이 놓였는지(= 값) 확인 할 수 있기 떄문에.
boolean Queens(int level){
    if(!promising(level)) { //level에 도착 했는데 말도 놓았는데 ,(cols[level]) 그 전 까지 놓은 말들이랑 충돌 하니? -> promisong(level)
        return false;
    }
    else if( level == N) {//level 이 N까지 왔다는것은 검사를 모두 마쳤다는 것. 정답이라는 것
        return true;
    }
    for(int i =0; i<=N; i++){//핵심코드. level +1 번쨰(자식노드) 에 말을 놓아도 되는지 안되는지 판단하는 부분임.
        cols[level] = i;
        if(Queens(level+1))     //안되면 그냥 if없이 queens(level+1)
            return true;
    }
    return false;
}

boolean promising(int level){
    for(int i=0; i< level; i++){
        if(cols[i] == cols[level]) //값이 같다는 것은 같은 열에 말이 있다는 것을 의미하는 것이므로 조건을 만족 한다면 false 리턴
            return false;
        else if(level - i == math.abs(cols[level] - cols[i])){ //대각선 임을 의미 하는데 , 좌표의 대각선 성질 상 대각선에 있다면 가로값(|cols[level] - cols[i]|)과 세로(level - i) 값이 서로 일치함을 볼 수있다.
            return false;
        }
        return true; // 위의 조건을을 거쳐왔다는것은 대각선에ㅐ 있지도 않고 열에 있지도 않음을 의미한다.
    }

}