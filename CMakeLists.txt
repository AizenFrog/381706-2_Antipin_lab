cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-2_Antipin_lab) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(vector vector) #Переменная с именем библиотеки
set(vectorlib vectorlib) #Переменная с именем библиотеки
set(vectortest vectortest)
set(stack_and_queue stack_and_queue) #Переменная с именем библиотеки
set(stack_and_queue_lib stack_and_queue_lib) #Переменная с именем библиотеки
set(stack_and_queue_tests stack_and_queue_tests)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/vectorlib ${CMAKE_CURRENT_SOURCE_DIR}/stack_and_queue_lib ${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(vector) #Собираем проект в поддиректории vector
add_subdirectory(vectorlib) #Собираем проект в поддиректории lib
add_subdirectory(vectortest)
add_subdirectory(stack_and_queue) #Собираем проект в поддиректории vector
add_subdirectory(stack_and_queue_lib) #Собираем проект в поддиректории lib
add_subdirectory(stack_and_queue_tests)
add_subdirectory(gtest)

#file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
#file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .h


#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}

#add_subdirectory(lib1) #Собираем проект в поддиректории lib1
#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}