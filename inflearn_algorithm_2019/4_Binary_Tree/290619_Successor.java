/* 
최소값과 계승자

트리의 최소값 // Tree_Minimum
//sudo
Tree_minimum(x)
1. while left[x] != Null
2.  x <- left[x]
3. return x;

노드의 계승자 // Successor(Delete 에 꼭 필요한 개념)
1.계승자 개념은 트리가 있을때 직선상으로 루트노드에 가장 가까운 Tree_left중의 노드를 말함.
2.즉, 노드의 오른쪽 트리(노드보다 큰 노드들)중 가장 작은 값(가장 왼쪽 하단의 노드)를 계승자라 함.
3.오른쪽 서브트리가 존재하지 않는경우, 어떤노드 y의 Tree_left중 최대값이 
//sudo
Tree_Successor(x)
1. if right[x] != Null //오른쪽 트리가 존재한다면
2.  then return Tree_Minimum(Right[x])
3. y <- p[x] //부모노드 방문, 


 */