#include <stdio.h>
#include <pthread.h>

static pthread_mutex_t g_mutex_lock;
static int g_count = 0;

void *thread_fun_1(void *data){
    pthread_mutex_lock(&g_mutex_lock);
    g_count++;
    printf("%s g_count: %d\n", __func__, g_count);
    pthread_mutex_unlock(&g_mutex_lock);
}

int main(){
    pthread_t pid[3];
    pthread_mutex_init(&g_mutex_lock, NULL);
    pthread_create(&pid[0], NULL, thread_fun_1, NULL);
    pthread_join(pid[0], NULL);
    pthread_mutex_destroy(&g_mutex_lock);
    return 0;
}