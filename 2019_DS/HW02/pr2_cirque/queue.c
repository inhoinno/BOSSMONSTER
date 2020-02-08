/*
원형큐 20개
구현하기

queue
front 
rear 
size
data

push
pop
seek
is queue empty
lastoperation



*/ 

struct cir_queue * Q = Create_Q(20);
    for(i = 1; i< 20 ; i++)
        enqueue(Q, i);
    showQueue(Q);
    printf("%d\n", dequeue(Q));
    printf("%d\n", dequeue(Q));
    printf("%d\n", dequeue(Q));
    enqueue(Q, 19);
    enqueue(Q, 21);
    enqueue(Q, 22);
    enqueue(Q, 23);
    showQueue(Q);

    
struct cir_queue{
    int front = -1;
    int rear = 0;
    int size;
    int * data = NULL;
    bool operator = false;
}
struct cir_queue * Create_Q(int size){
    struct cir_queue * Q = malloc(sizeof(struct cir_queue));
    Q->data = (int)malloc(sizeof(int)*size);
    Q->size = size;
    return Q;
}
void enqueue(struct cir_queue * q , int d){
    //rear는 무조건 제일 마지막 에 들어온 원소 인덱스를 참조한다.
    //enque 되면 rear +1 해서 해당 위치에 넣는다
    // if front == rear? is Q Full 로 체크 후 삽입
    int N = q->size; 
    if(isQFull(q)){ //다 차있다면 
        printf("Q is Full. \n");
        return ;
    }
    if(q->front == -1)  
        q->front =0;
    
    rear = (rear+1)%N;
    q->data[rear] = d;
    q->operator = true; //enque true , qfull ->true
    return ;
}
int dequeue(struct cir_queue * q){
    //front 는 무조건 원소 앞을 참조한다
    //deque 하면 front +1 되고 그 위치를 반환함
    //front = (front+1)%N
    // If front == rear ? is q Empty 로 체크
    int N = q->size;
    if (isQEmpty(queue)){ // q에 아무것도 없다면
        printf("Q is Empty. \n");
        return ; //f -1 r 0
    }
    front = (front +1)%N;
    q->operator = false;
    return q->data[front];
}
int seek(struct cir_queue * q){
    if(isQEmpty(q)){
        printf("queue is empty. No element shown\n");
        return -1;
    }
    else
        return q->data[rear];
}
bool isQFull(){
    if(q->front == q->rear && q->operator == true)//then q is full
        return true;
    else
        return false;
}
bool isQEmpty(struct cir_queue * q){
    if(q->front == -1) //f -1 then 한번도 enque된적이 없느것
        return true;
    if(q->front == q->rear && q->opeartor == false)// 
        return true;
    else 
        return false;
}
void showQueue(struct cir_queue * q){
    int i;
    for(i =0; i<q->size; i++)
        printf("%d ", q->data[i]);
    printf("\n");
    printf("%d elements shown...\n", q->size);  
    return ;

}