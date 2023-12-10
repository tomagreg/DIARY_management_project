cmake_minimum_required(VERSION 3.24)
project(Diary_management C)

set(CMAKE_C_STANDARD 99)

add_executable(Diary_management main.c contact.h contact.c date.c linked_list.h linked_list.c level_list.h level_list.c date.h menu.h menu.c cells.c lists.c timer.c)
