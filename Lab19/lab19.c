#include <stdio.h>

void generate(char *string_ordenada, int *letra_usada, char *word, int n, int k){
    if(k==n){
        word[n]='\0';
        printf("%s\n", word);
        return;
    }

    for (int i = 0; i < n; ++i) {
        if(!letra_usada[i]) {
            word[k] = string_ordenada[i];
            ++letra_usada[i];
            generate(string_ordenada, letra_usada, word, n, k+1);
            --letra_usada[i];
            while (string_ordenada[i]==string_ordenada[i-1]){
                ++i;
            }
        }
    }
}