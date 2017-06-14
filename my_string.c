#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_string.h"

struct STRING
{
  int size;
  int capacity;
  char* ch;
};
typedef struct STRING String;

MY_STRING my_string_init_default(void)
{
  String* pStr = (String*) malloc(sizeof(String));
  if (pStr != NULL)
  {
    pStr->size = 0;
    pStr->capacity = 7;
    pStr->ch = (char*)malloc(sizeof(char) * pStr->capacity);
    if (pStr->ch == NULL)
      {
	free(pStr);
        pStr = NULL;
      }
  }
  return (MY_STRING)pStr;
}

void my_string_destroy(MY_STRING* phMy_string)
{
  String* pStr = (String*) *phMy_string;

  free(pStr->ch);
  free(pStr);
  *phMy_string = NULL;
}

MY_STRING my_string_init_c_string(const char* c_string)
{
  int i = 0;
  String* pStr = (String*) malloc(sizeof(String));
  if (pStr != NULL)
    {
      while (c_string[i] !='\0')
	{
	  i++;
	}
      pStr->size = i;
      pStr->capacity = pStr->size + 1;
      pStr->ch = (char*)malloc(sizeof(char) * pStr->capacity);
      if (pStr->ch == NULL)
	{
	  free(pStr);
	  pStr = NULL;
	}
    }
    return (MY_STRING)pStr;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
  String* pStr = (String*)hMy_string;
  return pStr->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
  String* pStr = (String*)hMy_string;
  return pStr->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
  String* pLstr = (String*)hLeft_string;
  String* pRstr = (String*)hRight_string;
  return (pLstr->size - pRstr->size);
}
				  
Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
  int i;
  char* temp;
  String* pStr = (String*) hMy_string;
  int numOfCon = 0;
  
  if (!feof(fp))
    {
      numOfCon = fscanf(fp, "%s", pStr->ch);
    }
  if(pStr->size >= pStr->capacity)
      {
	temp = (char*) malloc(sizeof(char)* pStr->capacity * 2);
	if(temp == NULL)
	  {
	    return FAIL;
	  }
	for(i = 0; i < pStr->size; i++)
	  {
	    temp[i] = pStr->ch[i];
	  }
	free(pStr->ch);
	pStr->ch = temp;
	pStr->capacity *= 2;
      }
  
  if (numOfCon == 0 || numOfCon == -1)
    {
      return FAIL;
    }
  else
    {
      return SUCC;
    }
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
  String* pStr = (String*)hMy_string;
  int x = 29;

  if(strlen(pStr->ch) == x)
    {
      fprintf(fp, "%s", pStr->ch);
    }
  if(fgetc(fp) == 0)
    {
      return FAIL;
    }
  else
    {
      return SUCC;
    }
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
  int i;
  char* temp;
  String* pStr = (String*)hMy_string;

  if(pStr->size >= pStr->capacity)
    {
      temp = (char*) malloc(sizeof(char)* pStr->capacity * 2);
      if(temp == NULL)
	{
	  return FAIL;
	}
      for(i = 0; i < pStr->size; i++)
	{
	  temp[i] = pStr->ch[i];
	}
      free(pStr->ch);
      pStr->ch = temp;
      pStr->capacity *= 2;
    }
  pStr->ch[pStr->size] = item;
  pStr->size++;
  return SUCC;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
  String* pStr = (String*)hMy_string;

  if(pStr->size == 0)
    {
      return FAIL;
    }
  pStr->size--;
  return SUCC;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
  String* pStr = (String*)hMy_string;

  if(index >= pStr->size)
    {
      return NULL;
    }
  return &(pStr->ch[index]);
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
  int i, a;
  char* temp;
  String* pResult = (String*)hResult;
  String* pAppend = (String*)hAppend;
  int b = pResult->size;
  
  if((pResult->size + pAppend->size) >= pResult->capacity)
    {
      temp = (char*) malloc(sizeof(char)* pResult->capacity * 2);
	if(temp == NULL)
	  {
	    return FAIL;
	  }
	for(i = 0; i < pResult->size; i++)
	  {
	    temp[i] = pResult->ch[i];
	  }
	free(pResult->ch);
	pResult->ch = temp;
	pResult->capacity *= 2;
    }
  for(i = 0; i < (pAppend->size); i++)
    {
      pResult->ch[i + pResult->size] = pAppend->ch[i];
      pResult->size++;
    }
  a = pResult->size;
          
  if (a > b)
    {
      return SUCC;
    }
  else
    {
      return FAIL;
    }
}

Boolean my_string_empty(MY_STRING hMy_string)
{
  String* pStr = (String*)hMy_string;

  if (pStr->size == 0)
    {
      return TRUE;
    }
  else
    {
      return FALSE;
    }
}
