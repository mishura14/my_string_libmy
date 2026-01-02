#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//
typedef struct str
{
    uint8_t* data;
    size_t capasity;
    size_t size;
}str_t;
//функция создания строки
str_t* string_create(size_t capasity)
{
    str_t* string = malloc(sizeof *string);
    if (!string) return NULL;
    string->data = malloc(capasity + 1);
    if (!string->data){
        free(string);
        return NULL;
    }
    string->capasity = capasity;
    string->size = 0;
    return string;
};
// функция освобождения памяти
void string_free(str_t* string){
    if (!string) return;
    free(string->data);
    free(string);
};
// функция получения длины строки
size_t string_length(const str_t* string){
    return string->size;
};
//функция подсчета количества символов в строке
size_t string_strlen(const char *s)
{
    if(s == NULL){
        return 0;
    };
    size_t len = 0;
    while (s[len] != '\0'){
        len++;
    };
    return len;

};
// функция вывода строки
size_t string_print(const str_t* string, FILE* file){
    fwrite(string->data, 1, string->size, file);
    return string->size;
};
// функция копирования строки
str_t* string_dup(const char *str){
    size_t len = string_strlen(str);
    str_t* string = string_create(len);
    if (!string) return NULL;
    memcpy(string->data,str, len);
    string->size = len;
    string ->data[len] = '\0';
    return string;
};
// функция конкатенации строк
str_t* string_concat(const str_t* left,const str_t* right){
    str_t* string = string_create(left->size + right->size);
    if (!string)return NULL;
    memcpy(string->data, left->data, left->size);
    memcpy(string->data + left->size, right->data, right->size);
    string->size = left->size + right->size;
    string->data[string->size] = '\0';
    return string;
};
//функция нахождение первого вхождение подствроки в строке
uint8_t* string_strstr(const str_t* strstr, const str_t* str)
{
    if (!strstr || !str) return NULL;
    if (str->size == 0) return NULL;

    for(int i = 0; i <= strstr->size - str->size; i++){
        int j = 0;
        while(j < str->size && strstr->data[i + j] == str->data[j]){
            j++;
        }
        if (j == str->size){
            return strstr->data + i;
        };
    }
    return NULL;
};
//функия находит указатель на первый символ строки который совпадает одинм символов другой строки
uint8_t* string_strpbrk(const str_t* strstr, const str_t* str){
    if (!strstr || !str) return NULL;
    if (str->size == 0) return NULL;
    for(size_t i = 0; i < strstr->size; i++){
        for(size_t j = 0; j < str->size; j++){
            if (strstr->data[i] == str->data[j]){
                return strstr->data + i;
            }
        }
    }
    return NULL;
}
//функция возвращет длину начального участка строки состаящего ез символов которые не входят в другую строку

size_t string_strcspn(const str_t* strstr, const str_t* str)
{
    if (!strstr || !str) return 0;
    if (strstr->size == 0) return 0;
    if (str->size == 0) return strstr->size;

    size_t len = 0;
    for (size_t i = 0; i < strstr->size; i++) {
        int found = 0;
        for (size_t j = 0; j < str->size; j++) {
            if (strstr->data[i] == str->data[j]) {
                found = 1;
                break;
            }
        }
        if (found) return len;
        len++;
    }
    return len;
}

//функция возвращет длину начального участка строки состаящего ез символов которые входят в другую строку
size_t string_strspn(const str_t* haystack, const str_t* accept)
{
    if (!haystack || !accept) return 0;
    if (haystack->size == 0) return 0;
    if (accept->size == 0) return 0;

    size_t len = 0;

    for (size_t i = 0; i < haystack->size; i++) {
        int match = 0;
        for (size_t j = 0; j < accept->size; j++) {
            if (haystack->data[i] == accept->data[j]) {
                match = 1;
                break;
            }
        }
        if (!match) {
            return len;
        }
        len++;
    }

    return len;
}
