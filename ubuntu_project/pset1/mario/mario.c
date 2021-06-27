#include<stdio.h>
#include<cs50.h>

int get_height(void);
int main(void)
{
    printf("Welcome to my pyramid\n");

    int n = get_height();
     for(int i = 0; i< n; i++)
          {
            for(int j=0; j<n; j++)
            {
                if(i+j<n-1)
                 printf(".");
                 else
                 printf("#");



            }

            printf("\n");
          }
}
    int get_height(void)
{    int  inputHeight;
      do
     {
           inputHeight = get_int("Enter pyramid: ");

      }
      while (inputHeight < 1 || inputHeight > 9);
      return inputHeight;
}








