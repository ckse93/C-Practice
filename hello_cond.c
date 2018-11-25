#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int GLOBAL_COUNT = 0;
char* string[] = {"Hello\n", "world!\n"};
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t CV = PTHREAD_COND_INITIALIZER;


void* odd_print(void* args){
    pthread_mutex_lock (&mutex);
    if (GLOBAL_COUNT %2 == 0){
        printf("global : %d, %s", GLOBAL_COUNT, string[0]);
        GLOBAL_COUNT++;
        printf("sending signal to conditional variable...\n");
        pthread_cond_signal(&CV);
    }
    else {
        printf("waiting...\n");
        pthread_cond_wait(&CV, &mutex);
    }
    pthread_mutex_unlock (&mutex);
    return NULL;
}

void * even_print(void*args){
    pthread_mutex_lock (&mutex);
    if (GLOBAL_COUNT %2 != 0){
        printf("global : %d, %s", GLOBAL_COUNT, string[1]);
        GLOBAL_COUNT++;
        printf("sending signal to conditional variable...\n");
        pthread_cond_signal(&CV);
    }
    else {
        printf("waiting...\n");
        pthread_cond_wait(&CV, &mutex);
    }
    pthread_mutex_unlock (&mutex);
    return NULL;
}

int main(int argc, char const *argv[])
{   
    pthread_mutex_init(&mutex,NULL);
    pthread_t thr1, thr2;
    //pthread_mutex_init

    pthread_t thread[50];
    
    for(int i = 0; i < 50; i+=2){
        int in = i;   
        pthread_create(&thread[i], NULL, odd_print, (void*)&in);
        pthread_create(&thread[i+1], NULL, even_print,(void*)&in+1);
    }

    for(int j =0; j<50; j++)
{
    pthread_join(thread[j], NULL);
}
   
    printf ("main :%s", string[0]);
    printf("%d", GLOBAL_COUNT);
    return 0;
}
