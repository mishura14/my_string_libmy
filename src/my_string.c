#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct str
{
    uint8_t* data;
    size_t capasity;
    size_t size;
}str_t;

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
void string_free(str_t* string){
    if (!string) return;
    free(string->data);
    free(string);
};

size_t string_length(const str_t* string){
    return string->size;
};
size_t string_print(const str_t* string, FILE* file){
    fwrite(string->data, 1, string->size, file);
    return string->size;
}
str_t* string_dup(const char *str){
    size_t len = strlen(str);
    str_t* string = string_create(len);
    if (!string) return NULL;
    memcpy(string->data,str, len);
    string->size = len;
    string ->data[len] = '\0';
    return string;
};
str_t* string_concat(const str_t* left,const str_t* right){
    str_t* string = string_create(left->size + right->size);
    if (!string)return NULL;
    memcpy(string->data, left->data, left->size);
    memcpy(string->data + left->size, right->data, right->size);
    string->size = left->size + right->size;
    string->data[string->size] = '\0';
    return string;
}
int main(void) {
    str_t* s1 = string_dup("hello ");
    str_t* s2 = string_dup("world");

    str_t* s3 = string_concat(s1, s2);

    string_print(s3, stdout);
    printf("\nlength = %zu\n", string_length(s3));

    string_free(s1);
    string_free(s2);
    string_free(s3);

    return 0;
}
