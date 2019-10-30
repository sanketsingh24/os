#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void *thread1(void *param);
void *thread2(void *param);

pthread_mutex_t mutex1, mutex2;

int main(){
    pthread_t id1, id2;
    pthread_attr_t attr1, attr2;

    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);

    pthread_create(&id1, &attr1, thread1, NULL);
    pthread_create(&id2, &attr2, thread2, NULL);

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
}

void *thread1(void *param){
    pthread_mutex_lock(&mutex1);
    pthread_mutex_lock(&mutex2);

    printf("Thread 1\n");

    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);

    pthread_exit(0);
}

void *thread2(void *param){
    pthread_mutex_lock(&mutex2);
    pthread_mutex_lock(&mutex1);

    printf("thread 2\n");

    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);

    pthread_exit(0);
}
