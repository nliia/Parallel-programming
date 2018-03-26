/**
 * @author lnurullina
 */

#include <iostream>
#include <omp.h>
#include "Task8.h"
/**8. Написать программу, в которой объявлен массив из 16000 элементов и инициализирован так,
 * что значение элемента массива равно его порядковому номеру. Затем создайте результирующий массив,
 * в котором (за исключением крайних элементов) будут средние значения исходного массива:
b[i] = (a[i-1] + a[i] + a[i+1])/3.0
Запустите программу с 8-ю процессами при различных типах распределения работ
 (static, dynamic, guided, auto(runtime, если auto не работает)) и посмотреть время на разных размерах порций. (4 балла) */
#define N 16000

void Task8::run() {
    int a[N];
    double b[N];

    for (int i = 0; i < N; ++i) {
        a[i] = i;
    }
    double start = omp_get_wtime();
#pragma omp parallel for schedule(static, 16) num_threads(30)
    for (int i = 1; i < N - 1; i++) {
        b[i] = (a[i - 1] + a[i] + a[i + 1]) * 1.0 / 3;
    }
    double finish = omp_get_wtime();
    printf("Time of static working: %lf\n", finish - start);

    double start2 = omp_get_wtime();
#pragma omp parallel for schedule(dynamic) num_threads(30)
    for (int i = 1; i < N - 1; i++) {
        b[i] = (a[i - 1] + a[i] + a[i + 1]) * 1.0 / 3;
    }
    double finish2 = omp_get_wtime();
    printf("Time of dynamic working: %lf\n", finish2 - start2);

    start = omp_get_wtime();
#pragma omp parallel for schedule(guided, 16) num_threads(30)
    for (int i = 1; i < N - 1; i++) {
        b[i] = (a[i - 1] + a[i] + a[i + 1]) * 1.0 / 3;
    }
    finish = omp_get_wtime();
    printf("Time of guided working: %lf\n", finish - start);

    start = omp_get_wtime();
#pragma omp parallel for schedule(runtime) num_threads(30)
    for (int i = 1; i < N - 1; i++) {
        b[i] = (a[i - 1] + a[i] + a[i + 1]) * 1.0 / 3;
    }
    finish = omp_get_wtime();

    printf("Time of runtime working: %lf", finish - start);
}
