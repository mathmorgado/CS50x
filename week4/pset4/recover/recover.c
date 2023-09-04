#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: file to recover\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("could not open %s\n", argv[1]);
        return 1;
    }

    int count = 0;
    BYTE block[512];

    char filename[8];
    FILE *image = NULL;


    while (fread(block, 512, 1, raw_file) == 1)
    {
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            if (count > 0)
            {
                fclose(image);
            }
            sprintf(filename, "%03i.jpg", count);
            image = fopen(filename, "w");
            if (image == NULL)
            {
                fclose(raw_file);
                printf("Could not creat %s\n", filename);
                return 3;
            }
            count++;
        }
        if (count > 0)
        {
            fwrite(block, 512, 1, image);
        }
    }
    fclose(raw_file);
    if (count > 0)
    {
        fclose(image);
    }
    return 0;
}