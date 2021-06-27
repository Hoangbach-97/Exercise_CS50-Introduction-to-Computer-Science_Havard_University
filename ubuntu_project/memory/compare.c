#include<stdio.h>
#include<cs50.h>
#include<string.h>
int main(void)
{
char *s = get_string("Input:");
char *t = get_string("Input:");
// if(*s == *t)
if(strcmp(s,t)==0)
{
    printf("Same \n");
}
else
{
    printf("Different\n");
}
printf("%p\n", &s);
printf("%p\n", &t);
printf("%p\n", s);
printf("%p", t);
}