#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/time.h>
#define MaxThreadNum 32
#define kSamplePoints 100000000
#define kSpace 16	// >= 16 性能接近
void *compute_pi(void *);
inline double WallTime();

int total_hits, hits[MaxThreadNum][kSpace];
int sample_points_per_thread, num_threads;


int main123(void)
{
	printf("%d\n",sizeof(int));
   int i;
   double time_start, time_end;

   pthread_t  p_threads[MaxThreadNum];
   pthread_attr_t attr;

   pthread_attr_init(&attr);
   pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
   printf("Enter num_threads\n");
//   scanf("%d", &num_threads);
   num_threads = 16;

   int k = 10;
   while (k--) {
	   time_start = WallTime();

	   total_hits = 0;
	   sample_points_per_thread = kSamplePoints / num_threads;

	   for(i=0; i<num_threads; i++)
	   {
		   hits[i][0] = i;
		   pthread_create(&p_threads[i], &attr, compute_pi, (void *)&hits[i]);
	   }

	   for(i=0; i<num_threads; i++)
	   {
		   pthread_join(p_threads[i], NULL);
		   total_hits += hits[i][0];
	   }

	   double pi = 4.0 * (double)total_hits / kSamplePoints;
	   time_end = WallTime();
	   printf("Elasped time: %lf, Pi: %lf\n", time_end - time_start, pi);
   }
   return 0;

}

void *compute_pi(void * s)
{
    unsigned int seed;
    int i;
    int *hit_pointer;
    double rand_no_x, rand_no_y;
    int local_hits;

    hit_pointer = (int *)s;
    seed = *hit_pointer;
    local_hits = 0;

    for(i=0; i<sample_points_per_thread; i++)
    {
       rand_no_x = (double)(rand_r(&seed))/(double)(RAND_MAX);
       rand_no_y = (double)(rand_r(&seed))/(double)(RAND_MAX);
       if((rand_no_x - 0.5)*(rand_no_x - 0.5) + (rand_no_y - 0.5) * (rand_no_y - 0.5) < 0.25)
          (*hit_pointer)++;
//        ++local_hits;
       seed *= i;
     }
//     *hit_pointer = local_hits;
     pthread_exit(0);
}

inline double WallTime()
{
    struct timeval tv;
    struct timezone tz;

    gettimeofday(&tv, &tz);

    double currTime =  (double)tv.tv_sec + (double)tv.tv_usec/1000000.0;

    return currTime;
}
