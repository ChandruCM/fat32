#include "include.h"


int main(int argc,char *argv[])
{
     if(argc != 2)
     {
     	  printf("ERROR : PASS ARGUEMENT PROPERLY\n");
     	  return -1;
     }

     if((fd = open(argv[1],O_RDONLY)) == -1)
     {
	  printf("ERROR\n");
	  return -1;
     }

     if(strncmp(assign(fd),"FAT32",5) != 0)
     {
	  printf("ERROR\n");
	  return -1;
     }

     count++;
     printf("count---%d\n",count);
     read_info(data_start,fat_start + (2 * 4));

     return 0;
}
