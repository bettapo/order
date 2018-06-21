/*
 МОДУЛЬ 3
 Цель: Тестируем постановку снятие элементов с очереди; удаление элементов из очереди; очищение очереди.
 Тестируемые методы: dequeue()
                     dequeue_withoutReturn()
                     clear();


 Список тестов

 Для dequeue()
 Тест 1: Снятие 1 элемента с очереди, состоящей из 10 элементов.
 Тест 2: Снятие 5 элементов с очереди, состоящей из 10 элементов.
 Тест 3: Попытка снять элемент с пустой очереди.

 Для dequeue_withoutReturn()
 Тест 4: Добавление и удаление 1 элемента из очереди (сняти с очереди без возврата значений).
 Тест 5: Добавление и удаление 10 элементов подряд из очереди (сняти с очереди без возврата значений).
 Тест 6: Попытка удалить элемент из пустой очереди.

 Для clear();
 Тест 7: Очищение очереди, состоящей из 10 элементов.
 Тест 8: Попытка очистить пустую очередь.
 */

#include "tests_unit_2.h"
#include <iostream>

using namespace std;

void tests_unit_3()
{
    cout << "[UNIT TESTING] UNIT 3: 8 test upcoming..." << endl;
    int test_ok = 1;
    int test_id = 0;


    // Test 1
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> order;
        int Numbers[10] = {112, 34, 8, 9999, 1, 856, 34, 67, 5, 10 };
        for(int i = 0; i < 10; i++){
            order.enqueue(Numbers[i]);
        }

        int a;
        a = order.dequeue();

        if( (order.get_length() == 9) && (a == Numbers[0]))
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

        int Result[5];
        for (int i = 0; i < 5; i++ )
            Result[i] = order.dequeue();

        if (order.get_length() == 5)
        {
            test_ok = 1;

            for (int i = 0; i < 5; i++) {
                if (Result[i] !=  Numbers[i]) {
                    test_ok = 0;
                    break;
                }
            }
        } else
            test_ok = 0;


        test_result(test_ok);
    }

    // Test 3
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> order;

        if( order.get_length() == 0)
        {
            try {
                order.dequeue();
            } catch (std::out_of_range exep) {
                test_ok = 1;
            }
        }

        test_result(test_ok);
    }

    // Test 4
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> order;
        order.enqueue(29);

        order.dequeue();

        if ( order.isEmpty() ) {
            try {
                order.dequeue();
            } catch (std::out_of_range exep) {
                test_ok = 1;
            }
        }

        test_result(test_ok);
    }

    // Test 5
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> order;
        int Numbers[10] = {112, 34, 8, 9999, 1, 856, 34, 67, 5, 10 };
        for(int i = 0; i < 10; i++){
            order.enqueue(Numbers[i]);
        }

        for(int i = 0; i < 10; i++){
            order.dequeue();
        }


        if ( order.isEmpty() ) {
            try {
                order.dequeue();
            } catch (std::out_of_range exep) {
                test_ok = 1;
            }
        }

        test_result(test_ok);
    }

    // Test 6
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> order;

        if( order.get_length() == 0)
        {
            try {
                order.dequeue_withoutReturn();
            } catch (std::out_of_range exep) {
                test_ok = 1;
            }
        }

        test_result(test_ok);
    }

    // Test 7
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> order;
        int Numbers[10] = {112, 34, 8, 9999, 1, 856, 34, 67, 5, 10 };
        for(int i = 0; i < 10; i++){
            order.enqueue(Numbers[i]);
        }

        order.clear();

        if( order.get_length() == 0)
        {
            try {
                order.dequeue_withoutReturn();
            } catch (std::out_of_range exep) {
                test_ok = 1;
            }
        }

        test_result(test_ok);
    }

    // Test 8
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> order;

        order.clear();

        if( order.get_length() == 0)
        {
            try {
                order.dequeue_withoutReturn();
            } catch (std::out_of_range exep) {
                test_ok = 1;
            }
        }

        test_result(test_ok);
    }

    if (test_id == 8)
        cout << "[UNIT TESTING] Unit 3 testing SUCCESSEDED." << endl;
    else
        cout << "[UNIT TESTING] Unit 3 testing FAILED on TEST " << test_id << "." << endl;

    cout << endl;
}