#Будем использовать более-менее современную версию CMake.
cmake_minimum_required(VERSION 3.20)

#Проект будет на C/C++.
project(ttf-raster C CXX)

#Будем использовать стандарт c++20.
set(CMAKE_CXX_STANDART 20)
#c17.
set(CMAKE_C_STANDART 17)

#Включаем тестирование.
enable_testing()

#Добавляем gtest в наш проект.
add_subdirectory(googletest)

#Добавляем в наш проект файлы для тестирования
add_subdirectory(test)