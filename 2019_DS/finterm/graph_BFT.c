/*Breadth Fisrt Traversal 구현*/
//너비우선탐색? -> queue 를 이용해서 level order처럼 번호주기 합니다.
/*BOOK. Data Structure */
/* BSF breadth first pseudocode (List)*/
/*범위우선Traversal*/
Algorithm breadthFisrtTraversal (graph)
processes the keys fo the graph head structure
    //Pre graph is pointer to graph in breadth-first order.
    //Post vertices processed
1   if (empty graph)
    1   return
2   end if
    //Process each vertex in vertex list
3   createQueue (queue)
4   loop (through all vertices)
    1 set vertux to not processed
5   end loop
    //Process each vertex in vertex list
6   loop (through all vertices) //let head 1
    1   if (vertex not processed)
        1   if (vertix not in queue) //head 1
            //Enqueue and set process flag to queued
            1 enqueue (queue, walkPtr) //q 1
            2 set vertix to enqueued // v is 1
        2   end if
            //Now process descendents of vertex at queue front
        3   loop(not emptyQueue()) //q 1
            1   set vertex to dequeue (queue) //v 1 //q empty
            //process vertex and flag as processed
            2   process (vertex) //process 1
            3   set vertix to processed // 1 ->flag
            //enqueue non-processed vertuces from adjacency list
            4   loop (through adjacenct list) //v1 -> 2 -> 3 //for23
                1 if destination not enqueued or processed // for 2 /// for 3
                    1   enqueue (queue) // q 2 /// q 2 3
                    2   set destination to enqueued //des = 2 /// adc->des = 3
                2 endif
                3 get next destination // list = list->des ///null
            5   end loop // q 2 3
        4   end loop
    2 end if
    3 get next vertix //v =2 
7   end loop
8   destroy queue
end breathFirst

/*BOOK Data Structure*/
/* Code */
/* ======================= graphBrdthFrst ==========================
    Proces the data of the graph in brdth first order 
        pre graph is pointer to graph head structure
        post graph has been processed 
        processed Flag : 0 = not processed
                         1 = enqueued
                         2 = processed
*/
void graphBrdthFirst(GRAPH * graph, void (*process) (void* dataPtr)){
//Local
bool success;
VERTEX * walkPtr;
VERTEX * vertexPtr;
VERTEX * vertToPtr;
QUEUE * queue;
ARC* arcWalkPtr; //for adjacent vertex. 연결관계만 포함하는 자료구조 arc

// Statements 
    if (!graph -> first)
        return ;
    
    // Set processed flags to not procesed
    /* 초기화 부분 */
    walkPtr = graph->first;
    while(walkPtr){
        walkPtr->processed =0;
        walkPtr = walkPtr ->pNextVertex;
    }
    /* Vertex 를 번호주기 하는 부분 (Queue 에 삽입) */
    //process each vertex in List
    queue = createQueue();
    walkPtr = graph->first;
    while(walkPtr){
        if(walkPtr->processed <2){ // 2 = processed
            if(walkPtr -> processed < 1){// ( so, for processed->0 only) 1 = enqueue
                // Enqueue and set flag to queue
                success = enqueue(queue, walkPtr);
                if(success<0)}{printf("queue overflow! 100"); exit(100);}
                walkPtr -> processed = 1;
           } // if processed <1 
        } // if processed <2
        /*Queue에 있는 노드 pop-> 인접노드 push*/
        while(!emptyQueue(queue)){
            dequeue(queue, (void**)&vertexPtr);
            process (vertexPtr->dataPtr);
            vertexPtr->processed = 2;

            //enqueue from adjacency list
            arcWalkPtr = vertexPtr ->pArc;
            while(arcWalkPtr){
                vertToPtr = arcWalkPtr -> pArc
                if(vertToPtr->Processed ==0){
                    sucess = enqueue(queue, vertToPtr);
                    if(succes <0){printf("Queue Overflow 100 "), exit(100);}
                    vertToPtr -> processed =1; //ENQUEUED
                } 
                arcWalkPtr= arcWalkPtr->pNextArc;
            } //while p WalkArc
        } //while !emptyqueue
        walkPtr = walkPtr->pNextVertex; 
    }
    destroy(queue);
    return;
}        