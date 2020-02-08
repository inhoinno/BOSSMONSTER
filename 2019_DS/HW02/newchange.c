
int priority(char ch){
    char str = "+-/*"
    int i=0;
    switch (ch)
    {
    case '*'||'/':
        return 2;
        break;
    case '+'||'-':
        return 1;
        break;
    
    default:
        printf("wrong operator founded\n");
        break;
    }
    return 0;

}

void changetoPostfix(char *s , char *r){
    struct Stack st= Creat_Stack(10);
    int index=0;    //r = result
    int i=0;
    int j=0;
    int k=0;
    if(String_Check(s))
    for(i=0; s[i] != '\0'; i++){
        //error handle
        //(a*b+c)*c-d-e
        //st -
        // ab*c+c*d
        switch (s[i])
        {
        case '(': 
            //if 열린괄호이면 괄호안의 내용을 우선처리함
            //다음문자를 삽입?
            //stack push (
            //continue;
            push(st, s[i]);
            continue;
        case ')':
            // stack pop이 '('일때까지 pop함 
            while(seek(st) != '('){ //열린괄호를 만날때 까지 st에 있는 연산자를 pop해서 resutl
                r[k++] = pop(st);
            }
            pop(st);//"열린괄호 pop"
            break;
        case '*'||'/'||'+' ||'-';
            //이미있는 stack top 에 priority가 같다 -> stack pop출력
            // 더 높다 -> stack 삽입 (*)
            //연산자 stack push
            //  a/b-d-e-f-h
            //st -
            // ab/d-e-f-
            if(isSEmpty(st)){
                //스택이 비어있다면 그것은 맨처음 들어온 연산자 이다
                //바로 push 해주면 되겠다
                push(st, s[i]);
            }
            else if(priority(seek(st)) >= priority(s[i])){ //연산자 우선순위가 같거나 큰 녀석이 있다면 순서대로 처리하는게 원칙이므로 stack을 pop하고 resutl에 넣음
                //st * s[i] -or + then 
                //pop * and go to ressult[]
                //then push -or +
                r[k++] = pop(st);
                push(st, s[i]);
            }
            else if(priority(seek(st)) < priority(s[i]){ //a+b*c 에서 stack에 +가 있는데 *가 나왔다면?
            //*를 스택에 넣어야겠지?
                push(st, s[i]);
            }
            break;
        default:
            //문자는 바로 출력함
            //AB
            //특이사항이 없는경우 문자일것이고 
            r[k++] = s[i];
            break;
        }
    }
    //for문 종료시 stack에 +남아있음
    //result 에 append 후 return result.
    
    if(!isSEmpty(st)){
        while(!isSEmpty(st))    
            r[k++] = pop(st);
    }
    r[k] = '\0';
    return;

}