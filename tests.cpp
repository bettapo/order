/*
    Оболочка для тестирования order-list
    Всего есть 6 модулей, каждый из которых тестирует определённый функционал

    Вызвать тестирование можно методом run_tests()
 */

#include <iostream>
#include "tests.h"

using namespace std;

void test_prepare(int *test_id, int *test_ok)
{
    (*test_id)++;
    (*test_ok) = 0;
    cout << "[UNIT TESTING] TEST: " << *test_id << " "; //С "*" или без?
}

void test_result(int test_ok)
{
    if (test_ok == 1)
        cout << "OK" << endl;
    else
        cout << "ERROR" << endl;
}

void run_tests()
{
    tests_unit_1();
    tests_unit_2();
    tests_unit_3();
    tests_unit_4();
    tests_unit_5();
    tests_unit_6();
}
