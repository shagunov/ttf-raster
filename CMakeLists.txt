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
add_subdirectory(external/googletest)

#Добавляем в наш проект файлы для тестирования
add_subdirectory(test)

#Добавляем в наш проект проект документации
add_subdirectory(docs)

add_executable(workk main.cpp)

set_target_properties(workk PROPERTIES CMAKE_CONFIGURATION_TYPES DEBUG_CONFIGURATIONS)

find_package(Vulkan REQUIRED)
target_include_directories(workk PUBLIC head ${Vulkan_INCLUDE_DIRS} SYSTEM)

find_package(Boost REQUIRED)
include_directories(SYSTEM head ${Boost_INCLUDE_DIRS})
target_link_libraries(workk PUBLIC ${Boost_LIBRARIES})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
