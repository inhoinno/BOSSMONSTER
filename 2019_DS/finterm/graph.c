/*그래프의 이해, graph 자료구조.*/
/*1. directed graph->방향성 있다 2. inderected graph<->방향성 없다*/

/*그래프의 순회*/
//1. BFS : 그래프 범위우선 탐색 ->>>>>>"QUEUE"이용해! 
//2. DFS : 그래프 깊이우선 탐색

/*graph 자료구조의 표현 방법.*/
//1. Adjacency Matrix 2차원 배열의 행렬 표현
//2. linked list 
//3. Tree
//4. Heap

/*그래프 활용*/
/*그래프가 활용되는 곳 */
//1. city network : 기지국을 어디에 설치해야, 최소 기지국 대비 최대 연결이 될까?
//2. path finding
//3. 2. -> spanning tree NO CYCLE . 그래프를 트리로 만들어 버리기. 



// 1. Adjacency Matrix (이차원 배열)
// Array
/*  1   2   3   4   5
  +-------------------
1 | 1 | 0 | 0 | 0 | 0 |
2 | 0 | 1 | 2 | 6 | 7 |
3 | 0 | 0 | 1 | 0 | 0 |
4 | 0 | 1 | 0 | 1 | 0 |
5 | 0 | 5 | 0 | 0 | 0 |


정방행렬.(directed & indirected)
대칭행렬의 형태(in indirected graph).
각 [v1][v2] index는 노드의 번호주기를 통해서 노드를 나타내고
배열의 크기 = 노드의 수. 
index의 값은 
    1. 연결 여부 (0 : not connected 1 : connected)
    2. 간선 간 가중치 (path cost :[v1][v2] cost to go v2 from v1)

*/

// 2. Adjacency List (Linked List)
/*
A
|
B ㅡ E ㅡ F
| /  |  
C ㅡ D
 
ㅁAㅁ -> |B|X|
ㅁBㅁ -> |A|ㅁ| -> |C|ㅁ| -> |E|ㅁ|
ㅁCㅁ -> |B|ㅁ| -> |D|ㅁ| -> |E|X|
ㅁDㅁ -> |C|ㅁ| -> |E|X|
ㅁEㅁ -> |B|ㅁ| -> |C|ㅁ| -> |D|ㅁ| -> |F|X|
N Fㅁ -> |E|X|
  ^vertex ^arc
*/

/*BOOK. "DATA STRUCTURES"*/
typedef struct {
    int     count;
    struct vertex* fisrt;
    int     (*compare)(void * argu1, void * argu2);
}GRAPH; //head structure

typedef struct vertex{
    struct vertex *     pNextVertex; //연결된 노드 
    void*       dataPtr; // 데이터를 가리킬 포인터 변수
    int         inDegree; // 
    int         outDegree; //
    short       processed;
    struct arc* pArc; //TO first arc

}VERTEX;    //링크드 노드.

typedef struct arc{
    struct vertex * destination;
    struct arc* pNextArc;
    //int weigh
}   //간선같은것... the path from one vertex to another.
//가중치를 받을 수 있다.