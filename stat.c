#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>

int main()
{
  struct stat lol;
  //char cwd[256];
  //int fd=open("file",O_RDONLY);
  //getcwd(cwd,sizeof(cwd));
  //printf("%s\n",strcat(cwd,"/file"));
  if(stat("file",&lol)==0)
    {
      printf("Printing file information\n");
      printf("file size: %d GB ",lol.st_size/(1024*1024*1024));
      printf("%d MB ",lol.st_size/(1024*1024));
      printf("%d KB ",lol.st_size/1024);
      printf("%d bytes\n",lol.st_size%1024);
      printf("last time of access: %s",ctime(&lol.st_atime) );
      printf("File Permissions:   ");
      printf( (S_ISDIR(lol.st_mode)) ? "d" : "-");
      printf( (lol.st_mode & S_IRUSR) ? "r" : "-");
      printf( (lol.st_mode & S_IWUSR) ? "w" : "-");
      printf( (lol.st_mode & S_IXUSR) ? "x" : "-");
      printf( (lol.st_mode & S_IRGRP) ? "r" : "-");
      printf( (lol.st_mode & S_IWGRP) ? "w" : "-");
      printf( (lol.st_mode & S_IXGRP) ? "x" : "-");
      printf( (lol.st_mode & S_IROTH) ? "r" : "-");
      printf( (lol.st_mode & S_IWOTH) ? "w" : "-");
      printf( (lol.st_mode & S_IXOTH) ? "x" : "-");
      printf("\n");
      return 0;
    }
  
  printf("Unable to print info, something went wrong");
  return 0;
}
