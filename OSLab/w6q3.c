#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 4
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4) % N
#define RIGHT (phnum + 1) % N

int phil[N];
int times = 200;

struct monitor
{
    int state[N];
    pthread_cond_t phcond[N];
    pthread_mutex_t condLock;
};

void test(struct monitor *m, int phnum)
{
    if (m->state[(phnum + 1) % 5] != EATING && m->state[(phnum + 4) % 5] != EATING && m->state[phnum] == HUNGRY)
    {
        m->state[phnum] = EATING;
        pthread_cond_signal(&m->phcond[phnum]);
    }
}

void take_fork(struct monitor *m, int phnum)
{
    pthread_mutex_lock(&m->condLock);
    m->state[phnum] = HUNGRY;
    test(m, phnum);
    if (m->state[phnum] != EATING)
        pthread_cond_wait(&m->phcond[phnum], &m->condLock);
    pthread_mutex_unlock(&m->condLock);
}

void put_fork(struct monitor *m, int phnum)
{
    pthread_mutex_lock(&m->condLock);
    m->state[phnum] = THINKING;
    test(m, RIGHT);
    test(m, LEFT);
    pthread_mutex_unlock(&m->condLock);
}

void init_monitor(struct monitor *m)
{
    for (int i = 0; i < N; i++)
        m->state[i] = THINKING;
    for (int i = 0; i < N; i++)
        pthread_cond_init(&m->phcond[i], NULL);
    pthread_mutex_init(&m->condLock, NULL);
}

void destroy_monitor(struct monitor *m)
{
    for (int i = 0; i < N; i++)

        pthread_cond_destroy(&m->phcond[i]);

    pthread_mutex_destroy(&m->condLock);
}

struct monitor phil_object;

void *philosopher(void *arg)
{
    int c = 0;
    while (c < times)
    {
        int i = *(int *)arg;
        printf("Philosopher %d is thinking...\n", i + 1);
        sleep(3);
        printf("Philosopher %d is waiting...\n", i + 1);
        take_fork(&phil_object, i);
        printf("Philosopher %d is eating...\n", i + 1);
        sleep(2);
        put_fork(&phil_object, i);
        printf("Philosopher %d eated...\n", i + 1);
        c++;
    }
    return NULL;
}

int main()
{
    srand(time(0));
    pthread_t thread_id[N];
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (int i = 0; i < N; i++)

        phil[i] = i;

    init_monitor(&phil_object);

    for (int i = 0; i < N; i++)

        pthread_create(&thread_id[i], &attr, philosopher, &phil[i]);

    for (int i = 0; i < N; i++)

        pthread_join(thread_id[i], NULL);

    destroy_monitor(&phil_object);

    pthread_attr_destroy(&attr);
    pthread_exit(NULL);

    return 0;
}
