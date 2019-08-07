#include <pthread.h>
#include <stdio.h>

#define THREAD 5

void *runner(void *param);

int main(int argc, char *argv[])
{
    int i, scope;
    pthread_t tid[THREAD];
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    if(pthread_attr_getscope(&attr, &scope) != 0){
        fprintf(stderr, "fAIL\n");
    }
    else{
        if(scope == PTHREAD_SCOPE_PROCESS) 
        {
            printf("process\n");
        }
        else if(scope == PTHREAD_SCOPE_SYSTEM) 
        {
            printf("SYSTEM\n");
        }
        else {
            fprintf(stderr, "fail\n");
        }
    }

    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

    for(i = 0;i < THREAD; i++){
        pthread_create(&tid[i], &attr, runner, NULL);
    }

    for(i = 0; i < THREAD; i++){
        pthread_join(tid[i], NULL);
    }
}

void *runner(void *param)
{
    printf("running\n");

    pthread_exit(0);
}
