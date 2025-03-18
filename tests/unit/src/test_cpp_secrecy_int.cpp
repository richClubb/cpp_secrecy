#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include "cpp_secrecy.h"

void test_basic_int(void)
{
    int *ptr;
    SecretValue<int> value(1);

    // check that the exposed value is correct
    CU_ASSERT(*value.expose_value() == 1);

    // get the pointer to the secret values
    ptr = value.expose_value();

    // check the value at the pointer is correct
    CU_ASSERT(*ptr == 1);

    // destroy the secret value
    value.~SecretValue();

    // check the value at the old memory location is correct
    CU_ASSERT(*ptr == 0);    
}

void run_int_suite(void)
{
    CU_pSuite suite = CU_add_suite("C secrecy int tests", 0, 0);
    CU_add_test(suite, "test of basic int creation and destruction", test_basic_int);
    CU_basic_run_tests();
}