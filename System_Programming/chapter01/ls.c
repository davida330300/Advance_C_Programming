#include "apue.h"
#include <dirent.h>
/* include "apue.h" in every program of apue
   include "dirent.h" to use opendir & readdir function
   argv[1] == first parameter in cmd

*/
int main (int argc, char* argv[])
{
   DIR            *dp;
   struct dirent  *dirp;

   if (argc != 2)
      err_quit("usage: ls directory_name");

   /* return the prt point to DIR*/
   if ((dp = opendir(argv[1])) == NULL)
      err_sys("can't open %s", argv[1]);
   /* pass the prt to readdir(), recursivly call the property of directory_name*/
   while ((dirp = readdir(dp)) != NULL)
      printf("%s\n", dirp->d_name);

   /* close directory & exit*/
   closedir(dp);
   exit(0);
   
}