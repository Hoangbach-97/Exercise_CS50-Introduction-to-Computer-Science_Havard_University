// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    // Array
    uint8_t header[HEADER_SIZE];
    // size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
    // header: read into header
    fread(header, HEADER_SIZE, 1, input);
    // header:  write into header
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer;
    while(fread(&buffer, 2, 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, 2, 1, output);
    }



    // Close files
    fclose(input);
    fclose(output);
}
