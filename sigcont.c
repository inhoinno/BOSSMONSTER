/*

Section 22.2 noted that if a stopped process that has established a handler for and
22.2 장에서 sigcont 에 대한 핸들러를 설정하고 sigcont를 블록한 프로세스에 대해서

blocked SIGCONT is later resumed as a consequence of receiving a SIGCONT, then the
프로세스가 다시 시작되었을 때 (sigcont 를 받아서), 그때 핸들러가 실행된다는 것을 보여라(sigcont를 블록 했을 때 만) 
handler is invoked only when SIGCONT is unblocked. Write a program to verify this.

Recall that a process can be stopped by typing the terminal suspend character
(usually Control-Z) and can be sent a SIGCONT signal using the command kill –CONT
(or implicitly, using the shell fg command).

*/
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
    void 
continue_handler(int sig) 
{
    //handler for sigcont 
    printf("**** Hi, %s Handler invoked ... ****\n", strsignal(sig));

}
int main()
{
    //1 set a handler for sigcont
    //2 block sigcont . use sigprocmask
    //3 suspend process(by Cntrl z)
    //4 in terminal, type kill -SIGCONT pid
    //5 see

    // sigaction(int sig , struct sigaction *new, struct sigaction *old)
    int i=0;
    int j=0;

    struct sigaction newact,oldact;
    sigset_t procmask,oldmask;
    sigemptyset(&procmask);
    sigaddset(&procmask, SIGCONT);
    sigemptyset(&oldmask);
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;
    newact.sa_handler = continue_handler;  // 핸들러를 설정하였음
    if(sigaction(SIGCONT, &newact, &oldact) <0){
        perror("sigaction"); exit(-1);
    }

    if(sigprocmask(SIG_SETMASK, &procmask, &oldmask)<0){
        perror("sigprocmask 1");
    }
    printf("Process %d get started ...\n", getpid());
    while(i<10){
        printf("%d\n", i++);
        sleep(2);
    }
    if (sigprocmask(SIG_SETMASK, &oldmask, 0)<0){
        perror("sigprocmask 2");
    }
    //**signal can delivered in here
    printf("unblock continue signal\n");
    printf("PID %d Exit Successfully..\n", getpid());
    exit(1);

}
