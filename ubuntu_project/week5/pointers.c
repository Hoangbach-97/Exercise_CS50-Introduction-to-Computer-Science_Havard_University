#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int i=50;

    int *p = &i;
    printf("%p\n", p);
     printf("%p\n", &i);
     printf("%d\n", *p);

}