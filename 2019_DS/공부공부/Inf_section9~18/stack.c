
/*
데이터의 삽입과 삭제가 한쪽에서만 이루어지는 리스트이다.
LIFO
삭제가 되는 부분이 top이라고 부른다
*/

typedef struct{
    int top; 
    int data[10];
}Stack
//method
void push(int n){
    s.top++;
    if(s.top > s.data.length()){
        printf("stack is Full! \n");
        s.top --;
        return;
    }
    s.data[top] = n;
    return;
}
int pop(){
    int tmp ;
    if(s.top <0 ){
        printf("Stack is Empty\n");
        return -1;
    }
    tmp = s.data[top];
    s.top--;
    return tmp;
}
int peek(){
    return s.data[top]
}
bool IsEmpty(){
    if(s.top < 0)
        return true;
    else 
        return false;
}