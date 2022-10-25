#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <locale.h>

#define MAXSIZE 256


int get_file_size(FILE *fp)
{
    fseek(fp, SEEK_SET, SEEK_END); //setting point to the EOF
    int bsize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);  //setting point to the SOF
    return bsize;
}

void get_codes(FILE* note, uint8_t keys[256], uint8_t* size)
{   
    uint8_t tmp_sum = 0;
    char ch;
    while ((ch = fgetc(note)) != EOF)
    {
        if (ch != ' ')
        {
            tmp_sum += ch;
            keys[*size] = tmp_sum;
            
        }
        else {
            (*size)++;
            tmp_sum = 0;
        }
    }
    (*size)++;
}

void encode(FILE* input, FILE* output, uint8_t sizefile, uint8_t keys[MAXSIZE], uint8_t size_note)
{
    uint8_t ch, coded_char, counter = 0;

    for (int i = 0; i < sizefile; i++)
    {   
        ch = getc(input);
        if (ch != ' ')
        {
            coded_char = ch ^ keys[counter++ % size_note];
            fputc(coded_char, output);
        } else {
            coded_char = ' ';
            fputc(coded_char, output);
        }
    }
}

void decode(FILE* input, FILE* output, uint8_t sizefile, uint8_t keys[MAXSIZE], uint8_t size_note)
{
    uint8_t ch, decoded_char, counter = 0;
    for (int i = 0; i < sizefile; i++)
    {
        ch = getc(input);
        if (ch != ' ')
        {
            decoded_char = ch ^ keys[counter++ % size_note];
            fputc(decoded_char, output);
        } else {
            decoded_char = ' ';
            fputc(decoded_char, output);
        }
    }
}

int main(int argc, char** argv)
{
    FILE* codenote = fopen("codenote.txt", "r");
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w+");
    FILE* decoded = fopen("decoded.txt", "w+");

    int stat[256];
    uint8_t keys[256];
    uint8_t size = 0, counter = 0;

    if (input == NULL || codenote == NULL || output == NULL || decoded == NULL) 
    {
        perror("qe");
        exit(1);
    }

    get_codes(codenote, keys, &size);

    encode(input, output, get_file_size(input), keys, size);

    decode(output, decoded, get_file_size(output), keys, size);

    fclose(input); fclose(output); fclose(codenote); fclose(decoded);

    return 0;
}