#include "my_string.h"
#include <stdio.h>

int main()
{
    //тест создания строки
    str_t* s1 = string_create(10);
    if (!s1){
        printf("failed to create string\n");
        return 1;
    };
    // тест проверки длины
    if (string_length(s1) != 0){
        printf("string length is not zero\n");
        return 1;
    }
    if (string_strlen("hello") != 5){
        printf("string length is not 5\n");
        return 1;
    }

    // Тест копирование строки
    str_t* s2 = string_dup("hello");
    if (string_length(s2) != 5) {
        printf("FAIL: string_length after dup = %zu\n", string_length(s2));
        return 1;
    }

    // Тест соединение строк
    str_t* s3 = string_concat(s1, s2);
    if (string_length(s3) != 5) {
        printf("FAIL: string_concat length = %zu\n", string_length(s3));
        return 1;
    }
    printf("ALL TESTS PASSED\n");


    // тест нахождение подстроки
    str_t* s_haystack = string_dup("hello");
    str_t* s_needle   = string_dup("lo");

    uint8_t* pos = string_strstr(s_haystack, s_needle);
    if (!pos) {
        printf("FAIL: string_strstr did not find substring\n");
        return 1;
    } else {
        printf("string_strstr found substring at index %ld\n", pos - s_haystack->data);
    }

    //тест функия находит указатель на первый символ строки который совпадает одинм символов другой строки
    uint8_t* n = string_strpbrk(s_haystack, s_needle);
    if (!n) {
        printf("FAIL: string_strpbrk did not find substring\n");
        return 1;
    } else {
        printf("string_strpbrk found substring at index %ld\n", n - s_haystack->data);
    }

    // string_strcspn
    size_t len = string_strcspn(s_haystack, s_needle);
    if (len == 2) {
        printf("string_strcspn: first forbidden character at index %zu\n", len);
    } else {
        printf("FAIL: string_strcspn length = %zu\n", len);
        return 1;
    }

    // string_strspn
    str_t* i = string_dup("hel");
    size_t nel = string_strspn(s_haystack, i);
    if (nel == 4) {
        printf("string_strspn: initial segment length = %zu\n", nel);
    } else {
        printf("FAIL: string_strspn length = %zu\n", nel);
        return 1;
    };


    // Освобождаем память
    string_free(s1);
    string_free(s2);
    string_free(s3);
    string_free(s_haystack);
    string_free(s_needle);

    return 0;

}
