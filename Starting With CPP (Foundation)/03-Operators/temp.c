#include <stdio.h>
int main()
{
    int a = 10;
    int b = 20;
    printf("\033[2J\033[H");
    printf(" %d ", a++);
    // printf(" %d & %d", a++, a++);
    return 0;
}