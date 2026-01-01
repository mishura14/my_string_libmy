
# минимальная версия CMake
cmake_minimum_required(VERSION 3.20)

# имя проекта, язык и версия
project(my_string VERSION 1.0.0 LANGUAGES C)

# стандарт C
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ========== библиотека ==========
add_library(my_string SHARED
    src/my_string.c
)

# путь к заголовкам
target_include_directories(my_string PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# версия библиотеки (для .so)
set_target_properties(my_string PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# ========== тесты ==========
add_executable(tests_string
    tests/tests_string.c
)

target_link_libraries(tests_string PRIVATE
    my_string
)
