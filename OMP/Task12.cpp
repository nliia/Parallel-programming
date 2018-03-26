/**
 * @author lnurullina
 */

#include <cstdlib>
#include <time.h>
#include <cstdio>
#include "Task12.h"

#define N 300
#define DIVIDER 7

/** Написать программу, в которой, объявить и заполнить случайными значениями массив целых чисел. 
 * Используя возможности OpenMP найти максимальное числовое значение элементов массива кратное 7.
 * Длину массива и количество потоков определить самостоятельно. Результат выдать на экран. 
 * Для синхронизации числовых значений максимума используется механизм критических секций. (2 балла)
*/
void Task12::run() {
    srand(time(NULL));

    int a[N];

    for (int i = 0; i < N; i++) {
        a[i] = rand() % N;
    }

    int base_max = a[0];
    for (int j = 0; j < N; ++j) {
        if (a[j] % DIVIDER == 0 && base_max < a[j]) {
            base_max = a[j];
        }
    }

    int max = a[0];
#pragma omp parallel for shared(max)
    for (int i = 0; i < N; i++) {
        if (a[i] % DIVIDER == 0 && max < a[i]) {
#pragma omp critical
            {
                if (max < a[i])
                    max = a[i];
            }
        }
    }

    printf("%d\n", max);
    if (base_max == max) {
        printf("correct\n");
    }

}
