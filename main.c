#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[])
{
  MY_STRING hRString = NULL;
  MY_STRING hAString = NULL;
  char ch = 'a';
  
  hRString = my_string_init_default();
  hAString = my_string_init_default();

  if(my_string_push_back(hRString, ch) && my_string_push_back(hAString, ch))
    {
      if (my_string_concat(hRString, hAString))
	{
	  printf("Sucess!\n");
	}
      else
	{
	  printf("Failure\n");
	}
    }

  my_string_destroy(&hRString);
  my_string_destroy(&hAString);
  return 0;
}
