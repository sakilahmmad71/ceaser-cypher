#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "encrypt.c"
#include "decrypt.c"

int encrypt(char message[], int key);
int decrypt(char message[], int key);

int main()
{
    char sentence[1000];
    FILE *input, *output, *decrypt_output;
    int key = 4;

    // Reading text from "input.txt"
    if ((input = fopen("input.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }
    fscanf(input, "%[^\n]", sentence);
    fclose(input);

    // Encrypt input.text files words/sentences via calling encrypt function.
    encrypt(sentence, key);

    // Writing encrypted message into "enc_msg.txt"
    output = fopen("enc_msg.txt", "w");
    if (output == NULL)
    {
        printf("Error!");
        exit(1);
    }

    fprintf(output, "%s", sentence);
    fclose(output);

    // Decrypt enc_msg.text files words/sentences via calling decrypt function.
    decrypt(sentence, key);

    // writing decrypted output into "dec_msg.txt"
    decrypt_output = fopen("dec_msg.txt", "w");
    if (decrypt_output == NULL)
    {
        printf("Error!");
        exit(1);
    }

    fprintf(decrypt_output, "%s", sentence);
    fclose(decrypt_output);
}