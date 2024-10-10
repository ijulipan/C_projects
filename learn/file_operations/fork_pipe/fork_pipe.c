#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t pid;
    pid = fork();
    if(pid == 0){ // Returns child process
        printf("Child PID: %d\n", getpid());
    } else {
        printf("PID: %d\n", pid); // In parent process, returns child process ID
        printf("Father PID: %d\n", getpid());
    }

}
