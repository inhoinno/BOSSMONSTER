#include<stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 100
int main(){
    //자료구조 정의하기
    int n=0;
    char *words[100] //string 들이 각각 저장됨
    char buffer[BUFFER_SIZE]
    while(scanf("%s", buffer) != EOF){
        //1
        //words[n] = buffer; ->?가장 마지막의 단어만 연속해서 저장이 됩니다.
        //왜why 포인터들끼리의 치환문 이기 때문. words[0] = buffer word[1],[2],[3] =buffer .... 
        
        //2
        //strcpy. strcpy(words[n], buffer) ->? words[n]은 포인터임 스트링 아님.
        words[n++] = strdup(buffer); //복제본을 만들고 그 복제본의 주소값을 넘겨줌.
    }
    char * strdup(char *s){
        char *p ;
        p = (char*)malloc(strlen(s)+1)
        if(p!=NULL)
            strcpy(p,s);
        return p;
    }

}