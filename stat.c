#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
//#include <sys/type.h>

int main()
{
  struct stat *lol;
  //char cwd[256];
  //int fd=open("file",O_RDONLY);
  //getcwd(cwd,sizeof(cwd));
  //printf("%s\n",strcat(cwd,"/file"));
  if(stat("file",lol)==0)
    {
      //printf("works?\n");
      printf("file size: %lld\n",lol->st_size);
      printf("last time of access: %ld\n",lol->st_atime);
      printf("permissions: %hu",lol->st_mode); 
      //return 0;
    }
  

  return 0;
}
