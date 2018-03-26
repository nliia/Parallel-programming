/**
 * @author lnurullina
 */

#include <omp.h>
#include <cstdlib>
#include <cstdio>
#include "Task9.h"

/** Используя возможности OpenMP написать программу умножения матрицы на вектор.
 * Сравнить время выполнения последовательной и параллельных программ.
 * Определить размеры матрицы при которых параллельная программа начинает работать быстрей последовательной (3 балла)
*/
void Task9::run() {
    int n = 800;
    int a[n][n];
    int v[n];
    int result[n];
    int sum;

    omp_set_num_threads(2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = rand() % n - (n/2);
        }
        v[i] = rand() % n;
    }

    double start = omp_get_wtime();
    for (int k = 0; k < n; k++) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[k][i] * v[i];
        }
        result[k] = sum;
    }
    double finish = omp_get_wtime();

    for (int l = 0; l < n; l++) {
        printf("%d ", result[l]);
    }
    printf("\n Not parallel work time: %f\n", finish - start);


    double start2 = omp_get_wtime();

#pragma omp parallel for shared(result)
    for (int k = 0; k < n; k++) {
        sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[k][i] * v[i];
        }
        result[k] = sum;
    }
    double finish2 = omp_get_wtime();

    for (int l = 0; l < n; ++l) {
        printf("%d ", result[l]);
    }
    printf("\n Parallel work time: %f\n", finish2 - start2);

}
