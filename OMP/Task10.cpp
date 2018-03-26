/**
 * @author lnurullina
 */

#include <cstdlib>
#include <cstdio>
#include <stdlib.h>
#include "Task10.h"

#define N 6
#define M 8

/** Написать программу, в которой объявить и присвоить начальные значения элементам
 * двумерного массива d[6][8], для инициализации значений использовать генератор случайных чисел.
 * Используя конструкцию директивы omp parallel for и omp critical определить минимальное
 * и максимальное значения элементов двумерного массива. Реализовать аналог reduction для max и min.
 * Количество нитей задать самостоятельно. Результат выдать на экран. (2 балла) */
void Task10::run() {

    int d[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            d[i][j] = rand();
        }
    }

    int min = d[0][0];
    int max = d[0][0];

    int counter = 0;
#pragma omp parallel num_threads(6) reduction(+: counter)
    for (int i = 0; i < N; i++) {
#pragma omp for
        for (int j = 0; j < M; j++) {
            counter++;
            if (max < d[i][j]) {
#pragma omp critical(first)
                if (max < d[i][j])
                    max = d[i][j];
            }

            if (min > d[i][j]) {
#pragma omp critical(second)
                if (min > d[i][j])
                    min = d[i][j];
            }
        }
    }
    printf("counter is %d, minimum is %d, maximum is %d\n", counter, min, max);
}
