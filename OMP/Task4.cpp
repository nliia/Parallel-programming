/**
 * @author lnurullina
 */

#include <omp.h>
#include <cstdio>
#include "Task4.h"

/** Написать программу, в которой объявить и присвоить начальные значения целочисленным массивам a[10] и b[10],
 * определить параллельную область, количество нитей задать равным 2, выделить код для основной (номер 0) и нити с номером 1.
 * Основная нить должна выполнять поиск min значения элементов массива a,
 * нить с номером 1 - поиск max значения элементов массива b. Результат выдать на экран. (2 балла)
*/
void Task4::run() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int min = a[0];
    int max = b[0];
#pragma omp parallel num_threads(2)
    {
        if (omp_get_thread_num() == 0) {
#pragma omp for
            for (int i = 0; i < 10; ++i) {
                if (a[i] < min) {
                    min = a[i];
                }
            }

        } else {
#pragma omp for
            for (int i = 0; i < 10; ++i) {
                if (b[i] > max) {
                    max = b[i];
                }
            }
        }
    }

    printf("max of b array = %d\n", max);
    printf("min of a array = %d", min);
}
