# my_string — собственная библиотека строк на C

`my_string` — учебная реализация собственной строковой библиотеки на языке C.  
Проект создан для изучения работы со строками, динамической памятью, заголовочными файлами и статическими библиотеками.

---

## 📁 Структура проекта

my_string/
├── include/
│ └── my_string.h # Заголовочный файл библиотеки
├── src/
│ └── my_string.c # Реализация функций
├── tests/
│ └── test_string.c # Тесты
├── CMakeLists.txt
└── README.md


---

## 🧱 Тип данных

```c
typedef struct str {
    uint8_t* data;
    size_t capacity;
    size_t size;
} str_t;

    data — динамически выделенная строка

    capacity — выделенный размер памяти

    size — текущая длина строки (без \0)

📚 Реализованные функции
Создание и освобождение

str_t* string_create(size_t capacity);
void string_free(str_t* string);

Длина строки

size_t string_length(const str_t* string);  // длина собственной строки
size_t string_strlen(const char* s);        // длина C-строки (аналог strlen)

Работа со строками

str_t* string_dup(const char* str);                 // char* → str_t
str_t* string_concat(const str_t* left,
                     const str_t* right);           // конкатенация
size_t string_print(const str_t* string, FILE* f);  // вывод

🧪 Тестирование

Сборка и запуск тестов:

mkdir build
cd build
cmake ..
cmake --build .
./test_string

При успешном запуске:

ALL TESTS PASSED

🛠 Сборка статической библиотеки

Пример CMakeLists.txt:

cmake_minimum_required(VERSION 3.20)
project(my_string C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(my_string STATIC src/my_string.c)
target_include_directories(my_string PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(test_string tests/test_string.c)
target_link_libraries(test_string PRIVATE my_string)

📦 Использование библиотеки в другом проекте

    Подключить заголовок:

#include "my_string.h"

    При сборке:

    подключить libmy_string.a

    указать путь к include/

🎯 Цели проекта

    Понять, зачем нужны .h и .c

    Научиться работать с динамической памятью

    Разобраться, как создаются и используются статические библиотеки

    Освоить CMake на базовом уровне

🚀 Возможные улучшения

    string_push_back

    string_clear

    string_reserve

    Проверки переполнения

    Скрытие структуры (opaque struct)

    Больше тестов

📄 Лицензия

Проект создан в учебных целях. Свободное использование.


---

Если хочешь — следующим шагом можем:
- привести код к **идеальному стилю C**,
- добавить **Makefile вместо CMake**,
- или сделать **вторую версию библиотеки (v2)** с улучшенной архитектурой.
