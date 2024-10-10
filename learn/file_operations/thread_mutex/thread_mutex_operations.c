// Creating threads
#include <pthread.h>
int pthread_create(pthread_t *tidp, const pthread_attr_t *attr, (void*)(&start_rtn)(void*), void *arg);

pthread_t thrd1;
pthread_attr_t attr;
void thread_function(void *argument);
char *some_argument;
pthread_create(&thrd1, NULL, (void *)&thread_function, (void *) &some_argument);


// Ending Threads
pthread_exit(void *retval); // retval stores the thread's exit status
pthread_exit();


// Thread Wait
pthread_join(thrd1, NULL); // Wait for thread thrd1 to finish


// Thread Detach
int pthread_detach(pthread_t tid);