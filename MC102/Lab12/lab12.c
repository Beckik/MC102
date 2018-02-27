#include <stdio.h>
#include <string.h>

char text[1001], word[16];
char* array;
int length, txt_size, last_txt_size;

char* loko = &text[0];

int finder () {
    array = NULL;
    for (int i = txt_size-1; i>=0; --i) {
        if (word[0]==text[i]||(int)word[0]==(int)text[i]+32){
            int j = 0;
            for (; j < length; ++j) {
                if (word[j]!=text[i+j] && (int)word[j]!=(int)text[i+j]+32) {
                    break;
                }
            }
            if (j==length && (text[i-1] == ' ' || i == 0) && (text[i+length] == ' ' || text[i+length] == '\0' )) {
                array = &text[i];
                return 1;
            }
        }
    }
    return 0;
}

void standardizer(){
    last_txt_size = txt_size;
    txt_size = strlen(text);
    int diff = last_txt_size - txt_size;
    for (int i = 0; i < diff-1; ++i) {
        text[txt_size+1+i] = '\0';
    }
}

int main () {
    int new_length;
    char command;

    scanf("%[^\n]", text);
    printf("%s\n", text);
    getchar();
    txt_size = strlen(text);


    for (int k = 0; txt_size+1+k < 1002; ++k) {
        text[txt_size+1+k] = '\0';
    }

    while (scanf("%c", &command) && command != 'Q' && getchar()) {
        scanf("%[^\n]", word);
        getchar();
        length = strlen(word);

        for (int j = 0; j < length; ++j) {
            if ((int)word[j] >= 65 && (int)word[j] <= 90){
                word[j]+=32;
            }
        }

        if(command=='D'){
            while (finder() && array!= NULL){
                if (array[length] != '\0'){
                    for (int i = 0; array[i+length-1]!='\0'; ++i) {
                        array[i]=array[i+length+1];
                    }
                }
                else {
                    for (int i = 0; i <= length; ++i) {
                        array[i-1] ='\0';
                    }
                }
            }
            standardizer();
        }
        else if (command=='I'){
            char invert[length];
            while (finder() && array!= NULL){
                for (int i = 0; i < length; ++i) {
                    invert[length-1-i] = array[i];
                }
                for (int i = 0; i < length; ++i) {
                    array[i] = invert[i];
                }
            }
        }
        else if (command=='R'){
            char replace[16];
            scanf("%[^\n]", replace);
            getchar();
            new_length = strlen(replace);
            if (length > new_length) {
                while (finder() && array!= NULL){
                    for (int i = 0; i < new_length; ++i) {
                        array[i] = replace[i];
                    }
                    for (int j = 0; array[length+j-1] != '\0'; ++j) {
                        array[new_length+j] = array[length+j];
                    }
                }
                standardizer();
            }
            else if (length < new_length) {
                while (finder() && array!= NULL){
                    for (int i = 0; &(array[length-1]) != &(text[txt_size-i]) ; ++i) {
                        text[txt_size+new_length-length-i] = text[txt_size-i];
                    }
                    for (int j = 0; j < new_length; ++j) {
                        array[j] = replace[j];
                    }
                    standardizer();
                }

            }
            else if (new_length==length){
                while (finder() && array!= NULL){
                    for (int i = 0; i < length; ++i) {
                        array[i] = replace[i];
                    }
                }
            }
        }
        printf("%s\n", text);
    }
    return 0;
}