/**
 * @author lnurullina
 */

#include <omp.h>
#include <cstdio>
#include "Task2.h"

/**Написать программу, в которой определить две параллельные области,
выполнение которых зависит от условного оператора #pragma omp parallel if(…),
если заданное значение числа нитей больше 2, параллельная область выполняется,
иначе не выполняется. Число нитей перед первой областью задать равным 3,
перед второй – равным 1. Внутри параллельных областей определить количество нитей и номер каждой нити,
        результат выдать на экран. Убедиться в правильности работы программы. (2 балла)*/
void Task2::run() {

    int threads_num = 3;
    omp_set_num_threads(threads_num);
#pragma omp parallel if(threads_num > 2)
    {
        printf("First parallel area works! num threads = %d, from thread num: %d \n", omp_get_num_threads(),
               omp_get_thread_num());
    }

    int threads_num2 = 1;
    omp_set_num_threads(threads_num2);
#pragma omp parallel if (threads_num2 > 2)
    {
        printf("Second parallel area works! num threads = %d, from thread num: %d \n", omp_get_num_threads(),
               omp_get_thread_num());
    }

}
