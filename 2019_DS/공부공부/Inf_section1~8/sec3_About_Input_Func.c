#include<stdio.h>
#define MAX_BUFFER_SIZE 100
int String_length(char*);
int read_line(char[], int);
int main(){
	char str[MAX_BUFFER_SIZE];

	while (1){
		printf("$ ");
//		fgets(str, MAX_BUFFER_SIZE, stdin);
		int len = read_line(str, MAX_BUFFER_SIZE);
		if (str[0] == '\0') break;
		printf("%s:%d\n", str,len);
	}
	printf("Program terminated..\n");
	return 0;
}// 1234\0 -> 0~4, 5
int String_length(char * s){
	int i = 0;
	for (i = 0; s[i] != '\0'; i++){}
		
	return i;

}
int read_line(char str[], int limit){
	int ch, i = 0;
	while ((ch = getchar()) != '\n')
		if (i < limit)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}
/*problem1. scanf(%s)
$ whatif string longerthan hundred?
whatif:6
$ string:6
$ longerthan:10
$ hundred?:8
$
gets scanf fgets 모두 적합하지 않아서 input의 경우 따로 함수를 만들 때가 많음.
problem2. fgets(), input length > MAX_BUFFER_SIZE
if BUFFER_SIZE = 10,
$ abcbcbbabcbcb
abcbcbba:8
$ bcb:3
$

*/