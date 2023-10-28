#include <stdio.h>
#include <getopt.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char dateiname[255];
    char numbers[1000] = {};
    float* floaty = malloc(sizeof(float ));
    int anzZeilen = 0;
    FILE *file;
    if (argv[1] == NULL) {
        printf("Bitte geben sie einen Dateinamen ein\n");
        scanf("%s", dateiname);
    }

    file = fopen(dateiname, "r");
    while (fgets(numbers, 10 , file) != NULL) {
        float temp;
        sscanf(numbers, "%f\n", &temp);
        floaty = (float*) realloc(floaty, (anzZeilen+1)*sizeof(float));
        floaty[anzZeilen] = temp;
        anzZeilen++;

    }

    float max = 0;

    for (int i = 0; i < anzZeilen; i++) {
        if (floaty[i] > max ) {
            max = floaty[i];
        }
    }

    printf("%f", max);



    free(floaty);
    fclose(file);

    return  0;
}
