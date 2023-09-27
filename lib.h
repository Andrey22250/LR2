#pragma once
#define len_name 35
#include <malloc.h>
#include <string.h>
#include <iostream>

void clean()  //Очистка потока
{
	while (getchar() != '\n');
}

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
	int frequency, mem;
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
char* StatusToString(Status status) {
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

RAM* init_RAM(char* type_ddr, int frequency, int mem)
{
	if (type_ddr[0] == 'D' && type_ddr[1] == 'D' && type_ddr[2] == 'R' && frequency > 0)
	{
		RAM* ram = (RAM*)calloc(1, sizeof(RAM));
		ram->type_ddr = (char*)calloc(len_name, sizeof(char));
		strcpy(ram->type_ddr, type_ddr);
		ram->frequency = frequency;
		ram->mem = mem;
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

Build* init_build(int number, PC pc, char* client, Status status)
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

//Ввод структур

CPU input_cpu()
{
	printf("Ввод параметров процессора\n");
	char* name_cpu = (char*)calloc(len_name, sizeof(char));
	int frequency;
	int cores, treads;
	printf("Введите название процессора: ");
	gets_s(name_cpu, len_name);
	do
	{
		printf("Введите частоту процессора в МГЦ: ");
		scanf("%d", &frequency);
		clean();
	} while (frequency<=0 && frequency>=7000);
	do
	{
		printf("Введите кол-во ядер: ");
		scanf("%d", &cores);
		clean();
	} while (cores <= 0 && cores>256);
	do
	{
		printf("Введите кол-во потоков: ");
		scanf("%d", &treads);
		clean();
	} while (treads <= 0 && treads>512);
	return *init_cpu(name_cpu, frequency, cores, treads);
}

GPU input_gpu()
{
	printf("Ввод параметров видеокарты\n");
	char* name_gpu = (char*)calloc(len_name, sizeof(char));
	int vram, TDP;
	printf("Введите название видеокарты: ");
	gets_s(name_gpu, len_name);
	do
	{
		printf("Введите объём видеопамяти в МБ: ");
		scanf("%d", &vram);
		clean();
	} while (vram <= 0);
	do
	{
		printf("Введите TDP в ваттах: ");
		scanf("%d", &TDP);
		clean();
	} while (TDP <= 0);
	return *init_gpu(name_gpu, vram, TDP);
}

RAM input_ram()
{
	printf("Ввод параметров ОЗУ\n");
	char* type_ddr = (char*)calloc(len_name, sizeof(char));
	int frequency, mem;
	printf("Введите тип ОЗУ: ");
	gets_s(type_ddr, len_name);
	do
	{
		printf("Введите частоту ОЗУ в МГЦ: ");
		scanf("%d", &frequency);
		clean();
	} while (frequency <= 0 && frequency >= 12000);
	do
	{
		printf("Введите объём ОЗУ: ");
		scanf("%d", &mem);
		clean();
	} while (mem <= 0);
	return *init_RAM(type_ddr, frequency, mem);
}

motherboard input_motherboard()
{
	printf("Ввод параметров материнской платы\n");
	char* name_motherboard = (char*)calloc(len_name, sizeof(char));
	char* chipset = (char*)calloc(len_name, sizeof(char));
	printf("Введите название материнской платы: ");
	gets_s(name_motherboard, len_name);
	printf("Введите чипсет: ");
	gets_s(chipset, len_name);
	return *init_motherboard(name_motherboard, chipset);
}

PC input_pc()
{
	float price;
	printf("Ввод информации о компьютере\n");
	do
	{
		printf("Введите цену ПК: ");
		scanf("%.2f",&price);
		clean();
	} while (price <= 0);
	return *init_PC(input_cpu(), input_gpu(), input_ram(), input_motherboard(), price);
}

Build input_build()
{
	int number;
	char* client = (char*)calloc(len_name, sizeof(char));
	printf("Ввод данных заказа\n");
	do
	{
		printf("Введите номер заказа: ");
		scanf("%d", &number);
		clean();
	} while (number <= 0);
	printf("Введите имя клиента: ");
	gets_s(client, len_name);
	Status status;
	do
	{
		printf("Введите статус заказа, где\n0 - Заказ создан\n1 - Заказ в работе\n2 - Заказ выполнен\nВаш выбор: ");
		scanf("%d", &status);
		clean();
	} while (status < 0 && status > 2);
	return *init_build(number, input_pc(), client, status);
}

//Вывод структур
int Output_PC_spec(PC pc)
{
	printf("Информация о сборке:\n\n");
	printf("Процессор: %s, %d МГЦ, %d ядер, %d потоков\n", pc.cpu.name_cpu, pc.cpu.frequency, pc.cpu.cores, pc.cpu.treads);
	printf("Видеокарта: %s, %d VRAM, %d TDP\n", pc.gpu.name_gpu, pc.gpu.vram, pc.gpu.TDP);
	printf("ОЗУ: %s, %d частота, %d объём\n", pc.ram.type_ddr, pc.ram.frequency, pc.ram.mem);
	printf("Материнская плата: %s, %s чипсет\n", pc.motherboard.name_motherboard, pc.motherboard.chipset);
	printf("Цена сборки %.2lf\n", pc.price);
	return 1;
}

int Output_build(Build build)
{
	printf("Информация о заказе:\n\n");
	printf("Номер заказа: %d\n", build.number);
	printf("Клиент - %s\n", build.client);
	printf("Статус - %s\n", StatusToString(build.status));
}

//Дополнительные функции
void undervolt_gpu(GPU *gpu)
{
	int TDP_lowest = gpu->TDP * 0.85;
	if()
}