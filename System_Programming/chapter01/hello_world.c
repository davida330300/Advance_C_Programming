#include <stdio.h>
#include <unistd.h>
#define NNN 5
int main(void)
{
    for (int i = 0; i < NNN; i++) {
        fork();
        printf("-");                         
    }

    fflush(stdout);
    return 0;
}