#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX 7
/*
 * Name: Dreyton Scott , Class: CPS470
 * Due: 9/27/16
 *
 */

int values[MAX],maximum,minimum,mean;


/*
 * Function: thread_mean(), returns the mean of list of values
 */
void *thread_mean(void *arg){
  int sum = 0, n = 0;
  while(n<MAX){
    sum += values[n];
    n++;
  }
  mean = sum/n;
  printf("MEAN:%d\n", mean);

  
  return NULL;
}


/*
 * Function: thread_min(), returns the lowest value in list
 */
void *thread_min(void *arg){
  int n = 0;
  minimum = values[0];
  while(n<MAX){
    if(minimum > values[n]){
      minimum = values[n];
    }
    n++;
  }
  printf("MINIMUM:%d\n", minimum);
  return NULL;
}


/*
 * Function: thread_max(), returnes the highest value in list
 */
void *thread_max(void *arg){
  int n = 0;
  maximum = values[0];
  while(n<MAX){
    if (maximum < values[n]){
      maximum = values[n];
    }
    n++;
  }
  printf("MAXIMUM:%d\n", maximum);
  return NULL;

}

/*
 * This is where main logic begins
 */
int main(int argc, char *argv[]){
  int value = 0,i=0,n;
  while(i<MAX && (n=scanf("%d", &value)) != EOF){
    values[i] = value;
    i++;
  }
  //initialize threads
  pthread_t meanthread, maxthread, minthread;

  pthread_create(&meanthread,
		 NULL,
		 thread_mean,
		 "Processing..."
		 );
  pthread_create(&maxthread,
		 NULL,
		 thread_max,
		 "Processing..."
		 );
  pthread_create(&minthread,
		 NULL,
		 thread_min,
		 "Processing..."
		 );
  
  pthread_join(meanthread,NULL);
  pthread_join(maxthread,NULL);
  pthread_join(minthread,NULL);
  exit(0); 
}

