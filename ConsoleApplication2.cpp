#include <stdio.h>
#include <windows.h>
#include <malloc.h>
#include "lib.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //пример работы со статической переменной
    Build staticEx = input_build();
    Output_build(staticEx);
    Output_PC_spec(staticEx.pc);
    undervolt_gpu(&staticEx.pc);
    Output_PC_spec(staticEx.pc);

    //и с динамической
    Build *dynamic = (Build*)calloc(1, sizeof(Build));
    dynamic = init_build(5, input_pc(), (char*)"Андрей" , create);
    Output_build(*dynamic);
    Output_PC_spec(dynamic->pc);
    undervolt_gpu(&dynamic->pc);
    ChangeStatus(dynamic, working);
    Output_build(*dynamic);
    Output_PC_spec(dynamic->pc);
    cleanmemory(dynamic);
    free(dynamic);
}