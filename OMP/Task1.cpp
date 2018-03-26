/**
 * @author lnurullina
 */

#include <omp.h>
#include <cstdio>
#include "Task1.h"

#define THREAD_COUNT 5

int Task1::run() {
#pragma omp parallel num_threads(THREAD_COUNT)
    hello();

#define N 10
    int i;
#pragma omp parallel
    {
        int tmp = 0;
#pragma omp for private(tmp)
        for (i = 0; i < N; i++) {
            tmp += i;
        }
    }
    return 0;
}

void Task1::hello() {
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_thread_num();

    printf("hello from rank %d of %d \n", my_rank, thread_count);
}
