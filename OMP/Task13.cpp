/**
 * @author lnurullina
 */

#include <omp.h>
#include <cstdio>
#include <unistd.h>
#include "Task13.h"

#define NUM_THREADS 3

/**Модифицируйте задачу 1 так, чтобы потоки распечатывали свои идентификаторы в обратном порядке.
 * Существует как минимум 5 способов решения. Постарайтесь найти как можно больше. (каждый вариант 1 балл – max 5 баллов) */
void Task13::run() {
    omp_set_num_threads(NUM_THREADS);

#pragma omp parallel
    {
        sleep(2 * (NUM_THREADS - omp_get_thread_num()));
        printf("Hello, I'm thread number %d of %d\n", omp_get_thread_num(), omp_get_num_threads() - 1);

    }
#pragma omp parallel for
    for (int i = 0; i < NUM_THREADS; ++i) {
        sleep(2 * (NUM_THREADS - omp_get_thread_num()));
        printf("Hello, I'm thread number %d of %d\n", omp_get_thread_num(), omp_get_num_threads() - 1);
    }

#pragma omp parallel sections
    {
#pragma omp section
        {
            sleep(2 * (NUM_THREADS - omp_get_thread_num()));
            printf("Hello, I'm thread number %d of %d\n", omp_get_thread_num(), omp_get_num_threads() - 1);
        }
#pragma omp section
        {
            sleep(2 * (NUM_THREADS - omp_get_thread_num()));
            printf("Hello, I'm thread number %d of %d\n", omp_get_thread_num(), omp_get_num_threads() - 1);
        }
#pragma omp section
        {
            sleep(2 * (NUM_THREADS - omp_get_thread_num()));
            printf("Hello, I'm thread number %d of %d\n", omp_get_thread_num(), omp_get_num_threads() - 1);
        }
    }


}
