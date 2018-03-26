/**
 * @author lnurullina
 */

#include <cstdlib>
#include <cstdio>
#include <omp.h>
#include "Task11.h"
/** Написать программу, в которой объявить и присвоить начальные значения массиву целых чисел a[30],
 * для инициализации значений использовать генератор случайных чисел.
 * Используя конструкцию omp parallel for и omp atomic вычислить количество элементов массива,
 * числовые значения которых кратны 9. Количество нитей задать самостоятельно. Результат выдать на экран. (2 балла)
*/
#define N 30

void Task11::run() {
    int a[N];
    for (int i = 0; i < N; ++i) {
        a[i] = rand();
    }

    int count = 0;
#pragma omp parallel for num_threads(3)
    for (int j = 0; j < N; ++j) {
        if (a[j] % 9 == 0) {
#pragma omp atomic
            count++;
            printf("The value of array is %d from thread number %d \n", a[j], omp_get_thread_num());
        }
    }
    printf("Number of numbers which are divided in 9 = %d", count);

}
