/**
 * @author lnurullina
 */

#include <cstdio>
#include <omp.h>
#include "Task7.h"

/**Написать программу, в которой определить две параллельные области,
 * каждая из которых содержит итерационную конструкцию for выполняющую инициализацию элементов
 * одномерных массивов целых чисел a[12], b[12] и c[12].
 * Число нитей перед первой областью задать равным 3, перед второй – равным 4.
 * Первая параллельная область выполняет инициализацию элементов массивов a и b с использованием
 * статического распределения итераций, размер порции итераций выбрать самостоятельно,
 * вторая параллельная область выполняет инициализацию элементов массива c по следующему правилу c[i] = a[i] + b[i],
 * с использованием динамического распределения итераций, размер порции итераций выбрать самостоятельно.
 * В каждой области определить и выдать на экран количество нитей, номер нити и результат выполнения цикла.
 * Убедиться в правильности работы программы.  (2 баллов)
*/
#define N 12
#define CHUNK 3

void Task7::run() {
    int a[N] = {};
    int b[N] = {};
    int c[N] = {};
    omp_set_num_threads(3);

#pragma omp parallel for \
    schedule(static, CHUNK)
    for (int i = 0; i < N; ++i) {
        a[i] = i;
        b[i] = i;
        printf("Number of threads: %d, this thread is number: %d, i = %d, a= %d, b=%d\n", omp_get_num_threads(),
               omp_get_thread_num(), i, a[i], b[i]);
    }

    omp_set_num_threads(4);
#pragma omp parallel for schedule(dynamic, CHUNK)
    for (int i = 0; i < N; ++i) {
        c[i] = a[i] + b[i];
        printf("Number of threads: %d, this thread is number: %d, i = %d, c[i] = %d\n", omp_get_num_threads(),
               omp_get_thread_num(), i, c[i]);
    }
}
