#include<cs50.h>
#include<stdio.h>

 int get_negative_number(void);
 int main(void){

     int i = get_negative_number();
     printf("%i", i);
 }

 int get_negative_number(void){
     int n;
      do {
          n = get_int("Input negative number:");

      }
      while(n<0);
      return n;
 }