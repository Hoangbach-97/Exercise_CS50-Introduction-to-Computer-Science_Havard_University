#include<stdio.h>
#include<cs50.h>

void draw(int height);

int main(void)
{
    int height = get_int("Inpput height: ");
    draw(height);


}

void draw(int height)
{

        if(height==0)
        {
            return;
        }
        draw(height-1);
        for(int j = 0; j<height; j++)
        {
            printf("#");
        }
        printf("\n");

}