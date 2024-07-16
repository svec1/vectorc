#include "test-u.h"

int run_test_unit(){
    const time_t time_test_unit = time(NULL);
    struct tm* begin_time_test_unit;
    struct tm* end_time_test_unit;
    RUN_TEST_UNIT("TU1", test_allocate_100_el_struct, time_test_unit, begin_time_test_unit, end_time_test_unit);
    RUN_TEST_UNIT("TU2", test_allocate_100_el_struct_push_and_pop, time_test_unit, begin_time_test_unit, end_time_test_unit);
}