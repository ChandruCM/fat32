#include "include.h"

unsigned int cluster_begin_sector(unsigned int address,unsigned int cluster,int bytes_per_sector)
{
     if(cluster < 2)
     {   
	  printf("ERROR\n");
	  exit(-1);
     }   
     return (((cluster - 2)  * bytes_per_sector ) + address);
}
