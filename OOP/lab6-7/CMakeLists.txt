cmake_minimum_required(VERSION 3.22)
project(lab6_7)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_executable(lab6_7 main.cpp domain/Masina.cpp domain/Masina.h repo/Repo.cpp repo/Repo.h service/Service.cpp service/Service.h teste/teste.cpp teste/teste.h ui/Ui.cpp ui/Ui.h domain/VectorDinamic.h domain/Validator.cpp domain/Validator.h)
