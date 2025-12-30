#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct str
{
    uint8_t* data;
    uint8_t length;
    uint8_t how_much;
}str_t;

str_t* string_create(uint8_t length)
{
    str_t* string = malloc(sizeof(str_t));
    string->data = malloc(length);
    string->length = length;
    string->how_much = 0;
    return string;
};
void string_free(str_t* string){
    free(string->data);
    free(string);
};

uint8_t string_lengrh(str_t* string){
    return string->length;
};
void string_print(str_t* string, FILE* file){
    fwrite(string->data, sizeof(uint8_t), string->length, file);
}
str_t* string_dup(const char *str){
  str_t* string = string_create((uint8_t)strlen(str));
  memcpy(string->data,str,string->length);
  string->how_much = string->length;
  return string;
};
str_t* string_concat(str_t* left, str_t* right){
    str_t* string = string_create(left->length + right->length);
    memcpy(string->data, left->data, left->length);
    memcpy(string->data + left->length, right->data, right->length);
    string->how_much = string->length;
    return string;
}
int main(){
    str_t* string = string_dup("hellow world");
    string_print(string, stdout);
    fprintf(stdout, "\n length = %d", string_lengrh(string));
    string_free(string);
    return 0;
}
