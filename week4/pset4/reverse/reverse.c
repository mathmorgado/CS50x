#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: INPUT.wav OUTPUT.wav\n");
        return 1;
    }

    // Open input file for reading
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Could not open %s\n", argv[1]);
        return 1;
    }

    // Read header
    WAVHEADER wh;
    fread(&wh, sizeof(WAVHEADER), 1, inptr);

    // Use check_format to ensure WAV format
    if (!check_format(wh))
    {
        printf("Unsupported file format\n");
        fclose(inptr);
        return 2;
    }

    // Open output file for writing
    FILE *reversed = fopen(argv[2], "w");
    if (reversed == NULL)
    {
        printf("Could not create %s\n", argv[1]);
        fclose(inptr);
        return 3;
    }

    // Write header to file
    fwrite(&wh, sizeof(WAVHEADER), 1, reversed);

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(wh);

    // Write reversed audio to file
    int buffer[block_size];

    fseek(inptr, block_size, SEEK_END);
    while (ftell(inptr) - block_size > sizeof(wh))
    {
        fseek(inptr, -2 * block_size, SEEK_CUR);

        fread(buffer, block_size, 1, inptr);
        fwrite(buffer, block_size, 1, reversed);
    }

    fclose(inptr);
    fclose(reversed);
    return 0;
}

int check_format(WAVHEADER header)
{
    char *wav_format = "WAVE";
    bool valid = false;
    for (int i = 0; i < 4; i++)
    {
        if (header.format[i] == wav_format[i])
        {
            valid = true;
        }
        else
        {
            valid = false;
            break;
        }
    }
    return valid;
}

int get_block_size(WAVHEADER header)
{
    int size = (header.numChannels * (header.bitsPerSample / 8));
    return size;
}