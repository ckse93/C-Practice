#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

#define NTHREADS      100
#define LOOPS         100
int sum = 0;
int sleepFlag = 1;

void *do_work() {
  pthread_mutex_lock (&mutex); // comment this and "pthread_mutex_unlock(&mutex);" out and see what happens.
  int i;
  for (i=0; i<LOOPS; i++){
    if(sleepFlag)
      usleep(rand()%100);
    sum = sum + 1; // the point where critical section ocurrs
  }
  printf("sum : %d  |Thread ID :  %d\n",sum, (int)pthread_self());
  pthread_mutex_unlock(&mutex);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  if(argc > 1)
	sleepFlag = 0;
  srand(time(NULL));
  int i;
  pthread_t threads[NTHREADS];

  for (i=0; i<NTHREADS; i++)
    pthread_create(&threads[i], NULL, &do_work, NULL);

  for (i=0; i<NTHREADS; i++)
    pthread_join(threads[i], NULL);

  printf ("Thread sum: %d\n", sum);

  sum=0;
  for (i=0;i<NTHREADS * LOOPS;i++)
    sum = sum + 1;
  printf("Check sum:  %d\n",sum);

  pthread_exit(NULL);
}
