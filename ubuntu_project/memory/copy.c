#include<stdio.h>
#include<string.h>
#include<cs50.h>
#include<ctype.h>

int main(void)
{
    char *s = get_string("Input:");
    char *t = s;
    t[0] = toupper(t[0]);
    printf("t: %s\n", t);
     printf("s: %s\n", s);
}