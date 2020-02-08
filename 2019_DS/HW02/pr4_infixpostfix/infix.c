// A + B = C ->  AB+
// A+B*C -> ABC*+
// {(a+b)*c+d-e/(f+g)-(h+j)*(k-l)}/(m-n)
// ->{ab+c*d+e- / fg+jh+kl-*}/mn-
//-> (ab+c*d+e-)(fg+jh+kl-*)/mn-/
// ab+c*d+e-fg+jh+kl-*/mn-/

//(a+b)*c/d + (a+b)
//-> ab+c*d/ab++
char * Get_String(char * s , int size){ 
    //띄어쓰기 판별
    int i;
    int j=0;
    char * p = (char*)malloc(sizeof(char)*size);
    for(i = 0 ; i<size; i++){
        if(s[i] != ' '){//띄어쓰기가 아니라면 받아적어야함
            p[j++] = s[i];
        }
        //else{ //띄어쓰기라면 skip 암것도 안해도 됨.        }
    }
    p[j] ='\0';
    return p;

}

char* String_Cp(char * s, int size){
    int i=0;
    char *p = (char*)malloc(sizeof(char)*size);
     for(i=0; i<size && s[i] != '\0'; i++){
        p[i] = s[i];
    }
    p[i] = '\0';
    return p;
}

bool range_check(int s, int e){
    if(e> s)
        return true;
    else 
        return false;
}

bool String_Check(char *s , int size){
    int i;
    int count=0;
    char *p = String_Cp(s, size);
    if(!HessesChecker(s)){ //false 라면
        printf("괄호오류\n");
        return false;
    }
    else{ //괄호갯수가 맞으면 + , a , ()만으로 이루어 졌는지 확인
        for(i=0; i<size; i++){
            if( isOpenHesses(str[i])||isCloseHesses(str[i])||isOperator(str[i])||isAlphabet(s[i]) ) continue;
            else return false;
        }
    }
    //괄호 갯수도 맞고 그러면 연산자 < 피연산자 확인 
    eraseHesses(p , size);
    for(i=0; p[i]; i++){ // i 는 널문자 까지, i+1이 사이즈
        if(isOperator(p[i])){// 연산자 갯수
            count_o ++;
        }
    }
    free(p);
    //연산자는 피연산자 보다 항상 1개 적다
    if( (i+1-count) - (count) != 1 )
        return false;
       
    return true;
}

bool HessesChecker(char *str){
    //올바른 괄호를 가지고 있는지 check
    struct stack s;
    int i=0;
    for(i=0; str[i]; i++){
        if(isOpenHesses(str[i])){ //열린 괄호 일땐
            push(s,str[i]);
        }
        else if(isCloseHesses(str[i])){ //닫힌괄호라면
            char ch = Get_Close_Char(seek(s));
            if(ch != str[i] ) // then error
                return false;
            else {
                ch = pop(s);
                if(ch == '\0'){
                    printf("닫힌괄호순서 에러\n");
                    return false;
                }
            }
        }
    }
    return true;
}

void eraseHesses(char * s, int size){
    //postfix는 괄호가 필요 없음
    char * p = (char *)malloc(sizeof(char)*size);
    int i;
    int j=0;
    for(i = 0; i<size && s[i] !='\0'; i++){
        if( !(isOpenHesses(s[i]) || isCloseHesses(s[i]) )){ // 알파벳, 또는 operator라면
            p[j++] = s[i];
        }
    }
    //String_cp 로 고쳐요
    p[j] = '\0';
    for(j=0; p[j]; j++){
        s[j] = p[j];
    }
    s[j]='\0';
    free(p);
    return ;
}

char Get_Close_Char(char ch){
    char cc;
    if(ch == '('){
        cc =')';
    }else if(s[i] == '{'){
        cc ='}';
    }else if(s[i] == '['){
        cc =']';
    } else {
        printf("닫힌괄호 찾는 도중 에러..\n");
        return '\0';
    }
    return cc;
}

int CloseH_Checker(char * s , int i , int size){
    char ch = Get_Close_Char(s[i]); // 이 열린괄호에 해당하는 닫힌괄호 ch
    if(ch == '\0') {
        printf("error in CloseH_Checker\n");
        return -1;
    }
    //닫힌괄호
    for(i; i<size && s[i]!='\0'; i++){
        if(s[i] == ch) // 닫힌괄호를 찾음
            return i;
    }
}
