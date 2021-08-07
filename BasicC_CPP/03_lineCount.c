#include <stdio.h>

int main(int argc, char *argv[]){

  int c, line;
  while((c=getchar())!= EOF){
    if(c=='\n'){
      line++;
    }
    printf("%d\n",line);
  }
  return 0;
}