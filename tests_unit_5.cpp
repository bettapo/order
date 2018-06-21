/*
 МОДУЛЬ 5
 Цель: Тестируем извлечение подпоследовательности по заданным индексам.
 Тестируемые методы: subsequenceByIndexes(int from, int to)


 Список тестов:
 Тест 1: Извлечение подпоследовательности по заданным индексам.
 Тест 2: Попытка извлечь подпоследовательность из пустой очереди.
 Тест 3: Попытка извлечь подпоследовательность с отрицательным индексом from.
 Тест 4: Попытка извлечь подпоследовательность с отрицательным индексом to.
 Тест 5: Попытка извлечь подпоследовательность с индексами, выходящим за размеры очереди.
 Тест 6: Попытка извлечь подпоследоувательность с индексами from > to.

*/

#include "tests_unit_1.h"
#include <iostream>

using namespace std;

void tests_unit_5()
{
    cout << "[UNIT TESTING] UNIT 5: 6 test upcoming..." << endl;
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

        order_list<int> subsequence;

        subsequence = order.subsequenceByIndexes(3, 7);

        if ( subsequence.get_length() == 5 )
        {
            test_ok = 1;

            for (int i = 2; i < 7; i++)
            {
                int a;
                a = subsequence.dequeue();
                if ( a !=  Numbers[i] )
                {
                    test_ok = 0;
                    break;
                }
            }
        } else
            test_ok = 0;

        test_result(test_ok);
    }

    // Test 2
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> order;
        order_list<int> subsequence;

        try {
            subsequence = order.subsequenceByIndexes(3, 7);
        } catch (std::out_of_range exep) {
            test_ok = 1;
        }

        test_result(test_ok);
    }

    // Test 3
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> order;
        order_list<int> subsequence;

        int Numbers[10] = {112, 34, 8, 9999, 1, 856, 34, 67, 5, 10 };
        for(int i = 0; i < 10; i++){
            order.enqueue(Numbers[i]);
        }

        try {
            subsequence = order.subsequenceByIndexes(-1, 7);
        } catch (std::out_of_range exep) {
            test_ok = 1;
        }

        test_result(test_ok);
    }

    // Test 4
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> order;
        order_list<int> subsequence;

        int Numbers[10] = {112, 34, 8, 9999, 1, 856, 34, 67, 5, 10 };
        for(int i = 0; i < 10; i++){
            order.enqueue(Numbers[i]);
        }

        try {
            subsequence = order.subsequenceByIndexes(2, -7);
        } catch (std::out_of_range exep) {
            test_ok = 1;
        }

        test_result(test_ok);
    }

    // Test 5
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> order;
        order_list<int> subsequence;

        int Numbers[10] = {112, 34, 8, 9999, 1, 856, 34, 67, 5, 10 };
        for(int i = 0; i < 10; i++){
            order.enqueue(Numbers[i]);
        }

        try {
            subsequence = order.subsequenceByIndexes(12, 15);
        } catch (std::out_of_range exep) {
            test_ok = 1;
        }

        test_result(test_ok);
    }

    // Test 5
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> order;
        order_list<int> subsequence;

        int Numbers[10] = {112, 34, 8, 9999, 1, 856, 34, 67, 5, 10 };
        for(int i = 0; i < 10; i++){
            order.enqueue(Numbers[i]);
        }

        try {
            subsequence = order.subsequenceByIndexes(9, 2);
        } catch (std::out_of_range exep) {
            test_ok = 1;
        }

        test_result(test_ok);
    }


    if (test_id == 6)
        cout << "[UNIT TESTING] Unit 5 testing SUCCESSEDED." << endl;
    else
        cout << "[UNIT TESTING] Unit 5 testing FAILED on TEST " << test_id << "." << endl;

    cout << endl;
}
