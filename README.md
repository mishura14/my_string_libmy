# Моя реализация string

# Вот структура реализации string.

```C
typedef struct str
{
    uint8_t* data;
    size_t capasity;
    size_t size;
}str_t;
```
Для сборки библиотеки нужно
создать папку build
```
mkdir build
```
нужно в нее перейти 
```
cd build
```
и выполнить команды
```
cmake ..
cmake --build .
```
# В моем string реализованы следующие функции:
- string_create
  ```c
  str_t* string_create(const char* str);
    ```
- string_free
  ```c
  void string_free(str_t* str);
    ```
- string_length
  ```c
  size_t string_length(const str_t* str);
    ```
- string_strlen
  ```c
  size_t string_strlen(const str_t* str);
    ```
- string_print
  ```c
  void string_print(const str_t* str);
    ```
- string_dup
  ```c
  str_t* string_dup(const str_t* str);
    ```
- string_strstr
  ```c
  str_t* string_strstr(const str_t* str, const char* substr);
    ```
- string_strpbrk
  ```c
  str_t* string_strpbrk(const str_t* str, const char* chars);
    ```
- string_concat
  ```c
  str_t* string_concat(str_t* str1, const str_t* str2);
    ```
- string_strcspn
  ```c
  size_t string_strcspn(const str_t* str, const char* chars);
    ```
- string_strspn
  ```c
  size_t string_strspn(const str_t* str, const char* chars);
    ```
этого хвантит для безопасной работы со строками
