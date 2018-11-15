#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//make sure to add "-pthread" option when compiling

void * print_thread_info (void * input){
  pid_t pid = getpid(); // current process ID
  pthread_t thread_id = pthread_self(); // current thread ID
  char* thread_name = (char*)input;
  printf("thread name : %s  |  PID : %d  |  thread_id = %d\n",thread_name, (int)pid, (int)thread_id);
  return NULL;
}

int main(int argc, char const *argv[]) {
  pthread_t threads[2];
  char p0[] = "threads[0]";
  char p1[] = "threads[1]";
  char p2[] = "threads[2]";
  printf("%s\n","starting..." );
  pthread_create (&threads[0], NULL, print_thread_info, (void*)p0);
  pthread_create (&threads[1], NULL, print_thread_info, (void*)p1);
  pthread_create (&threads[2], NULL, print_thread_info, (void*)p2);
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  pthread_join(threads[2], NULL);
  printf("%s\n\n", "ending...");
  printf("the reason threads are not in order -- sometimes it may be in order, if so, you are lucky \n is that threads are created and some thread may reach the line 12 faster than other threads");
  return 0;
}
