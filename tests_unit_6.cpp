/*
 МОДУЛЬ 6
 Цель: Тестируем поиск на вхождение подпоследовательности.
 Тестируемые методы: searchSubsequence()


 Список тестов:
 Тест 1: Успешный поиск подпоследовательности, которая есть в очереди.
 Тест 2: Попытка найти последовательнось, которой в очереди нет.

 */

#include "tests_unit_1.h"
#include <iostream>

using namespace std;

void tests_unit_6()
{
    cout << "[UNIT TESTING] UNIT 6: 1 test upcoming..." << endl;
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

        order_list<int> subjectOfSearch;
        for(int i = 3; i < 8; i++){
            order.enqueue(Numbers[i]);
        }


        if ( order.searchSubsequence( subjectOfSearch ) )
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

        order_list<int> subjectOfSearch;
        for(int i = 0; i < 10; i++){
            order.enqueue(Numbers[i]);
        }
        subjectOfSearch.enqueue(29);


        if ( !order.searchSubsequence( subjectOfSearch ) )
            test_ok = 1;

        test_result(test_ok);
    }


    if (test_id == 2)
        cout << "[UNIT TESTING] Unit 6 testing SUCCESSEDED." << endl;
    else
        cout << "[UNIT TESTING] Unit 6 testing FAILED on TEST " << test_id << "." << endl;

    cout << endl;
}

