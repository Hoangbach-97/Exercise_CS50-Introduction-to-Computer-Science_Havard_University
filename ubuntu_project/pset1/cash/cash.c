#include<stdio.h>
#include<cs50.h>
#include<math.h>

int get_greedy(void);
int main(void)
{

      get_greedy();
    // printf("%.5f", n);

}

int get_greedy(void)
{
    float greedy;
    do
    {
        greedy = get_float("Change owne: ");
    }
    while(greedy <1);
    printf("%f", greedy);
    return greedy;

}