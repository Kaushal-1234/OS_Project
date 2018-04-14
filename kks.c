# include<pthread.h>
# include<stdio.h>
# include<unistd.h>
# include<semaphore.h>
# include<sys/types.h>
void *producer();
void *consumer();
pthread_mutex_t entrance;
sem_t Empty;
sem_t Full;
int i1,i2,i3;
int main()
{
int n;
n=10;
sem_init(&Empty,0,n);
sem_init(&Full,0,0);
write(1,"Enter the number of times to run the problem:",45);
scanf("%d",&i1);
pthread_t t1[i1],t2[i1];
for(i2=0;i2<i1;i2++)
{
pthread_create(&t1[i2],NULL,producer,NULL);
pthread_create(&t2[i2],NULL,consumer,NULL);
}
for(i2=0;i2<i1;i2++)
{
pthread_join(t1[i2],NULL);
pthread_join(t2[i2],NULL);
}
}
void *producer()
{
{

sem_wait(&Empty);
pthread_mutex_lock(&entrance);
printf("\nProducer is producing an item inside the buffer");
printf("\nAn item produced");
sleep(1);
pthread_mutex_unlock(&entrance);
sem_post(&Full);
}
}
void *consumer()
{
{
sem_wait(&Full);
pthread_mutex_lock(&entrance);
printf("\nConsumer is consuming an item from the buffer");
printf("\nAn item consumed");
sleep(1);
pthread_mutex_unlock(&entrance);
sem_post(&Empty);
}
}
