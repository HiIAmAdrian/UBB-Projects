cmake_minimum_required(VERSION 3.22.1)
project(lab02_04 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_executable(lab02_04 main.c repo/repo.h domain/RawMaterial.h domain/RawMaterial.c repo/repo.c service/service.c service/service.h UI/ui.c UI/ui.h teste/teste.c teste/teste.h validator.c validator.h)
