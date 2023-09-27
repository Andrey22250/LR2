#pragma once
#define len_name 35
#include <malloc.h>
#include <string.h>

struct CPU
{
	char *name_cpu;
	int frequency;
	int cores;
	int treads;
};

struct GPU
{
	char *name_gpu;
	int vram;
	int TDP;
};

struct RAM
{
	char *type_ddr;
	int frequency;
};

struct motherboard
{
	char *name_motherboard, *chipset;
};

struct psu
{
	char* name_psu;
	int power;
};

struct PC
{
	CPU cpu;
	GPU gpu;
	RAM ram;
	motherboard motherboard;
	psu psu;
	float price;
};

typedef enum Status { create, working, finished };

struct build
{
	int number;
	PC pc;
	char* client;
	Status status;
};

//Вспомогательные функции
char* check_ddr(RAM *type_ddr)
{
	char* str = (char*)calloc(5, sizeof(char));
	strcpy(str, type_ddr);
	if (str[0] != 'D' && str[1] != 'D' && str[2]!='R')
		return
}