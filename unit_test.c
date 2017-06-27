#include <stdio.h>
#include <stdlib.h>
#include "unit_test.h"

int main(int argc, char* argv[])
{
  Status(*tests[])(char*, int) =
    {
      test_init_default_returns_nonNULL,
      test_esmith_init_c_string_returns_nonNULL,
      test_get_size_on_init_default_returns_0,
      test_esmith_get_capacity_on_init_returns_nonzero,
      test_esmith_str_destroy_succeeds_on_init_default,
      test_esmith_str_compare_returns_negative,
      test_esmith_str_compare_returns_positive,
      test_esmith_str_compare_returns_zero,
      test_esmith_my_string_empty_on_init_c_string_returns_false,
      test_esmith_my_string_empty_on_init_default_returns_true
    };
  int number_of_functions = sizeof(tests)/sizeof(tests[0]);
  int i;
  char buffer[500];
  int success_count = 0;
  int failure_count = 0;

  for(i = 0; i < number_of_functions; i++)
    {
      if(tests[i](buffer, 500) == FAIL)
	{
	  printf("FAILED: Test %d failed miserably\n", (i+1));
	  printf("\t%s\n", buffer);
	  failure_count++;
	}
      else
	{
	  printf("SUCCESS: Test %d was completed successfully\n", (i+1));
	  printf("\t%s\n", buffer);
	  success_count++;
	}
    }
  
  return 0;
}
