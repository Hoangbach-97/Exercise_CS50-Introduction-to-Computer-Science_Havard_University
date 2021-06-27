#include<stdio.h>

int main(void)
{
    int x= 1;
    int y=2;

    int s;
    s =x;
    x = y;
    y = s;
    printf("x: %i, y: %i", x,y);
}