/*
 МОДУЛЬ 2
 Цель: Тестируем постановку элементов в очередь
 Тестируемые методы: enqueue(T item)


 Список тестов
 Тест 1: Добавление 1 элемента в очередь.
 Тест 2: Добавление 10 элементов в очередь.

 */

#include "tests_unit_2.h"
#include <iostream>

using namespace std;

void tests_unit_2()
{
    cout << "[UNIT TESTING] UNIT 2: 2 test upcoming..." << endl;
    int test_ok = 1;
    int test_id = 0;


    // Test 1
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);


        order_list<int> order;
        order.enqueue(29);
        if ( (order.get_length() == 1) && (order.dequeue() == 29) )
            test_ok = 1;


        test_result(test_ok);
    }

    // Test 2
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> order;
        int Numbers[10] = {112, 34, 8, 9999, 1, 856, 34, 67, 5, 10 };
        for(int i = 0; i < 10; i++){
            order.enqueue(Numbers[i]);
        }

        if (order.get_length() == 10)
        {
            test_ok = 1;

            for (int i = 0; i < 10; i++) {
                if (order.dequeue() !=  Numbers[i]) {
                    test_ok = 0;
                    break;
                }
            }
        } else
            test_ok = 0;

        test_result(test_ok);
    }


    if (test_id == 2)
        cout << "[UNIT TESTING] Unit 2 testing SUCCESSEDED." << endl;
    else
        cout << "[UNIT TESTING] Unit 2 testing FAILED on TEST " << test_id << "." << endl;

    cout << endl;
}

