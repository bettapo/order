/*
 МОДУЛЬ 4
 Цель: Тестируем конкатанацию очередей (списков)
 Тестируемые методы: concatenation()


 Список тестов:
 Тест 1: Конкатенация 2 непустых очередей.
 Тест 2: Конкатенация 2 пустых очередей.
 Тест 3: Конкатенация пустой и непустой очередей.
 Тест 4: Конкатенация непустой и пустой очередей.
 */

#include "tests_unit_1.h"
#include <iostream>

using namespace std;

void tests_unit_4()
{
    cout << "[UNIT TESTING] UNIT 4: 4 test upcoming..." << endl;
    int test_ok = 1;
    int test_id = 0;


    // Test 1
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> A;
        int NumbersA[10] = {112, 34, 8, 9999, 1, 856, 34, 67, 5, 10 };
        for(int i = 0; i < 10; i++){
            A.enqueue(NumbersA[i]);
        }

        order_list<int> B;
        int NumbersB[10] = {1, 2, 8, 9999, 52, 85, 34, 67, 5, 945 };
        for(int i = 0; i < 10; i++){
            B.enqueue(NumbersB[i]);
        }

        A = A.concatenation(B);

        if ( A.get_length() == 20 )
        {
            test_ok = 1;

            for (int i = 0; i < 20; i++)
            {
                int a;
                a = A.dequeue();
                if ( (i < 10) && (NumbersA[i] != a) )
                {
                    test_ok = 0;
                    break;
                }
                if ( (i>=10) && (a !=  NumbersB[i-10]) )
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

        order_list<int> A;
        order_list<int> B;

        A = A.concatenation(B);

        if( A.get_length() == 0)
        {
            try {
                A.dequeue();
            } catch (std::out_of_range exep) {
                test_ok = 1;
            }
        }

        test_result(test_ok);
    }

    // Test 3
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> A;
        order_list<int> B;

        int NumbersB[10] = {1, 2, 8, 9999, 52, 85, 34, 67, 5, 945 };
        for(int i = 0; i < 10; i++){
            B.enqueue(NumbersB[i]);
        }

        A = A.concatenation(B);

        if ( A.get_length() == 10 )
        {
            test_ok = 1;

            for (int i = 0; i < 10; i++)
            {
                int a;
                a = A.dequeue();
                if ( a !=  NumbersB[i] )
                {
                    test_ok = 0;
                    break;
                }
            }
        } else
            test_ok = 0;

        test_result(test_ok);
    }

    // Test 4
    if (test_ok == 1)
    {
        test_prepare(&test_id, &test_ok);

        order_list<int> A;
        order_list<int> B;

        int NumbersA[10] = {112, 34, 8, 9999, 1, 856, 34, 67, 5, 10 };
        for(int i = 0; i < 10; i++){
            A.enqueue(NumbersA[i]);
        }

        A = A.concatenation(B);

        if ( A.get_length() == 10 )
        {
            test_ok = 1;

            for (int i = 0; i < 10; i++)
            {
                int a;
                a = A.dequeue();
                if ( a !=  NumbersA[i] )
                {
                    test_ok = 0;
                    break;
                }
            }
        } else
            test_ok = 0;

        test_result(test_ok);
    }

    if (test_id == 4)
        cout << "[UNIT TESTING] Unit 4 testing SUCCESSEDED." << endl;
    else
        cout << "[UNIT TESTING] Unit 4 testing FAILED on TEST " << test_id << "." << endl;

    cout << endl;
}