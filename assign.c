#include "include.h"

char* assign(int fd)
{
     lseek(fd,11,SEEK_SET);
     read(fd,&bytes_per_sector,2);

     read(fd,&sectors_per_cluster,1);

     read(fd,&reserved_sectors,2);


     read(fd,&no_of_fat_tables,1);

     read(fd,&root_entry_cnt,1);

     lseek(fd,22,SEEK_SET);
     read(fd,&fat_size,2);
     if(fat_size == 0) 
     {
	  lseek(fd,36,SEEK_SET);
	  read(fd,&fat_size,4);
     }


     lseek(fd,44,SEEK_SET);
     read(fd,&root_dir_cluster_no,4);

     first_data_sector_offset = ((fat_size * no_of_fat_tables) + reserved_sectors);

     data_start = cluster_begin_sector(first_data_sector_offset,2,sectors_per_cluster) * bytes_per_sector;

     fat_start = reserved_sectors * bytes_per_sector;

     char *version = calloc(10,sizeof(char));
     lseek(fd,0x52,SEEK_SET);
     read(fd,version,8);

     return version;
}
