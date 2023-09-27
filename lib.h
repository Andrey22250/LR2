#pragma once
#define len_name 35

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
	char type_ddr[7];
	int frequency;
};

struct motherboard
{
	char *name_motherboard;
	char* chipset;
};

struct PC
{
	CPU cpu;
	GPU gpu;
	RAM ram;
	motherboard motherboard;
	char* client;
};

