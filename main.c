#include <stdio.h>
#include <getopt.h>
#include <math.h>
#include <float.h>

double convertTemp(char from, char to, float value) {
    double convertedTemp;
    switch (from) {
        case 'C':
            convertedTemp = value;
            break;
        case 'D':
            convertedTemp = 100 - value * ((double) 2/3);
            break;
        case 'F':
            convertedTemp =value - 32 * ((double ) 5/9);
            break;
        case 'K':
            convertedTemp = value - 273.15;
            break;
        case 'R':
            convertedTemp = value * ((double ) 5/9) - 273.15;
            break;
        default:
            convertedTemp = NAN;
    }

    switch (to) {
        case 'C':
            convertedTemp = convertedTemp;
            break;
        case 'D':
            convertedTemp = 100-convertedTemp * 1.5;
            break;
        case 'F':
            convertedTemp = convertedTemp * 1.8 + 32;
            break;
        case 'K':
            convertedTemp =convertedTemp +  273.15;
            break;
        case 'R':
            convertedTemp = convertedTemp * 1.8 + 491.67;
            break;
        default:
            convertedTemp = NAN;

    }
    return convertedTemp;
}

int main(int argc, char *argv[]) {
    char *from, *to;
    from = NULL;
    to = NULL;
    float value = FLT_MAX;

    // Kommandozeilenparameter einlesen
    int ret;
    while ((ret = getopt(argc, argv, "f:t:v:")) != -1) {
        switch (ret) {
            case 'f':
                from = optarg;
                break;
            case 't':
                to = optarg;
                break;
            case 'v':
                value = atof(optarg);
                break;
            default:
                break;
        }
    }

    if (from != NULL && to != NULL && value < FLT_MAX) {
        double convertedTemp = convertTemp(*from, *to, value);
        if (convertedTemp < FLT_MAX) {
            printf("%f in %c entsprechen %f in %c", value, *from, convertedTemp, *to);
        } else {
            printf("Fehler bei der Konvertierung von %c zu %c", *from, *to);
            //Todo warum -2 returnen
            return -2;
        }
    } else {
        printf("Entweder Quell- oder Zieleinheit wurden nicht angegeben");
        return -1;
    }
    return 0;
}
