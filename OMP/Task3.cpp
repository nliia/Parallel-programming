/**
 * @author lnurullina
 */

#include <omp.h>
#include <cstdio>
#include "Task3.h"

/** Написать программу, в которой объявить и присвоить начальные значения целочисленным переменным: a и b,
 * определить две параллельные области, первая – с числом нитей 2, вторая – с числом нитей 4.
 * Для первой области переменные a и b объявить защищенными, с режимом доступа private и firstprivate соответственно,
 * внутри области определить номер нити и выполнить увеличение значения переменных на эту величину.
 * Выдать на экран значения переменных до входа в параллельную область, внутри параллельной области и
 * после выхода из параллельной области. Для второй области переменную a объявить общей,
 * переменную b объявить защищенной, с режимом доступа private, определить номер нити и выполнить
 * уменьшение значения переменных на эту величину. Выдать на экран значения переменных до входа в параллельную область,
 * внутри параллельной области и после выхода из параллельной области. (2 балла)
*/
void Task3::run() {
    int a = 5;
    int b = 6;
    printf("before parallel: a = %d, b = %d\n\n", a, b);
#pragma omp parallel num_threads(2) private(a) firstprivate(b)
    {
        a = a + omp_get_thread_num();
        b = b + omp_get_thread_num();
        printf("from thread number %d: a = %d, b = %d\n", omp_get_thread_num(), a, b);
    }
    printf("\nafter first parallel: a = %d, b = %d\n", a, b);

    printf("\nbefore second parallel: a = %d, b = %d\n\n", a, b);

#pragma omp parallel num_threads(4) shared(a) private(b)
    {
        a = a - omp_get_thread_num();
        b = b - omp_get_thread_num();
        printf("from thread number %d: a = %d, b = %d\n", omp_get_thread_num(), a, b);
    }
    printf("\nafter first parallel: a = %d, b = %d", a, b);

}
