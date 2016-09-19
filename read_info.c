#include "include.h"

int read_info(unsigned int data_offset,unsigned int fat_offset)
{
     unsigned char *value = calloc(33,sizeof(char));
     unsigned int fat, size = 0, total_size = sectors_per_cluster * bytes_per_sector;
     lseek(fd,data_offset,SEEK_SET);

     while(size < total_size)
     {
	  memset(value,0,33);
	  read(fd,value,32);
	  if((flag == 0 && ((value[0] & 0xF0) == 0x40)) || (flag == 1))
	  {
	       long_name(fd,value,size);
	  }
	  else if(value[0] == 0)
	  {
	       return 0;
	  }
	  size +=32; 
     }
     lseek(fd,fat_offset,SEEK_SET);
     read(fd,&fat,4);
     if((fat &= 0x0FFFFFFF) < 0xFFFFFEF)
     {
	  read_info(cluster_begin_sector(first_data_sector_offset,fat,sectors_per_cluster) * bytes_per_sector,fat_start + (fat * 4));
     }
     return 0;
}
