/*inhoshell.c a simple myshell including redirection
32152332@dankook.ac.kr inho song date :2019 10 28 ~ 11 05*/
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include <errno.h>
#define _CRT_SECURE_NO_WARNINGS //define for strtok error

int tokenize(char * line , char* token[] , int max_token){
	//line 의 공백을 읽어서 token 들을 token[]에 담아준다.
	//use strtok func
	//read line -> to token[]
	int cnt_tk =0;
	char cut_[3] = " \n";
	char* tok=NULL;
	tok = strtok(line ,cut_); /*now tok = argv[0]*/
	//error hdling for strtok
	if(tok == NULL){return 0;}	 
	if ((strcmp(tok, "exit")==0)||(strcmp(tok, "\n")==0)) /*then no input exists -> go to shell*/	
		return -1;
	
	while(tok && cnt_tk < max_token){ /* tokenizing */
		
		token[cnt_tk++] = tok;
		tok = strtok(NULL ,cut_);
	}
	token[cnt_tk] ='\0'; /* now token[i] = argv[i] */
	
	//show token that initialized
	int t =0;
	for(; t<cnt_tk;t++)
		printf("token[%d]: %s\n",t,token[t]);
	
	//end showing token.
	
	return cnt_tk; /*if sucess then return token num*/

}
bool internal_command(char * token[] , int token_count){
	/*for internal command -> dont use fork and exev*/
	/*pwd cd kill*/
	if(strcmp(token[0] , "cd") == 0){
		if(chdir(token[1]) <0){	printf("cd fail..err %d\n", errno);}
		return true;
	}
	else if(strcmp(token[0], "pwd")== 0){
		printf("%s \n",get_current_dir_name());
		return true;
	}
	else if(strcmp(token[0], "kill")== 0){
		if(token_count != 2){printf("kill fail.. input pid\n");}
		else if(kill((pid_t)token[1], SIGKILL) < 0){
			printf("fail to kill %d ..sorry ㅠㅡㅠ\n",token[1]);}
		return true;
	}//else if(strcmp(token[0], "help")==0){inho_shell_help(); return true;}
	else if(strcmp(token[0], "inho")==0 || strcmp(token[0], "32152332")==0 ){
		printf("안녕하세요 ? ** ^_^ ** \n 이스터 에그를 발견하셨군요!\n");
		printf("부끄러우니 그만 종료하겠습니다.ㅎㅅㅎ 안녕!\n");
		sleep(2);
		printf("힝!  속았지! XD \n");
		return true;
	}
	return false;
}
void check_redirection(char* token[], int token_size , int* redir, bool* append){
//check tokens that it contains redirection
int i=0;
while(token[i]!=NULL && i< token_size){
	if((strcmp(token[i], ">")==0)){ redir[1] = i; redir[3]=1;}
	else if(strcmp(token[i], "<")==0){ redir[0] = i; redir[3]=1;}
	else if(strcmp(token[i], ">>")==0){redir[1]= i; *append=true;redir[3]=1;}
	else if(strcmp(token[i], "2>")==0){redir[2]= i;redir[3]=i;}
i++;
}
/*show token and redir[]*/
return;
}

void token_rearrange(char* token[] , int* token_size){
//re arrange token according to redirection 	
//bool tok_red[4] = {redir[0], redir[1], redir[2], redir[3]};
//case 1 : ./program < a.txt > b.txt then rearrange like ./program \0
//case 2 : cat a.txt > b.txt then rearrange like cat a.txt
int i=0;
printf("...token rearrange..."); 
while(i<*(token_size) && token[i] != '\0'){
if((strcmp(token[i], ">")==0)){token[i]='\0';token[i+1]='\0'; *(token_size) -= 2;}
else if((strcmp(token[i], "<")==0)){token[i]='\0'; token[i+1]='\0'; *(token_size)-=2;}
else if((strcmp(token[i],"2>")==0)){token[i]='\0'; token[i+1]='\0'; *(token_size)-=2;}
else if((strcmp(token[i],">>")==0)){token[i]='\0'; token[i+1]='\0'; *(token_size)-=2;}

i++;
}
return;
}
bool run(char * line){
	int token_count, fork_return;
	int fd; // redirection in out 
	// 0stdin 1stdout 2input index 3output index  define MARCO. 
	int saved_std[3];
	// [0] stdin [1] stdout [2] stderr
	int redir[4]= {0}; 
	// [0]for stdin, [1] stdout [2] stderr [3]for any redirection bit
	bool background = false;
	bool redirOUT = false, redirIN =false, redirERR=false;
	bool r_append = false;
	char* token[10]= {'\0'};
	int fd_arg[4];// 0stdin 1stdout 2stderr 3free
	int i=0;
	token_count = tokenize(line, token, sizeof(token)/sizeof(char*));
	if(token_count < 0 ){ return false;} /* then "exit" or \n */
	if(token_count == 0 ){return true; }
	//then token counted

	/* check redirection */
	check_redirection(token, token_count, redir, &r_append);
	/* now redirection checked, redir[] set. */
if(redir[3]){		/*do redirection according to redir[]*/

	if(redir[1]){	//redirect for out
		int flags = O_RDWR|O_CREAT;
		if(r_append) flags |= O_APPEND; 
		if((fd_arg[1] = open(token[redir[1]+1], flags, 0666))<0){perror("wrong fd STDOUT. ");}
		saved_std[1] =dup(1);
		dup2(fd_arg[1], 1);
		redir[3] =true;
	}// for redirection > out
	else if(redir[0]){if((fd_arg[0] = open(token[redir[0]+1], O_RDONLY))<0){perror("wrong fd STDIN.");}
		saved_std[0] = dup(0);
		dup2(fd_arg[0],0);  redir[3]=true;
	}// for redirection < in	
	else if(redir[2]){
		if((fd_arg[2]= open(token[redir[2]+1], O_RDWR|O_CREAT|O_APPEND , 0666)<0)){
		perror("wrond fd STDERR");}
		saved_std[2] =dup(2);
		dup2(fd_arg[2], 2);  redir[3] =true;
	}// for redirection 2> err
	
	/*token re-arrange*//*32152332 *^^* 송인호*/
		// ./program < a.txt > b.txt 
		// re-arrange : ./program 
	token_rearrange(token, &token_count);
}

	/*check background processing*/
	if(strcmp(token[token_count-1], "&")==0){
	//last token == & then background processing
	background= true;}
		
	/*check internal*/
	if (internal_command(token, token_count)){
	 	return true;
	} 	

	/*check external then fork() */
	if((fork_return = fork())< 0 ){ perror("fork error encounted. ");}
	else if(fork_return == 0){ // then this is child process
		//execl cat or other external command . 
			execvp(token[0], token);
			perror("in child, errr ocurred during exev.");
			exit(1);	
	}	
	else{ //then parent process
		if(!background) /*if run in background, no wait() call */
			wait();
		/*for redirection, reset stdin, stdout, stderr*/
		if(redir[3]){ //[3] : any redirection bit is true then
			if(redir[1])
				{dup2(saved_std[1], 1); close(saved_std[1]);}
			if(redir[0])
				{dup2(saved_std[0], 0); close(saved_std[0]);}
			if(redir[2])
				{dup2(saved_std[0], 2); close(saved_std[2]);}
		}	
		return true;
		
	} // then parent
	printf("Help -> type 'help' :)\n");
	return true;	
}
int main(){
	char line[256];
	while(1){
		printf("%s Inho$ ",get_current_dir_name());
		fgets(line, sizeof(line)-1, stdin);
		if(run(line) == false){ break;}
	}	
	exit(0);
}
