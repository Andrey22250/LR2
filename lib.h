#pragma once
#define len_name 35
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

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

struct PC
{
	CPU cpu;
	GPU gpu;
	RAM ram;
	motherboard motherboard;
	float price;
};

typedef enum Status { create, working, finished };

struct Build
{
	int number;
	PC pc;
	char* client;
	Status status;
};

//Вспомогательные функции
char* StatusTypeToString(Status status) {
	char* strStatus = (char*)calloc(len_name, sizeof(char));

	switch (status)
	{
	case create:
		strcpy(strStatus, "создан");
		break;
	case working:
		strcpy(strStatus, "в сборке");
		break;
	case finished:
		strcpy(strStatus, "готов к выдаче");
		break;
	default:
		break;
	}
	return strStatus;
}

//Основные функции


//Инициализация структур

CPU *init_cpu(char* name_cpu, int frequency, int cores, int treads)
{
	if (strlen(name_cpu) != 0 && frequency > 0 && cores > 0 && treads > 0)
	{
		CPU* cpu = (CPU*)calloc(1, sizeof(CPU));
		cpu->name_cpu = (char*)calloc(len_name, sizeof(char));
		strcpy(cpu->name_cpu, name_cpu);
		cpu->frequency = frequency;
		cpu->cores = cores;
		cpu->treads = treads;
		return cpu;
	}
	else
	{
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}

GPU* init_gpu(char* name_gpu, int vram, int TDP)
{
	if (strlen(name_gpu) != 0 && vram > 0 && TDP > 0)
	{
		GPU* gpu = (GPU*)calloc(1, sizeof(GPU));
		gpu->name_gpu = (char*)calloc(len_name, sizeof(char));
		strcpy(gpu->name_gpu, name_gpu);
		gpu->vram = vram;
		gpu->TDP = TDP;
		return gpu;
	}
	else
	{
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}

RAM* init_RAM(char* type_ddr, int frequency)
{
	if (type_ddr[0] == 'D' && type_ddr[1] == 'D' && type_ddr[2] == 'R' && frequency > 0)
	{
		RAM* ram = (RAM*)calloc(1, sizeof(RAM));
		ram->type_ddr = (char*)calloc(len_name, sizeof(char));
		strcpy(ram->type_ddr, type_ddr);
		ram->frequency = frequency;
	}
	else
	{
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}

motherboard* init_motherboard(char* name_motherboard, char* chipset)
{
	if (strlen(name_motherboard) > 0 && strlen(chipset) > 0)
	{
		motherboard* motherboard1 = (motherboard*)calloc(1, sizeof(motherboard));
		motherboard1->name_motherboard = (char*)calloc(len_name, sizeof(char));
		motherboard1->chipset = (char*)calloc(len_name, sizeof(char));
		strcpy(motherboard1->name_motherboard, name_motherboard);
		strcpy(motherboard1->chipset, chipset);
	}
	else
	{
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}

PC* init_PC(CPU cpu, GPU gpu, RAM ram, motherboard motherboard, float price)
{
	if (price > 0)
	{
		PC* pc = (PC*)calloc(1, sizeof(PC));
		pc->cpu = cpu;
		pc->gpu = gpu;
		pc->ram = ram;
		pc->motherboard = motherboard;
		pc->price = price;
	}
	else
	{
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}

Build* build(int number, PC pc, char* client, Status status)
{
	if (number > 0 && strlen(client) != 0 && status >= create && status <= finished)
	{
		Build* build = (Build*)calloc(1, sizeof(Build));
		build->client = (char*)calloc(len_name, sizeof(char));
		strcpy(build->client, client);
		build->number = number;
		build->pc = pc;
		build->status = status;
	}
	else
	{
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}