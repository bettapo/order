#ifndef ORDER_TESTS_H
#define ORDER_TESTS_H

#include <cstdio>
#include <cstdlib>
#include "order.h"

#include "tests_unit_1.h"
#include "tests_unit_2.h"
#include "tests_unit_3.h"
#include "tests_unit_4.h"
#include "tests_unit_5.h"
#include "tests_unit_6.h"


void test_prepare(int *test_id, int *test_ok);
void test_result(int test_ok);
void run_tests();


#endif //ORDER_TESTS_H
