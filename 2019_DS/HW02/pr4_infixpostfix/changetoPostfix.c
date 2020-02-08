char * changetoPostfix(char * s, int start ,int end){
    // start 부터 end 까지 바꾸는것
    //"(a+b)*c/d+(a+b)" -> ab+c*d/ab++
    // -> (ab+)c*d/(ab+)+
    //"a+b*c/d+a+b" -> abc*+d/ab+
    int tmp_size = end - start +2;
    char * p = (char*)malloc(sizeof(char)*(tmp_size)); //배열 p, size = end - start+1,             
    struct Stack * stack Create_Stack(15);
    int i ;
    int k =0;
    //check hesses
    if(range_check(start, end)){
    for(i=start; i<=end; i++){
        if(isOpenHesses(s[i])){ //({[열린 괄호 라면!! 우선순위 적용
            int tmp =0;
            tmp = CloseH_Checker(s, i , end+1); //이렇게 하면 tmp 는 닫힌 괄호의 인덱스를 가지게 됨. i 0 tmp 4
            if(tmp < 0 ){ //error 핸들링
                return "error in changetoPostfix(tmp)\n";
            }
            p = changetoPostfix(s, i+1, tmp-1);
            //i는 열린 괄호의 인덱스이고, tmp 는 닫힌괄호의 index
            //그래서 s는 i+1 부터 tmp -1까지 수정되어야 한다
            cpstr(s, i+1 , tmp -1 ,p ,tmp);
            i =tmp+1; //i는 괄호 바로 뒤  부터 다시 시작
        }
        else if(isOperator(s[i])){// +-*/
            push(stack, s[i]);
            continue;
        } 
        else if(isAlphabet(s[i])){ //괄호도 아니고 operator도 아니야, 그럼 이건 문자다 이게 내 결론이다.
            //is스택 탑ㅇ이 *나 /임? -> true then pop stack -> false then 넘어가
            //s의 start부터 end까지 수정하는 것
            p[k] = s[i];
            k++;
            if(seek(stack)== '*' || top(stack)=='/'){ // 곱하기거나 나누기이면
                p[k] = pop(stack);//바로수행
                k++;
            }
        }
    }
    if(isSEmpty(stack)) {//stack 에 오퍼레이터가 남아있다면 아마도 ++들
        for(k; isSEmpty(stack); k++){
            p[k] = pop(stack);
        } //append
        p[k] = '\0'; 
    }
    else{
        p[k] = '\0';
    }
    return p;
}