#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 2

int buffer[BUFFER_SIZE];
int count = 0;
int in = 0, out = 0;

sem_t empty, full, mutex;
int stop = 0;

void *producer(void *param)
{
    int item;
    while (!stop)
    {
        item = rand() % 100;

        int empty_value;
        sem_getvalue(&empty, &empty_value);
        if (empty_value == 0)
            printf("Producer waiting for empty slot...\n");
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        printf("Producer produced: %d (buffer count: %d)\n", item, count);

        sem_post(&mutex);
        sem_post(&full);
        sleep(4);
    }
    return NULL;
}

void *consumer(void *param)
{
    int item;
    while (!stop)
    {
        int full_value;
        sem_getvalue(&full, &full_value);
        if (full_value == 0)
            printf("Consumer waiting for full slot...\n");
        sem_wait(&full);
        sem_wait(&mutex);

        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        printf("Consumer consumed: %d (buffer count: %d)\n", item, count);

        sem_post(&mutex);
        sem_post(&empty);
        sleep(rand() % 6 + 1);
    }
    return NULL;
}

int main()
{
    printf("Enter q to quit\n");
    pthread_t producer_thread, consumer_thread;

    srand(time(NULL));

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    if (getchar() == 'q')
        stop = 1;
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
