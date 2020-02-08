/*
32152332 송인호 기본적인 선형리스트 functions
리스트 생성
head add item(head)
head rm item (head, int)
head rm firstitem (head)
head find item(list, data)

head

* node = 첫 노드 
data = list 갯수

*/o n
//생성
typedef struct NODE{
    int data
    struct Node * next;
}; 
struct NODE * List_Head(){
    struct NODE * head;
    head = make_Node(0);
    return head;
}
//노드생성
struct NODE make_Node(int d){
    struct NODE * fnode = malloc(sizeof(struct NODE));
    fnode-> data = d;
    fnode-> next =NULL;
    return fnode;
}
// struct NODE L = List_Head(make_Node(10));
void add_first(struct NODE * L, int d){
    struct NODE * newNode = make_Node(d);
    //순서 매우 중요 !
    newNode->next = L->next;
    L->next = newNode;
    L->data +=1;
    return ;
}
void add_end(struct NODE * L ,int d){
    struct NODE * tnode = L;
    struct NODE newNode = make_Node(d);
    //while(tnode->next != NULL){//끝에 오면 d를 추가
        //tnode 는 맨 끝의 노드를 가리킴
        //iterate
    myIterator(tnode);
    tnode->next = newNode;
    L->data += 1;
    return ;
}

//순회 함수
void myIterator(struct NODE * head){
    while (head->next != NULL){
        head = head->next;
    }
    return ;
    //NO myItator(L);
}
//list 길이 = L->data 값
int List_length(struct NODE * head){
    return head->data;
}



//remove

//search
