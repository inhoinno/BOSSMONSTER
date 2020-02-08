struct Stack {
    int top;  //top은 삽입될 값의 인덱스
    char* data ;
    int size ;
};
struct Stack * Creat_Stack(int d){
    struct Stack * s = malloc(sizeof(struct Stack));
    s->size = d;
    s->data = (char*)malloc(sizeof(char)*d);
    return s;
}
char seek(struct Stack *s){
    if(isSEmpty(s)){
        printf("stack is empty");
        return '\0';
    }
    return s->data[s->top];
}
bool isSEmpty(struct Stack *s){ //스택이 비었다면 true를 반환
    if(s->top == 0){ //then stack is empty
        return true;
    }
    return false;
}
bool isSFull(struct Stack *s){
    if(s->top == s->size){//then stack is full
        return true;
    }
    return false;
}
void push(struct Stack *s , char ch){
    if(isSFull(s)){
        printf("stack is Full..\n");
        return ;
    }
    s->data[top] = ch;
    s->top ++;
    return;
}

char pop(struct Stack * s){
    if(isSEmpty(s)){// then stack is Empty
        printf("Stack is empty\n");
        return '\0'
    }
    s->top -= 1 ;
    return s->data[top];
}
