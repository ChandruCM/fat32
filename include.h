#ifndef INCLUDE
#define INCLUDE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int fd, count, flag, j;
char *info;

unsigned int bytes_per_sector;
unsigned int sectors_per_cluster;
unsigned int reserved_sectors;
unsigned int no_of_fat_tables;
unsigned int root_entry_cnt;
unsigned int root_dir_cluster_no;
unsigned int first_data_sector_offset;
unsigned int data_start;
unsigned int fat_size;
unsigned int fat_start;

unsigned int cluster_begin_sector(unsigned int ,unsigned int ,int );
int read_info(unsigned int,unsigned int);
char* assign(int);
char* long_name(int ,unsigned char *,unsigned int);

#endif
