#include <stdio.h>
#include <stdlib.h>
#include<cs50.h>
#include<stdint.h>

typedef uint8_t BYTE;

#define BLOCK_SIZE 512
#define FILE_NAME_SIZE 8

bool is_start_new_jpeg(BYTE buffer[]);


int main(int argc, char *argv[])
{

 if(argc !=2 )
 {
     printf("Usage: ./recover image\n");
     return 1;
 }
 FILE *file = fopen(argv[1], "r");
 if(file == NULL)
 {
     printf("File is empty!");
     return 1;
 }
 BYTE buffer[BLOCK_SIZE];
 int file_index = 0;
 FILE *ofile;

 bool found_first_jpeg = false;
 while(fread(buffer, BLOCK_SIZE, 1, file))
 {
     if(is_start_new_jpeg(buffer))
    {
         if(!found_first_jpeg)

             found_first_jpeg =true;

         else
         fclose(file);

         char fileName[FILE_NAME_SIZE];
         sprintf(fileName, "%03i.jpg", file_index++);
         ofile = fopen(fileName, "w");
         if(ofile == NULL)

             return 1;


         fwrite(buffer, BLOCK_SIZE, 1, ofile);
    }
    else if(found_first_jpeg)
    {
        // keep on writing the previous file
        fwrite(buffer, BLOCK_SIZE, 1, ofile);
    }



 }

 fclose(ofile);
 fclose(file);

}

bool is_start_new_jpeg(BYTE buffer[])
{
    return buffer[0] ==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]&0xf0)==0xe0;

}