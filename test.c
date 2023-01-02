#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#define MAX_THREADS 10

int sum; /* this data is shared by the thread(s) */
void *runner(void * param);

int main(int argc, char *argv[])
{
  int num_threads, i;
  pthread_t tid[MAX_THREADS];     /* the thread identifiers  */
  pthread_attr_t attr; /* set of thread attributes */

  if (argc != 2) {
    fprintf(stderr, "usage:  test <integer value>\n");
    exit(EXIT_FAILURE);
  }

  if (atoi(argv[1]) <= 0) {
    fprintf(stderr,"%d must be > 0\n", atoi(argv[1]));
    exit(EXIT_FAILURE);
  }

  if (atoi(argv[1]) > MAX_THREADS) {
    fprintf(stderr,"%d must be <= %d\n", atoi(argv[1]), MAX_THREADS);
    exit(EXIT_FAILURE);
  }

  num_threads = atoi(argv[1]);
  printf("The number of threads is %d\n", num_threads);

  /* get the default attributes */
  pthread_attr_init(&attr);

  /* create the threads */
  for (i=0; i<num_threads; i++) {
    // pthread_create(&(tid[i]), &attr, runner, (void *)(intptr_t) i);
    printf("Creating thread number %d, tid=%lu \n", i, tid[i]);
  }

  /* now wait for the threads to exit */
  for (i=0; i<num_threads; i++) {
    pthread_join(tid[i],NULL);
  }
  return 0;
}

/* The thread will begin control in this function */
void *runner(void * param)
{
  int i;
  //int threadnumber = (int) param;
  //int threadnumber = (long) param;
  int threadnumber = (intptr_t) param;
  
  for (i=0; i<1000; i++) printf("Thread number=%d, i=%d\n", threadnumber, i);
  pthread_exit(0);
}
