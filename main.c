/* md_array1.c */
#include <stdio.h>
#include <stdlib.h>

void readFile(FILE *stream) {
    int c;

    while ( (c = fgetc(stream)) != EOF) {
        putchar(c);
    }
}

int main(void) {
    FILE *datei;
    char filename[255];
    printf("Enter a valid filename: ");
    scanf("%s", filename);


    datei = fopen(filename, "r");

    if (datei != NULL) {
        readFile(datei);
       } else {
        printf("No file found");
    }
}



