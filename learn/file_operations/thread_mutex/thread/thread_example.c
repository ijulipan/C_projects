#include <stdio.h>
#include <pthread.h>

void print_message_function(void *ptr);

int main(){
    pthread_t thread1, thread2;
    char *message1 = "thread1";
    char *message2 = "thread2";

    pthread_create(&thread1, NULL, &print_message_function, message1);
    pthread_create(&thread2, NULL, &print_message_function, message2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

void print_message_function(void *ptr){
    for (int i = 0; i < 5; i++){
        printf("%s: %d\n", (char *)ptr, i);
    }
}