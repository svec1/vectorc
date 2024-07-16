#ifndef _TEST_U__H
#define _TEST_U__H

#include "../include/vec_f.h"

#include <assert.h>
#include <stdio.h>
#include <time.h>

#define TEST_DECL_OUTPUT(name_test_unit) printf("RUN UNIT TEST - %s\n", name_test_unit)
#define TEST_DECL_OUTPUT_END(name_test_unit, time) printf("UNIT TESTING SUCCESSFUL -%s, END! TIME TESTING - %d\n", name_test_unit, time)

#define RUN_TEST_UNIT(name_test_unit, test_unit, time_test_unit, begin_time_test_unit, end_time_test_unit) \
                                      TEST_DECL_OUTPUT(name_test_unit); \
                                      begin_time_test_unit = localtime(&time_test_unit); \
                                      test_unit(); \
                                      end_time_test_unit = localtime(&time_test_unit); \
                                      TEST_DECL_OUTPUT_END(name_test_unit, end_time_test_unit->tm_sec-begin_time_test_unit->tm_sec);

typedef struct test_struct_u
{
    double var;
    double var2;
    double var3;
    double var4;
} test_struct_u;

int run_test_unit();

void test_allocate_100_el_struct();
void test_allocate_100_el_struct_push_and_pop();

#endif