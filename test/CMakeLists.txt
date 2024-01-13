#Будем использовать более-менее современную версию CMake.
cmake_minimum_required(VERSION 3.20)

#Проект будет на C++.
project(ttf-raster-test CXX)

#Минимальная необходимая версия стандарта c++14 будем использовать её.
set(CMAKE_CXX_STANDART 14)

#Задаём список файлов исходного кода для тестирования
set(SOURCE_TESTS
  #Пока тут пусто(
)

#Создаём исполняемый файл для запуска тестирования
#Их может быть несколько поэтому вместо PROJECT_NAME 
#стоит использовать другие имена
add_executable(${PROJECT_NAME} ${SOURCE_TESTS})

#Добавим библиотеки для тестирования
target_link_libraries(
  ${PROJECT_NAME} PUBLIC
  gtest_main
  gmock_main
)

#Добавим их в списки тестов
add_test(
	NAME ${PROJECT_NAME}
	COMMAND ${PROJECT_NAME}
)