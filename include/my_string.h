#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//создание стуктуры строки
typedef struct str
{
    uint8_t* data;
    size_t capasity;
    size_t size;
}str_t;

// создание строки
str_t* string_create(size_t capasity);

// освобождение памяти
void string_free(str_t* string);

// получение длины строки
size_t string_length(const str_t* string);

// печать строки
size_t string_print(const str_t* string, FILE* file);

// копирование строки
str_t* string_dup(const char *str);

// конкатенация строк
str_t* string_concat(const str_t* left,const str_t* right);
