/*
 МОДУЛЬ 1
 Цель: Тестируем создание очереди
 Тестируемые методы: конструктор order_list()


 Список тестов:
 Тест 1: Успешное создание пустой очереди (вызов конструктора).

 Мб, стоит добавить тест с попыткой извлечь элемент. Тогда должно вызваться исключение.
 */

#include "tests_unit_1.h"
#include <iostream>

using namespace std;

void tests_unit_1()
{
    cout << "[UNIT TESTING] UNIT 1: 1 test upcoming..." << endl;
    int test_ok = 1;
    int test_id = 0;


    // Test 1
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> order;
        if ( order.isEmpty() ) {
            try {
                order.dequeue();
            } catch (std::out_of_range exep) {
                test_ok = 1;
            }
        }

        test_result(test_ok);
    }


    if (test_id == 1)
        cout << "[UNIT TESTING] Unit 1 testing SUCCESSEDED." << endl;
    else
        cout << "[UNIT TESTING] Unit 1 testing FAILED on TEST " << test_id << "." << endl;

    cout << endl;
}