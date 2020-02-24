
/*
LPI ch22 ex2 

If both a realtime and a standard signal are pending for a process, SUSv3 leaves it
unspecified which is delivered first. 

realtime signal(queue 시그널 )과 std signal(bitmask signal)들이 둘다 보류중일 때 , 
SUSv3 는 이들에 대해서 딱히 무엇이 먼저 처리 되어야 하는지 규정짓지 않았다("Unspecified")

Write a program that shows what Linux does in this case. 
(Have the program set up a handler for all signals, block signals for a
period time so that you can send various signals to it, and then unblock

핸들러를 설정한 뒤 , 일정 시간동안 모든 시그널을 블록하고나서 지금 보류중인 시그널을 보이고(queue시그널과 std시그널)
그러고 unblock 해서 두개의 시그널을 받아보아랑


*/
#define GNU_SOURCE
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
void 
inho_handler(int sig){
    //signal handler for all signal
    printf("***** Handler invoked! signal : %s signo %d *****\n", strsignal(sig), sig); //not safe 
    return ;
}

void 
pringSigset(const char * prefix , sigset_t *sigset)
{
    int sig, cnt;
    for(sig =1; sig<NSIG; sig++){
        if(sigismember(sigset, sig)){
            printf("%s%d (%s)\n", prefix , sig , strsignal(sig));
        }
    }
    if (cnt ==0 )
        printf("%s <empty signal set>", prefix);
}

int main(int argc , char * argv[])
{

    if (argc > 2 ){
        printf("USAGE : $ ./%s +#", argv[0]);
        printf("\t# : 1 (default stdsig -> quesig)\n");
        printf("\t  : 2 (quesig -> stdsig )\n");
        return 0;
    }
    printf("Process %d get Started . \n",getpid());
    struct sigaction queact, stdact;
    sigemptyset(&queact.sa_mask);sigemptyset(&stdact.sa_mask);
    queact.sa_flags =0 ; stdact.sa_flags =0;

    queact.sa_handler = inho_handler;
    stdact.sa_handler = inho_handler;
   
    int mypid  =getpid();
    union sigval sv;
    sv.sival_int = 1000;
    //1. 인터럽트 시그널과 리얼타임 시그널에 대해 핸들러를 설정하고,
    if (sigaction(SIGINT, &stdact, 0)< 0 ){
        perror("sigaction");
    }
    if (sigaction(SIGUSR1, &queact, 0)< 0 ){
        perror("sigaction");
    }
    sigaddset(&queact.sa_mask,SIGUSR1);

    sigset_t mask;
    sigset_t oldmask;
    sigset_t pending_sig;
    sigemptyset(&pending_sig);
    //int mypid = getpid();
    sigfillset(&mask);
    //2. 모오든 시그널을 블록하고
    if(sigprocmask(SIG_SETMASK, &mask, &oldmask) < 0){
        perror("sigprocmask1");
    }
    //block all signal
    /*critical code here*/
    if( atoi(argv[1]) == 1){ 
        raise(SIGINT);
        sigqueue(mypid, SIGUSR1, sv);
    }
    else{
        sigqueue(mypid, SIGUSR1,sv);
        raise(SIGINT);
    }
    //now we have 2 signal which is pending right now
    /*show pending signal! */
    if(sigpending(&pending_sig)<0){
        perror("sigpending"); 
    }
    //print pending signals
    pringSigset("pending signal", &pending_sig);

    printf("Press any key to continue process. (signals will unblocked)\n");
    getchar();
    //3. 일정 기간동안 만 블록 했고, 프로세스 내부적으로 raise 와 sigqueue를 이용해서 받았다
    if(sigprocmask(SIG_SETMASK, &oldmask, 0) < 0){
        perror("sigprocmask2");
    }
    //now handler will invoke

    printf("process %d exit Successfully...\n" ,getpid());
    return 0;

}
