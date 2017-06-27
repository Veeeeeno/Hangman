#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_esmith_init_c_string_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_esmith_get_capacity_on_init_returns_nonzero(char* buffer, int length);
Status test_esmith_str_destroy_succeeds_on_init_default(char* buffer, int length);
Status test_esmith_str_compare_returns_negative(char* buffer, int length);
Status test_esmith_str_compare_returns_positive(char* buffer, int length);
Status test_esmith_str_compare_returns_zero(char* buffer, int length);
Status test_esmith_my_string_empty_on_init_default_returns_true(char* buffer, int length);
Status test_esmith_my_string_empty_on_init_c_string_returns_false(char* buffer, int length);

#endif
