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

// получение длины строки
size_t string_strlen(const char *s);

// печать строки
size_t string_print(const str_t* string, FILE* file);

// копирование строки
str_t* string_dup(const char *str);

// конкатенация строк
str_t* string_concat(const str_t* left,const str_t* right);

//функция нахождение первого вхождение подствроки в строке
uint8_t* string_strstr(const str_t* strstr, const str_t* str);

//функия находит указатель на первый символ строки который совпадает одинм символов другой строки
uint8_t* string_strpbrk(const str_t* strstr, const str_t* str);

//функция возвращет длину начального участка строки состаящего ез символов которые не входят в другую строку
size_t string_strcspn(const str_t* strstr, const str_t* str);

//функция возвращет длину начального участка строки состаящего ез символов которые входят в другую строку
size_t string_strspn(const str_t* strstr, const str_t* str);
