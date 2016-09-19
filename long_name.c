#include "include.h"

char* long_name(int fd,unsigned char *value,unsigned int size)
{
     int i;
     if(flag == 0)
     {
     	  free(info);
	  info = calloc((value[0] & 0x0F) * 13,sizeof(char));
	  flag = 1;
	  j = ((value[0] & 0x0F) - 1) * 13;
     }
     else
     {
	  j = ((value[0] & 0x0F) - 1) * 13;
     }
     for(i = 1;i < 32;i++)
     {
	  if(i > 0x0B && i <= 0x0D)
	  {
	       continue;
	  }
	  if(isprint(value[i]) != 0)
	  {
	       info[j++] = value[i];
	  }
     }
     if((value[0] & 0x0F) == 1)
     {
	  flag = 0;
	  j = 0;
	       if(count != 1)
	       {
		    printf("|");
	       }
	  for(i = 0; i < count;i++)
	  {
	       if(count - 1 == i)
	       {
		    printf("`-- ");
	       }
	       else
	       {
		    printf("   ");
	       }
	  }
	  read(fd,value,32);
	  size += 32;
	  if((value[11] & 0x10) == 0x10)
	  {
	       printf("\033[01;34m%s\033[00m\n",info);
	       count++;
	       int pos = lseek(fd,0,SEEK_CUR);
	       unsigned int cluster_no = (value[21] << (3 * 8))|(value[20] << (2 * 8))|(value[27] << (1 * 8))|(value[26] << (0 * 8));
	       read_info(cluster_begin_sector(first_data_sector_offset,cluster_no,sectors_per_cluster) * bytes_per_sector, \
			 fat_start + (cluster_no * 4));
	       lseek(fd,pos,SEEK_SET);
	       count--;
	  }
	  else
	  {
	       printf("\033[01;32m%s\033[00m\n",info);
	  }
	  return 0;
     }
     return 0;
}
