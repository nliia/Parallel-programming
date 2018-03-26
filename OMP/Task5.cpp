/**
 * @author lnurullina
 */

#include <cstdio>
#include <omp.h>
#include <cstdlib>
#include "Task5.h"

/** Написать программу, в которой объявить и присвоить начальные значения элементам двумерного массива d[6][8],
 * для инициализации значений использовать генератор случайных чисел. Используя конструкцию директивы sections…section
 * определить три секции для выполнения следующих операций:
        первая секция выполняет вычисление среднего арифметического значения элементов двумерного массива,
        вторая секция выполняет вычисление минимального и максимального значений элементов двумерного массива,
        третья секция выполняет вычисление количества элементов массива, числовые значения которых кратны
В каждой секции определить и выдать на экран номер исполняющей нити и результат выполнения вычислений. (3 балла)
*/
using namespace std;

void Task5::run() {
    int n = 6;
    int m = 8;
    int d[n][m] = {};
#pragma omp for
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            d[i][j] = rand();
        }
    }

#pragma omp parallel sections
    {
#pragma omp section
        {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    sum = sum + d[i][j];
                }
            }
            printf("Average of the array = %d from thread number %d\n", sum / n * m, omp_get_thread_num());
        }

#pragma omp section
        {
            int max = d[0][0];
            int min = d[0][0];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (d[i][j] > max)
                        max = d[i][j];
                    if (d[i][j] < min)
                        min = d[i][j];
                }
            }
            printf("Min of array is %d, max is %d from thread number %d \n", min, max, omp_get_thread_num());
        }

#pragma omp section
        {
            int count = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (d[i][j] % 2 == 0) {
                        count++;
                    }
                }
            }
            printf("Number of elements which are divided in two: %d from thread number %d\n", count,
                   omp_get_thread_num());
        }
    }
}
