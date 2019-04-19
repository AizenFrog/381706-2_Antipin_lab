cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-2_Antipin_lab) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(time_check time_check)
set(vector vector) #Переменная с именем библиотеки
set(vectorlib vectorlib) #Переменная с именем библиотеки
set(vectortest vectortest)
set(stack_and_queue stack_and_queue) #Переменная с именем библиотеки
set(stack_and_queue_lib stack_and_queue_lib) #Переменная с именем библиотеки
set(stack_and_queue_tests stack_and_queue_tests)
set(list list)
set(list_lib list_lib)
set(list_tests list_tests)
set(math_function math_function)
set(math_function_lib math_function_lib)
set(math_function_tests math_function_tests)
set(text_editor text_editor) #Переменная с именем библиотеки
set(text_editor_lib text_editor_lib) #Переменная с именем библиотеки
set(text_editor_test text_editor_test)
set(figures figures)
set(figureslib figureslib)
set(figurestest figurestest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/vectorlib ${CMAKE_CURRENT_SOURCE_DIR}/stack_and_queue_lib ${CMAKE_CURRENT_SOURCE_DIR}/list_lib ${CMAKE_CURRENT_SOURCE_DIR}/math_function_lib ${CMAKE_CURRENT_SOURCE_DIR}/text_editor_lib ${CMAKE_CURRENT_SOURCE_DIR}/figureslib ${CMAKE_CURRENT_SOURCE_DIR}/gtest ${CMAKE_CURRENT_SOURCE_DIR}/time_check)
add_subdirectory(time_check)
add_subdirectory(vector) #Собираем проект в поддиректории vector
add_subdirectory(vectorlib) #Собираем проект в поддиректории lib
add_subdirectory(vectortest)
add_subdirectory(stack_and_queue) #Собираем проект в поддиректории vector
add_subdirectory(stack_and_queue_lib) #Собираем проект в поддиректории lib
add_subdirectory(stack_and_queue_tests)
add_subdirectory(list)
add_subdirectory(list_lib)
add_subdirectory(list_tests)
add_subdirectory(math_function)
add_subdirectory(math_function_lib)
add_subdirectory(math_function_tests)
add_subdirectory(text_editor) #Собираем проект в поддиректории vector
add_subdirectory(text_editor_lib) #Собираем проект в поддиректории lib
add_subdirectory(text_editor_test)
add_subdirectory(figures)
add_subdirectory(figureslib)
add_subdirectory(figurestest)
add_subdirectory(gtest)

#file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
#file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .h


#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}

#add_subdirectory(lib1) #Собираем проект в поддиректории lib1
#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}