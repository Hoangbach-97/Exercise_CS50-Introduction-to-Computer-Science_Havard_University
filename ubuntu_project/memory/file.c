#include<stdio.h>
#include<cs50.h>

int main(void)
{
    FILE *filePhone = fopen("phonebook.csv", "a");
    if(filePhone == NULL)
    {
        return 1;
    }
    char *name = get_string("Input name: ");
    char *number = get_string("Input number: ");

    fprintf(filePhone, "%s, %s\n", name, number);
    fclose(filePhone);
}
