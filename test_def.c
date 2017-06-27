#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_test.h"

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();

  if(hString == NULL)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_init_default_returns_nonNULL\n"
	      "my_string_init_default returns NULL", length);
      return FAIL;
    }else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
      return SUCC;
    }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();

  if(my_string_get_size(hString) != 0)
    {
      status = FAIL;
      printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
      strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
	      "Did not receive 0 from get_size after init_default\n", length);
    }else
    {
      status = SUCC;
      strncpy(buffer, "\ttest_get_size_on_init_default_returns_0\n", length);
    }

  my_string_destroy(&hString);
  return status;
}

Status test_esmith_get_capacity_on_init_returns_nonzero(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();  
  if(my_string_get_capacity(hString) == 0)
    {
      status = FAIL;
      printf("Expected an initial capacity of !0 but found 0\n");
      strncpy(buffer, "test_esmith_get_capacity_on_init_returns_nonzero\n"
	     "Received 0 from get_capacity after init.\n", length);
    }
  else
    {
      status = SUCC;
      strncpy(buffer, "\ttest_esmith_get_capacity_on_init_returns_nonzero\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_esmith_str_destroy_succeeds_on_init_default(char* buffer, int length)
{
  Status status;
  MY_STRING hString = NULL;

  hString = my_string_init_default();
  my_string_destroy(&hString);

  if(hString != NULL)
    {
      status = FAIL;
      printf("Attempt to destroy string failed\n");
      strncpy(buffer, "test_esmith_str_destroy_succeeds_on_init_default\n"
	      "String was not properly destroyed, hString has nonNULL value\n", length);
    }
  else
    {
      status = SUCC;
      strncpy(buffer, "\ttest_esmith_str_destroy_succeeds_on_init_default\n", length);
    }
  return status;
}

Status test_esmith_str_compare_returns_negative(char* buffer, int length)
{
  Status status;
  MY_STRING hLString = NULL, hRString = NULL;
  hLString = my_string_init_c_string("Left");
  hRString = my_string_init_c_string("Right");
  
  if(my_string_compare(hLString, hRString) >= 0)
    {
      status = FAIL;
      printf("Expected a value less than 0 but value received was >= 0\n");
      strncpy(buffer, "test_esmith_str_compare_returns_negative\n"
	      "Size of string #1 was greater than string #2\n", length);
    }
  else
    {
      status = SUCC;
      strncpy(buffer, "\ttest_esmith_str_compare_returns_negative\n", length);
    }
  my_string_destroy(&hLString);
  my_string_destroy(&hRString);
  return status;
}

Status test_esmith_str_compare_returns_positive(char* buffer, int length)
{
  Status status;
  MY_STRING hLString = NULL, hRString = NULL;
  hLString = my_string_init_c_string("Left");
  hRString = my_string_init_c_string("Right");
  
  if(my_string_compare(hRString, hLString) <= 0)
    {
      status = FAIL;
      printf("Expected a value greater than 0 but value received was <= 0\n");
      strncpy(buffer, "test_esmith_str_compare_returns_positive\n"
	      "Size of string #1 was lesser than string #2\n", length);
    }
  else
    {
      status = SUCC;
      strncpy(buffer, "\ttest_esmith_str_compare_returns_positive\n", length);
    }
  my_string_destroy(&hLString);
  my_string_destroy(&hRString);
  return status;
}

Status test_esmith_str_compare_returns_zero(char* buffer, int length)
{
  Status status;
  MY_STRING hLString = NULL, hRString = NULL;
  hLString = my_string_init_c_string("Cat");
  hRString = my_string_init_c_string("Dog");
  
  if(my_string_compare(hRString, hLString) != 0)
    {
      status = FAIL;
      printf("Expected a value of 0 but value received was != 0\n");
      strncpy(buffer, "test_esmith_str_compare_returns_zero\n"
	      "Size of string #1 differed from string #2\n", length);
    }
  else
    {
      status = SUCC;
      strncpy(buffer, "\ttest_esmith_str_compare_returns_positive\n", length);
    }
  my_string_destroy(&hLString);
  my_string_destroy(&hRString);
  return status;
}

Status test_esmith_my_string_empty_on_init_c_string_returns_false(char* buffer, int length)
{
  Status status;
  MY_STRING hString = NULL;
  hString = my_string_init_c_string("A");

  if(my_string_empty(hString) != FALSE)
    {
      status = FAIL;
      printf("Expected string to be occupied but it was empty\n");
      strncpy(buffer, "test_esmith_my_string_empty_on_init_c_string_returns_false\n"
	      "String was empty after initializing\n", length);
    }
  else
    {
      status = SUCC;
      strncpy(buffer, "\ttest_esmith_my_string_empty_on_init_c_string_returns_false\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_esmith_my_string_empty_on_init_default_returns_true(char* buffer, int length)
{
  Status status;
  MY_STRING hString = NULL;
  hString = my_string_init_default();

  if(my_string_empty(hString) != TRUE)
    {
      status = FAIL;
      printf("Expected string to be empty but it was occupied\n");
      strncpy(buffer, "test_esmith_my_string_empty_on_init_default_returns_true\n"
	      "String was empty after initializing\n", length);
    }
  else
    {
      status = SUCC;
      strncpy(buffer, "\ttest_esmith_my_string_empty_on_init_default_returns_true\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_esmith_init_c_string_returns_nonNULL(char* buffer, int length)
{
  Status status;
  MY_STRING hString = NULL;

  hString = my_string_init_c_string("Hey");
  if(hString == NULL)
    {
      status = FAIL;
      strncpy(buffer, "test_esmith_init_c_string_returns_nonNULL\n"
	      "init_c_string returns NULL", length);
    }
  else
    {
      status = SUCC;
      strncpy(buffer, "\ttest_esmith_init_c_string_returns_nonNULL\n", length);
    }
  my_string_destroy(&hString);
  return status;
}
