#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#define MAX_BUF 4096
//cp a.txt b.txt

int main(int argc,char *argv[]){
struct stat file_mode;
int mode, read_size;
char buf[MAX_BUF];
int fd[2];

if(argc!=3){
printf("USAGE:%s input_file_name output_file_name\n",argv[0]);
exit(0);
}

fd[0]=open(argv[1],O_RDWR);
if(fd[0]<0){
printf("Open Fail! %d\n");
exit(-1);
}

fstat(fd[0],&file_mode);
fd[1]=open(argv[2],O_RDWR|O_CREAT|O_EXCL,file_mode.st_mode);
if(fd[1]==-1){
printf("Filename exists!\n");
exit(-1);
}

while(1){
read_size=read(fd[0],buf,MAX_BUF);
if(!read_size){
break;}
write(fd[1],buf,read_size);
}
close(fd[0]);
close(fd[1]); //추가
}
