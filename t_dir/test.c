#include <dirent.h>  
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
int main(void)
{ FILE *fp;
  DIR           *d;
  struct dirent *dir;
  char *filenames[8];
  int a;
  int i = 0;
  d = opendir(".");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      filenames[i] = malloc(strlen(dir->d_name)+1);
      strcpy(filenames[i],(char *)dir->d_name);
      printf("%s", *filenames);
      printf("\n");
      i++;
    }
    printf("\n");
    closedir(d);
  }
  for (a = 0; a < 8; a++){
     printf("%s", filenames[a]);
     printf("\n");
  }
  return(0);
}