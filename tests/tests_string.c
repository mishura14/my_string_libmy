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

    // Освобождаем память
    string_free(s1);
    string_free(s2);
    string_free(s3);

    return 0;

}
