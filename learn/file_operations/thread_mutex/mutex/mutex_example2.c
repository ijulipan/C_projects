#include <stdio.h>
#include <pthread.h>

static pthread_mutex_t g_mutex_lock;

void *thread_fun_1(void *data){
    pthread_mutex_lock(&g_mutex_lock);
    for (int i = 0; i < 10; i++){
        printf("hello\n");
        sleep(1);
    }
    pthread_mutex_unlock(&g_mutex_lock);
}

void *thread_fun_2(void *data){
    pthread_mutex_lock(&g_mutex_lock);
    for (int i = 0; i < 10; i++){
        printf("world\n");
        sleep(1);
    }
    pthread_mutex_unlock(&g_mutex_lock);
}

int main(){
    pthread_t pid[3];
    pthread_mutex_init(&g_mutex_lock, NULL);
    pthread_create(&pid[0], NULL, thread_fun_1, NULL);
    pthread_join(pid[0], NULL);
    pthread_create(&pid[1], NULL, thread_fun_2, NULL);
    pthread_join(pid[1], NULL);
    pthread_mutex_destroy(&g_mutex_lock);
    return 0;
}