
cmake_minimum_required(VERSION 3.20)
project(my_string C)

# Устанавливаем стандарт C
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Включаем предупреждения
add_compile_options(-Wall -Wextra)

# Пути к заголовочным файлам
include_directories(${CMAKE_SOURCE_DIR}/include)

# Создание статической библиотеки
add_library(my_string STATIC
    src/my_string.c
)

# Определяем исполняемый файл для тестов
add_executable(tests_string
    tests/test_string.c
)

# Линкуем библиотеку с тестами
target_link_libraries(tests_string PRIVATE my_string)

# Опционально: добавим цель для запуска тестов
add_custom_target(run_tests
    COMMAND tests_string
    DEPENDS tests_string
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
