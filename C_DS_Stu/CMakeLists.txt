cmake_minimum_required(VERSION 3.28)
project(C_DS_Stu C)

set(CMAKE_C_STANDARD 99)

add_library(C_DS_Stu STATIC library.c
        LinearList/SeqList.c
        LinearList/LinkList.c
        LinearList/CdList.c
        LinearList/Experiment_LinkList.c
        Stack/SeqStack.c
        Stack/LinkStack.c)
