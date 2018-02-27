#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int red;
    int green;
    int blue;
} RGB;

int main(int argc, char **argv) {
    FILE *input_archive, *output_archive;

    int lines, columns, Imax;

    RGB **inputRGB, **outputRGB;
    RGB max, min;

    max.red = 0;
    max.green = 0;
    max.blue = 0;

    min.red = 255;
    min.green = 255;
    min.blue = 255;

    char discard;

    if (argc != 3) {
        fprintf(stderr, "Argumentos invalidos. Use:\n");
        fprintf(stderr, "./lab18 <arqEntrada> <arqSaida>\n");
        fprintf(stderr, "Usado:");
        for (int i=0; i<argc; i++) {
            fprintf(stderr, " %s", argv[i]);
        }
        fprintf(stderr, "\n");
        return 1;
    }

    char efeito[20];
    char *arqEntrada = argv[1];
    char *arqSaida = argv[2];

    scanf("%s", efeito);

    input_archive = fopen (arqEntrada, "r");
    output_archive = fopen (arqSaida, "w");

    fscanf(input_archive, "%c", &discard); // pra ler o P
    fprintf(output_archive, "%c", discard); // pra printar o p

    fscanf(input_archive, "%c\n", &discard); // pra ler o 3\n
    fprintf(output_archive, "%c\n", discard); // pra printar o 3 e ir pra linha abaixo

    fscanf(input_archive, "%d", &columns); // pra ler o numero de colunas
    fprintf(output_archive, "%d ", columns); // pra printar o numero de colunas e dar um espaço

    fscanf(input_archive, "%d\n", &lines); // pra ler o numero de linhas e o newline
    fprintf(output_archive, "%d\n", lines); // pra printar o numero de linhas e dar newline

    fscanf(input_archive, "%d\n", &Imax);  // pra ler o 255 com \n
    fprintf(output_archive, "%d\n", Imax); // e printar o 255 com \n


    inputRGB = malloc(lines*sizeof(RGB*));
    outputRGB = malloc(lines*sizeof(RGB*));

    for (int j = 0; j < lines ; ++j) {
        inputRGB[j] = malloc(columns*sizeof(RGB));
        outputRGB[j] = malloc(columns*sizeof(RGB));
    }

    for (int k = 0; k < (lines*columns); ++k) {
        int x = ceil(k/columns);
        int y = k%columns;
        fscanf(input_archive, "%d", &inputRGB[x][y].red);
        fscanf(input_archive, "%d", &inputRGB[x][y].green);
        fscanf(input_archive, "%d", &inputRGB[x][y].blue);
        if (inputRGB[x][y].red > max.red) {
        	max.red = inputRGB[x][y].red;
        }
        if (inputRGB[x][y].green > max.green) {
        	max.green = inputRGB[x][y].green;
        }
        if (inputRGB[x][y].blue > max.blue) {
        	max.blue = inputRGB[x][y].blue;
        }
        if (inputRGB[x][y].red < min.red) {
        	min.red = inputRGB[x][y].red;
        }
        if (inputRGB[x][y].green < min.green) {
        	min.green = inputRGB[x][y].green;
        }
        if (inputRGB[x][y].blue < min.blue) {
        	min.blue = inputRGB[x][y].blue;
        }
    }

    if (efeito[0] == 'c') {
        for (int i = 0; i < (columns*lines); ++i) {
            int x = ceil(i/columns);
            int y = i%columns;
            outputRGB[x][y].red = floor((inputRGB[x][y].red + inputRGB[x][y].green + inputRGB[x][y].blue)/3);
            outputRGB[x][y].green = outputRGB[x][y].red;
            outputRGB[x][y].blue = outputRGB[x][y].red;
        }
    }

    else if (efeito[0] == 'e') {
        for (int i = 0; i < (columns*lines); ++i) {
            int x = ceil(i/columns);
            int y = i%columns;
            outputRGB[x][y].red = floor(((inputRGB[x][y].red - min.red) * 255)/(max.red - min.red));
            outputRGB[x][y].green = floor(((inputRGB[x][y].green - min.green) * 255)/(max.green - min.green));
            outputRGB[x][y].blue = floor(((inputRGB[x][y].blue - min.blue) * 255)/(max.blue - min.blue));
        }
    }

    else if (efeito[0] == 'n') {
        for (int i = 0; i < (columns*lines); ++i) {
            int x = ceil(i/columns);
            int y = i%columns;
            int sum = inputRGB[x][y].red + inputRGB[x][y].green + inputRGB[x][y].blue;
            if (sum) {
                outputRGB[x][y].red = floor(inputRGB[x][y].red * 255 / sum);
                outputRGB[x][y].green = floor(inputRGB[x][y].green * 255 / sum);
                outputRGB[x][y].blue = floor(inputRGB[x][y].blue * 255 / sum);
            }
            else {
                outputRGB[x][y].red = 0;
                outputRGB[x][y].green = 0;
                outputRGB[x][y].blue = 0;
            }

        }
    }


    for (int l = 0; l < lines; ++l) {
        for (int c = 0; c < columns-1; ++c) {
            fprintf(output_archive, "%d %d %d ", outputRGB[l][c].red, outputRGB[l][c].green, outputRGB[l][c].blue);
            if (c == columns-2) {
                fprintf(output_archive, "%d %d %d\n", outputRGB[l][columns-1].red, outputRGB[l][columns-1].green, outputRGB[l][columns-1].blue);
            }
        }
    }
}
