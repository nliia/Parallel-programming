/**
 * @author lnurullina
 */

#include <cstdio>
#include "Task6.h"

/**Написать программу, в которой объявить и присвоить начальные значения целочисленному массиву a[100].\
 * Используя конструкцию parallel for и reduction вычислить средние арифметические значения элементов массива a.
 * Одно при помощи reduction, другое без. Сравнить полученные значения, результат выдать на экран. (2 балла) */
void Task6::run() {
    int a[100] = {};

    for (int j = 0; j < 100; ++j) {
        a[j] = j;
    }
    int sum = 0;
#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < 100; i++)
        sum += a[i];

    int sum2 = 0;
#pragma omp parallel for
    for (int i = 0; i < 100; i++)
        sum2 += a[i];
    printf("Result from reduction section: %d, from parallel for: %d", sum / 100, sum2 / 100);
}
