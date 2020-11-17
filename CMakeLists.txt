cmake_minimum_required(VERSION 3.17)
project(project C)
set(CMAKE_C_STANDARD 99)
add_executable(project check_arg.c file.c ft_atoif.c ft_printf.c ft_printf.h ft_strchrf.c ft_strcpyf.c get_arguments.c
        memsetting.c parser.c print.c print_processing.c string_print.c value_print1.c itoa_functions.c
        value_print2.c print_pointer.c ptr_init.c free_memory.c)