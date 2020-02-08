/* 1. mycopy.c , cp_inho.out
   2. a.txt(argv[1])을 읽고 b.txt(argv[2])를 생성하여 내용을 복사하는 프로그램.
    이미 b.txt가 있다면, 새로생성하지 말고 그것을 실패로 처리. (O_EXCL)
    + (bonus) 파일의 속성정보까지 읽어서 새롭게 생성하는 프로그램.
   3. by 32152332 송인호 
   4. mearrong123@gmail.com 
    */
#include "inhofile.h"
#define MAX_BUF 64
int main (int argc,char * argv[]){
        // ./inhocp a.txt b.txt
        //  ㅅargv[0] ㅅargv[1]ㅅargv[2]
        int fd1,fd2,stat1;
        int file_size=0;
        int read_size, write_size;
        char buff[MAX_BUF];
        struct stat stat_buf; /*struct for copy a.txt 's attributes*/

        if(argc != 3 ){ printf("WRONG USAGE! \n USAGE : %s (copy) file_A (to) file_B\n ");}
        /*error handling for usage*/
        fd1 = open(argv[1], O_RDONLY);          /* open a.txt = fd1 */
        if(fd1<0){ printf("CANT OPEN %s , : ERROR NUMBER %d , \n",argv[1], errno); exit(-1);}
        /*error handling for file_A*/

        stat1 = fstat(fd1, &stat_buf); /*read file's atrributes to stat_buf*/
        if(stat1 < 0){printf("stat error :  %d\n",errno); exit(-1);}
        printf("att -> %lo\n",(unsigned long)stat_buf.st_mode);


        fd2 =open(argv[2], O_WRONLY|O_CREAT|O_EXCL, stat_buf.st_mode); /*NOW fd2 = b.txt*/
        if(fd2<0){ printf("ERROR while creat %s... ERROR num :%d\n",argv[2], errno); exit(-1);}


        /*read a.txt size MAX_BUF while , and write at b.txt*/
        while(true){
                read_size = read(fd1, buff, MAX_BUF);
                if(read_size < 0 ){printf("read error! \n"); exit(-1);}
                if(read_size == 0){ break ;}
                write_size = write(fd2, buff, read_size);
                if(write_size <0 ){printf("write error! \n"); exit(-1);}
                file_size += write_size;
        }
        close(fd1);
        close(fd2);
        /*show file size at STDOUT_FILENO*/
        printf("cp size = %d\n", write_size);
        return 0;

}   