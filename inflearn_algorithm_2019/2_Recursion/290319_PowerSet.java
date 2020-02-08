/* 

power set 멱집합
당구장 표시) 이 부분은 상태공간트리로 설명할 때 더 이해하기 쉬움을 알려드립ㄴ다


멱집합이란? : 자기 자신의 원소 + 자기자신 부분집합 + 자기자신 을 원소로 갖는 집합
S = {a, b}
P(s) = {0, {a} ,{b} , S} // powerset of S

멱집합 알고리즘. : data 를 집합이라고 하였을 때 P(data) 를 출력하는 프로그램 제작

                    k=0    {}
                   a 제외  /  \ a 포함
                k=1  {}         {a}
             b 제외  / \b포함 제/  \ b포함
            k=2   {}    {b}  {a}   {a,b}    => 멱집합 P의 원소들이 되시겠다.

     Q1 . 포함 제외를 어떤방식으로 구현 할 것인가?
     Q2 . 자식노드 방문을 어떤방식으로 구현 할 것인가?



*/
public class PowerSet{
    private static char data[] ={'a','b','c','d','e','f'};
    private static int n = data.length();
    private static boolean [] include = new boolean[n]; // include boolean 배열이 갖는 의미. Q1 . 포함 제외를 true false 로 나누어 그에따라서 Q2. 자식노드를 방문한다

    public static void PowerSet(int k){
        if(k==n){ //리프노드의 도착
            for(int i=0; i<n; i++){
                if(include[i]) system.out.println(data[i] + " ");   //리프노드로 오는동안 include 에 의해 제외한거 빼고 출력된다.(false로 체크한 부분)
                system.out.println(" ");
                return; //리프노드 종료
            }
        }
        include[k] =false;
        PowerSet(k+1);
        //제외하는 자식노드로 dfs. 
        //리프노드로 도달 할 때 까지 DFS진행되고, 맨 처음 출력되는 원소는 공집합이 출력됨. 그담은 아마도 {f} <-이건 담에 나올 트루를 한번만 거쳤을 떄. 모든 원소를 포함하지 않았으까(FALSE만 하면서 DFS) 
        inlcude[k] =true;니
        PowerSet(k+1);
        //바꾸어서 포함으로 dfs
    }
}