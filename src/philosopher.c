/* 
* @Author: Erick Lucena Palmeira Silva
* @Date:   2015-03-21 15:46:22
* @Last Modified by:   Erick Lucena Palmeira Silva
* @Last Modified time: 2015-03-27 02:25:18
*/

#include "philosopher.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#define THINKING_MAX_TIME 1
#define EATING_MAX_TIME 1

int nPhilosophers;
int *philosopherId;
int *plates;
pthread_mutex_t *forks;
pthread_t *philosophers;

void setTable (int seats, int meals)
{
    int i;

    nPhilosophers = seats;
    plates = calloc(sizeof(int), seats);
    philosopherId = calloc(sizeof(int), seats);
    forks = malloc(sizeof(pthread_mutex_t)*seats);
    philosophers = malloc(sizeof(pthread_t)*seats);

    for (i=0; i< seats; i++)
    {
        philosopherId[i] = i;
        plates[i] = meals;
        if (pthread_create(&philosophers[i], NULL, philosopher, &philosopherId[i]))
        {
            fprintf(stderr, "Error creating thread\n");
            exit(1);
        }
    }

    for (i=0; i< seats; i++)
    {
        if(pthread_join(philosophers[i], NULL))
        {
            fprintf(stderr, "Error joining thread\n");
            exit(1);
        }
    }


}

void* philosopher (void* arg)
{

    int *id;

    id = (int*) arg;

    while(plates[*id] != 0)
    {
        think(*id);
        eat(*id);
    }

    return NULL;

}

void think (int id)
{
    srand(time(NULL));
    printf("Philosopher %d thinking\n", id+1);
    sleep(rand()%THINKING_MAX_TIME);
}

void eat(int id)
{
    int firstForkId;
    int secondForkId;
    bool ate = false;
    srand(time(NULL));

    if(id==0)
    {
        firstForkId = id;   
        secondForkId  = nPhilosophers-1;
    }
    else
    {
        firstForkId  = id-1;
        secondForkId = id;
    }

    while (!ate)
    {
        while( pthread_mutex_trylock(&forks[firstForkId]) != 0);
        if ( pthread_mutex_trylock(&forks[secondForkId]) == 0)
        {
            ate = true;
            plates[id]--;
            printf("Philosopher %d eating\n", id+1);
            sleep(rand()%EATING_MAX_TIME);
        }
        else
        {
            pthread_mutex_unlock(&forks[firstForkId]);
        }
    }

    pthread_mutex_unlock(&forks[secondForkId]);
    pthread_mutex_unlock(&forks[firstForkId]);
}
