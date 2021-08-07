#include <stdio.h>

int main(int argc, char **argv){
  
  float fahr;
  scanf("%f", &fahr);

  printf("%f\n",((5.0/9.0)*(fahr-32)));

  return 0;
}